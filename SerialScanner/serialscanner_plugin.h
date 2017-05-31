#ifndef SERIALSCANNER_PLUGIN_H
#define SERIALSCANNER_PLUGIN_H

#include <QQmlExtensionPlugin>

class SerialScannerPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // SERIALSCANNER_PLUGIN_H

