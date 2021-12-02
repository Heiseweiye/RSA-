#include "RSA_DE.h"
#include <QtWidgets/QMessageBox>
#include "GBK.h"
#include <QFileDialog>


RSA_DE::RSA_DE(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);  
	rsa = new RSA;   //��ʼ��
	connect(ui.Btn_GenKey_slt, SIGNAL(clicked()), this, SLOT(OnbtnGen()));     //�л�������Կҳ��
	connect(ui.Btn_ED_slt, SIGNAL(clicked()), this, SLOT(OnbtnEn()));          //�л��ӽ���ҳ��
	connect(ui.Btn_Open_File, SIGNAL(clicked()), this, SLOT(OnbtnOpen()));     //�ļ���
	connect(ui.Btn_Save_file, SIGNAL(clicked()), this, SLOT(OnbtnSave()));     //�ļ�����
	connect(ui.Btn_Gen, SIGNAL(clicked()), this, SLOT(GennarateKey()));        //��Կ����
	connect(ui.Btn_StartED, SIGNAL(clicked()), this, SLOT(Sel_DE()));          //�ӽ���ѡ��
}

//������Կҳ��
int RSA_DE::OnbtnGen()
{
	ui.stackedWidget->setCurrentIndex(1);
	return 0;
}

//�ӽ���ҳ��
int RSA_DE::OnbtnEn()
{
	ui.stackedWidget->setCurrentIndex(0);
	return 0;
}

//���ļ�
int RSA_DE::OnbtnOpen()
{
	// ѡ��Ҫ�򿪵��ļ�
	QString filepath = QFileDialog::getOpenFileName(
		this, // ������
		GBK::ToUnicode("ѡ���ļ�") // ����caption
		);

	// Ϊ��ʱ��ʾ�û�ȡ���˲���,û��ѡ���κ��ļ�
	if (filepath.length() > 0)
	{
		string gbk_name = GBK::FromUnicode(filepath);
		if (gbk_name.length() == 0)
		{
			QMessageBox::warning(this, "error",
				"GBK not supported, See 'Change Jian Wen Ti Hui Zong'");
			return -1;
		}

		// ���ļ�����ȡ����
		FILE* fp = fopen(gbk_name.c_str(), "rb");

		// �ļ��Ĵ�С
		fseek(fp, 0, SEEK_END);
		int filesize = ftell(fp);

		// ��ȡ����
		fseek(fp, 0, SEEK_SET);
		char* buf = new char[filesize + 1];
		int n = fread(buf, 1, filesize, fp);
		if (n > 0)
		{
			buf[n] = 0;
			// ��ʾ���ı�����
			ui.plain_PlainText->setPlainText(GBK::ToUnicode(buf));
		}
		delete[] buf; // �ͷ��ڴ�
		fclose(fp);  // �ر��ļ�
	}
	return 0;
}

//�����ļ�
int RSA_DE::OnbtnSave()
{
	// ѡ��Ҫ�򿪵��ļ�
	QString filepath = QFileDialog::getSaveFileName(
		this, // ������
		GBK::ToUnicode("����") // ����caption
		);

	// Ϊ��ʱ��ʾ�û�ȡ���˲���,û��ѡ���κ��ļ�
	if (filepath.length() > 0)
	{
		QString text = ui.plain_Ciper->toPlainText();
		string gbk_text = GBK::FromUnicode(text);
		string gbk_filename = GBK::FromUnicode(filepath);

		// ���ļ� (��17�£�
		FILE* fp = fopen(gbk_filename.c_str(), "wb");
		fwrite(gbk_text.c_str(), 1, gbk_text.length(), fp);
		fclose(fp);  // �ر��ļ�
	}
	return 0;
}

//������Կ��
void RSA_DE::GennarateKey()
{
	if (ui.Line_KeySize->text().isEmpty())
	{
		QMessageBox::warning(NULL, "warning", "����������Կλ��", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	int nbits = ui.Line_KeySize->text().toInt();
	int ebits = 32;  //65537

	if (nbits > 2048)
	{
		QMessageBox::warning(NULL, "warning", "��Կλ�����󣬲�Ҫ����2048!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
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

//����
void RSA_DE::Encode()
{
	if (ui.plain_PlainText->toPlainText().isEmpty())
	{
		QMessageBox::warning(NULL, "warning", "������������!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	if (ui.plain_Pub_E->toPlainText().isEmpty())
	{
		QMessageBox::warning(NULL, "warning", "����������Կ!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}

	rsa->setKey(RSA::PublicKey, pub_e, pub_n);  //��Կ���м���

	//��������ַ���תΪ16�����ַ���
	QString text = ui.plain_PlainText->toPlainText();
	QByteArray hex;
	QString strhex = hex.append(text).toHex();
	string enc = rsa->Encrypt(strhex.toStdString(), 16);
	ui.plain_Ciper->setPlainText(QString::fromStdString(enc));
}

//����
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

	rsa->setKey(RSA::PrivateKey, pri_d, pri_n);  //˽Կ���н���

	string text = ui.plain_PlainText->toPlainText().toStdString();
	string enc = rsa->Decrypt(text, 16);
	//��16�����ַ���תΪ�ַ���
	QString strhex = QString::fromStdString(enc);
	QByteArray hex;
	hex.append(strhex);
	QByteArray str = QByteArray::fromHex(hex);
	ui.plain_Ciper->setPlainText(str);
}

//ѡ����ܻ��߽���
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