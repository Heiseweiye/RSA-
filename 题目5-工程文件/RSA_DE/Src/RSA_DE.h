#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QtWidgets/QMainWindow>
#include "ui_RSA_DE.h"
#include <QDialog>
#include "rsa.h"




class RSA_DE : public QMainWindow
{
	Q_OBJECT

public:
	RSA_DE(QWidget *parent = Q_NULLPTR);

private slots:
	int OnbtnGen();         //生成密钥
	int OnbtnEn();          //加密
	int OnbtnOpen();        //打开文件
	int OnbtnSave();       //保存内容
	void GennarateKey();   //生成密钥
	void Encode();         //加密
	void Decode();         //解密
	void Sel_DE();         //选择加解密

private:
	Ui::RSA_DEClass ui;
	RSA *rsa;
	string pub_e, pub_n, pri_d, pri_n;
};
