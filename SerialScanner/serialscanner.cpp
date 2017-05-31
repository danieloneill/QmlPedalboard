#include "serialscanner.h"

#include <QSerialPort>
#include <QDebug>
#include <QtMath>

void dumpPacket(const QByteArray &packet)
{
    QString result;
    for( int x=0; x < packet.length(); x++ )
    {
        QString byte;
        byte.sprintf("0x%x ", (quint8)packet.at(x));
        result.append( byte );
    }
    qDebug() << result;
}

SerialScanner::SerialScanner(QQuickItem *parent):
    QQuickItem(parent),
    m_baudRate(115200),
    m_dataBits(8),
    m_parity(NoParity),
    m_stopBits(1),
    m_open(false)
{
    m_device = new QSerialPort(this);

    connect( m_device, SIGNAL(readyRead()), this, SLOT(readPacket()) );
}

SerialScanner::~SerialScanner()
{
    if( m_device->isOpen() )
        m_device->close();

    m_device->deleteLater();
}


bool SerialScanner::getOpen()
{
    return m_device->isOpen();
}

QString SerialScanner::getDevicePath()
{
    return m_devicePath;
}

bool SerialScanner::intOpen()
{
    m_device->setPortName(m_devicePath);
    m_device->setBaudRate(m_baudRate);
    switch( m_dataBits )
    {
    case 5:
        m_device->setDataBits(QSerialPort::Data5);
        break;
    case 6:
        m_device->setDataBits(QSerialPort::Data6);
        break;
    case 7:
        m_device->setDataBits(QSerialPort::Data7);
        break;
    case 8:
        m_device->setDataBits(QSerialPort::Data8);
        break;
    }

    switch( m_parity )
    {
    case NoParity:
        m_device->setParity(QSerialPort::NoParity);
        break;
    case OddParity:
        m_device->setParity(QSerialPort::OddParity);
        break;
    case EvenParity:
        m_device->setParity(QSerialPort::EvenParity);
        break;
    }

    switch( m_stopBits )
    {
    case 1:
        m_device->setStopBits(QSerialPort::OneStop);
        break;
    case 2:
        m_device->setStopBits(QSerialPort::TwoStop);
        break;
    }

    if( m_device->open(QIODevice::ReadWrite) )
        return true;

    return false;
}

void SerialScanner::readPacket()
{
    QByteArray packet = m_device->read(32768);

    for( int x=0; x < packet.length(); x++ )
    {
        char byte = packet.at(x);
        emit characterScanned(byte);
    }
}
void SerialScanner::setOpen(bool value)
{
    if( value == m_open && m_open == m_device->isOpen() )
        return;

    m_open = value;

    if( value )
    {
        if( m_devicePath.isEmpty() )
            return;

        if( m_open && m_device->isOpen() )
            m_device->close();

        if( !intOpen() )
            m_open = false;

        return;
    }

    m_device->close();
    return;
}

void SerialScanner::setDevicePath(const QString &path)
{
    if( m_devicePath == path )
        return;

    m_devicePath = path;
    m_device->setPortName(m_devicePath);

    if( m_open )
    {
        if( m_device->isOpen() )
            m_device->close();

        intOpen();
    }
}

