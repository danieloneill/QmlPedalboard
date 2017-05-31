#ifndef SERIALSCANNER_H
#define SERIALSCANNER_H

#include <QQuickItem>
#include <QSerialPort>

class SerialScanner : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(SerialScanner)

public:
    typedef enum {
        NoParity = 0,
        OddParity = 1,
        EvenParity = 2
    } Parity;
    Q_ENUMS(Parity)

private:
    QString     m_devicePath;
    QSerialPort *m_device;
    int         m_baudRate;
    int         m_dataBits;
    Parity      m_parity;
    int         m_stopBits;

    bool        m_open;

public:
    SerialScanner(QQuickItem *parent = 0);
    ~SerialScanner();

    Q_PROPERTY(bool open READ getOpen WRITE setOpen NOTIFY openChanged)
    Q_PROPERTY(QString devicePath READ getDevicePath WRITE setDevicePath NOTIFY devicePathChanged)
    Q_PROPERTY(int baudRate READ getBaudRate WRITE setBaudRate NOTIFY baudRateChanged)
    Q_PROPERTY(int dataBits READ getDataBits WRITE setDataBits NOTIFY dataBitsChanged)
    Q_PROPERTY(Parity parity READ getParity WRITE setParity NOTIFY parityChanged)
    Q_PROPERTY(int stopBits READ getStopBits WRITE setStopBits NOTIFY stopBitsChanged)

public slots:
    bool getOpen();
    QString getDevicePath();

    void setOpen(bool value);
    void setDevicePath(const QString &path);

    int getBaudRate() { return m_baudRate; }
    int getDataBits() { return m_dataBits; }
    Parity getParity() { return m_parity; }
    int getStopBits() { return m_stopBits; }

    void setBaudRate(int baudRate) {
        m_baudRate = baudRate;
        emit baudRateChanged();
    }
    void setDataBits(int dataBits) {
        m_dataBits = dataBits;
        emit dataBitsChanged();
    }
    void setParity(Parity parity) {
        m_parity = parity;
        emit parityChanged();
    }
    void setStopBits(int stopBits) {
        m_stopBits = stopBits;
        emit stopBitsChanged();
    }

private slots:
    bool intOpen();
    void readPacket();

signals:
    void openChanged();
    void devicePathChanged();

    void baudRateChanged();
    void dataBitsChanged();
    void parityChanged();
    void stopBitsChanged();

    void characterScanned(char c);
};

//Q_DECLARE_METATYPE(SerialFuelPriceRequest*)

#endif // SERIALSCANNER_H

