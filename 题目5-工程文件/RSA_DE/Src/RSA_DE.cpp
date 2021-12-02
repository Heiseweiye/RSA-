#include "RSA_DE.h"
#include <QtWidgets/QMessageBox>
#include "GBK.h"
#include <QFileDialog>


RSA_DE::RSA_DE(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);  
	rsa = new RSA;   //初始化
	connect(ui.Btn_GenKey_slt, SIGNAL(clicked()), this, SLOT(OnbtnGen()));     //切换生成密钥页面
	connect(ui.Btn_ED_slt, SIGNAL(clicked()), this, SLOT(OnbtnEn()));          //切换加解密页面
	connect(ui.Btn_Open_File, SIGNAL(clicked()), this, SLOT(OnbtnOpen()));     //文件打开
	connect(ui.Btn_Save_file, SIGNAL(clicked()), this, SLOT(OnbtnSave()));     //文件保存
	connect(ui.Btn_Gen, SIGNAL(clicked()), this, SLOT(GennarateKey()));        //密钥生成
	connect(ui.Btn_StartED, SIGNAL(clicked()), this, SLOT(Sel_DE()));          //加解密选择
}

//生成密钥页面
int RSA_DE::OnbtnGen()
{
	ui.stackedWidget->setCurrentIndex(1);
	return 0;
}

//加解密页面
int RSA_DE::OnbtnEn()
{
	ui.stackedWidget->setCurrentIndex(0);
	return 0;
}

//打开文件
int RSA_DE::OnbtnOpen()
{
	// 选择要打开的文件
	QString filepath = QFileDialog::getOpenFileName(
		this, // 父窗口
		GBK::ToUnicode("选择文件") // 标题caption
		);

	// 为空时表示用户取消了操作,没有选中任何文件
	if (filepath.length() > 0)
	{
		string gbk_name = GBK::FromUnicode(filepath);
		if (gbk_name.length() == 0)
		{
			QMessageBox::warning(this, "error",
				"GBK not supported, See 'Change Jian Wen Ti Hui Zong'");
			return -1;
		}

		// 打开文件，读取内容
		FILE* fp = fopen(gbk_name.c_str(), "rb");

		// 文件的大小
		fseek(fp, 0, SEEK_END);
		int filesize = ftell(fp);

		// 读取内容
		fseek(fp, 0, SEEK_SET);
		char* buf = new char[filesize + 1];
		int n = fread(buf, 1, filesize, fp);
		if (n > 0)
		{
			buf[n] = 0;
			// 显示到文本框中
			ui.plain_PlainText->setPlainText(GBK::ToUnicode(buf));
		}
		delete[] buf; // 释放内存
		fclose(fp);  // 关闭文件
	}
	return 0;
}

//保存文件
int RSA_DE::OnbtnSave()
{
	// 选择要打开的文件
	QString filepath = QFileDialog::getSaveFileName(
		this, // 父窗口
		GBK::ToUnicode("保存") // 标题caption
		);

	// 为空时表示用户取消了操作,没有选中任何文件
	if (filepath.length() > 0)
	{
		QString text = ui.plain_Ciper->toPlainText();
		string gbk_text = GBK::FromUnicode(text);
		string gbk_filename = GBK::FromUnicode(filepath);

		// 打开文件 (第17章）
		FILE* fp = fopen(gbk_filename.c_str(), "wb");
		fwrite(gbk_text.c_str(), 1, gbk_text.length(), fp);
		fclose(fp);  // 关闭文件
	}
	return 0;
}

//生成密钥对
void RSA_DE::GennarateKey()
{
	if (ui.Line_KeySize->text().isEmpty())
	{
		QMessageBox::warning(NULL, "warning", "请先输入密钥位数", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	int nbits = ui.Line_KeySize->text().toInt();
	int ebits = 32;  //65537

	if (nbits > 2048)
	{
		QMessageBox::warning(NULL, "warning", "密钥位数过大，不要超过2048!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	pub_e.clear();
	pub_n.clear();
	pri_d.clear();
	pri_n.clear();

	ui.plain_Pub_E->clear();
	ui.plain_Pub_N->clear();
	ui.plain_Pri_D->clear();

	rsa->generateKey(nbits, ebits);
	rsa->getKey(RSA::PublicKey, pub_e, pub_n);
	rsa->getKey(RSA::PrivateKey, pri_d, pri_n);
	ui.plain_Pub_E->setPlainText(QString::fromStdString(pub_e));
	ui.plain_Pub_N->setPlainText(QString::fromStdString(pub_n));
	ui.plain_Pri_D->setPlainText(QString::fromStdString(pri_d));
}

//加密
void RSA_DE::Encode()
{
	if (ui.plain_PlainText->toPlainText().isEmpty())
	{
		QMessageBox::warning(NULL, "warning", "请先输入内容!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	if (ui.plain_Pub_E->toPlainText().isEmpty())
	{
		QMessageBox::warning(NULL, "warning", "请先生成密钥!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}

	rsa->setKey(RSA::PublicKey, pub_e, pub_n);  //公钥进行加密

	//将输入的字符串转为16进制字符串
	QString text = ui.plain_PlainText->toPlainText();
	QByteArray hex;
	QString strhex = hex.append(text).toHex();
	string enc = rsa->Encrypt(strhex.toStdString(), 16);
	ui.plain_Ciper->setPlainText(QString::fromStdString(enc));
}

//解密
void RSA_DE::Decode()
{
	if (ui.plain_PlainText->toPlainText().isEmpty())
	{
		QMessageBox::warning(NULL, "warning", "Please input something!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	if (ui.plain_Pub_E->toPlainText().isEmpty())
	{
		QMessageBox::warning(NULL, "warning", "Please generate the key!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}

	rsa->setKey(RSA::PrivateKey, pri_d, pri_n);  //私钥进行解密

	string text = ui.plain_PlainText->toPlainText().toStdString();
	string enc = rsa->Decrypt(text, 16);
	//将16进制字符串转为字符串
	QString strhex = QString::fromStdString(enc);
	QByteArray hex;
	hex.append(strhex);
	QByteArray str = QByteArray::fromHex(hex);
	ui.plain_Ciper->setPlainText(str);
}

//选择解密或者解密
void RSA_DE::Sel_DE()
{
	int index = ui.com_Select->currentIndex();
	//QString text = ui.com_Select->itemText(index);
	//string sel = text.toStdString();
	if (index == 0)
	{
		Encode();
		return;
	}
	else
	{
		Decode();
		return;
	}
}