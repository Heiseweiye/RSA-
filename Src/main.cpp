#include "RSA_DE.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RSA_DE w;
	w.setWindowTitle(QString("RSA�ӽ��� Designed By �Ű�1��"));
	w.show();
	return a.exec();
}
