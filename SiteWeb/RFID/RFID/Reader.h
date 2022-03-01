#pragma once

#include <QWebSocket>
#include <QObject>
#include <cstdint>
#include <cstring>
#include <QMap>
#include "uFCoder.h"
#include "Server.h"

class Server;

class Reader : public QObject
{
	Q_OBJECT

	public:
		Reader( QObject *parent = Q_NULLPTR );
		~Reader();

	private:

		UFR_STATUS status;
		uint32_t readerType = 0;
		uint8_t  cardType	= 0;
		uint32_t cardSerial = 0;

	public slots:
		void read();
		void write( QString newContent );

	signals:
		void hasRead( QMap< QString, QVariant > );

};
