#include "serialscanner_plugin.h"
#include "serialscanner.h"

#include <qqml.h>

void SerialScannerPlugin::registerTypes(const char *uri)
{
    // @uri com.foxmoxie.SerialScanner
    qmlRegisterType<SerialScanner>(uri, 1, 0, "SerialScanner");
}
