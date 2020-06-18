#include "RSA_DE.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RSA_DE w;
	w.setWindowTitle(QString("RSA¼Ó½âÃÜ Designed By ¾Å°à1×é"));
	w.show();
	return a.exec();
}
