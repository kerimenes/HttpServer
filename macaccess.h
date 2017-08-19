#ifndef MACACCESS_H
#define MACACCESS_H

#include "net/simplehttpserver.h"

class MacAccess: public SimpleHttpServer
{
	Q_OBJECT
public:
	MacAccess(int port, QObject *parent = 0);
protected:
	const QByteArray getFile(QString filename, QString &mime, QUrl &url);
	QString getMacAddress();
	int updateMacAddressState(const QString mac, int status);
};

class SqlAccess {
public:
	SqlAccess();
};
#endif // MACACCESS_H
