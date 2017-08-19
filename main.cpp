#include <QCoreApplication>
#include <QDebug>
#include "macaccess.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	MacAccess *mac = new MacAccess(9569);
	return a.exec();
}
