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
	int OnbtnGen();         //������Կ
	int OnbtnEn();          //����
	int OnbtnOpen();        //���ļ�
	int OnbtnSave();       //��������
	void GennarateKey();   //������Կ
	void Encode();         //����
	void Decode();         //����
	void Sel_DE();         //ѡ��ӽ���

private:
	Ui::RSA_DEClass ui;
	RSA *rsa;
	string pub_e, pub_n, pri_d, pri_n;
};
