#include "macaccess.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

MacAccess::MacAccess(int port, QObject *parent)
	: SimpleHttpServer(port, parent)
{

}


const QByteArray MacAccess::getFile(QString filename, QString &mime, QUrl &url)
{
	qDebug() << server << "getfile";
	Q_UNUSED(mime);
	filename = filename.remove("/");
	if(filename == "get_asel_mac") {
		qDebug() << "Getting Aselsan MAC address";
		QString mac = getMacAddress();
		if (mac.contains("00:03:73")) {
//			int err = updateMacAddressState(mac, 1);
			server = NULL;
			return mac.toUtf8();
		}
		return "000000000000";
	} else if(filename == "get_bilkon_mac") {
		/***
		 * TODO
		 **/
	} else if(filename == "cam_test") {

	}
}

QString MacAccess::getMacAddress()
{
	SqlAccess sql;
	QSqlQuery q(QString("SELECT * FROM mac_address_list"));
	QString mac;
	if(q.next()) {
		mac = q.value("mac_address").toString();
	}
	return mac;
}

int MacAccess::updateMacAddressState(const QString mac, int status)
{
	SqlAccess sql;
	QSqlQuery q;
	q.prepare(QString("UPDATE mac_address_list SET status=%1 WHERE mac_address='%2'").arg(status).arg(mac));
	if (q.exec())
		return 0;
	return q.lastError().number();}


SqlAccess::SqlAccess()
{
	QString m_dbDriver("QPSQL");
	QString m_dbHostName("10.30.1.1");
	QString m_dbDatabaseName("BilkonErp");
	QString m_dbUserName("BilkonErpAdmin");
	QString m_dbPassword("Aibotah8");
	int m_dbPort(5432);

	QSqlDatabase db = QSqlDatabase::addDatabase(m_dbDriver);
	db.setHostName(m_dbHostName);
	db.setDatabaseName(m_dbDatabaseName);
	db.setUserName(m_dbUserName);
	db.setPassword(m_dbPassword);
	db.setPort(m_dbPort);

	qDebug() << "state database" << db.open();
}

