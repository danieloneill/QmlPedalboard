import QtQuick 2.4
import com.foxmoxie.SerialScanner 1.0

Item {
    id: pedalBoard

    signal pedalA();
    signal pedalB();
    signal pedalC();
    signal pedalD();

    SerialScanner {
        id: serial

        property string buffer: ''

        devicePath: "/dev/usb/pedalboard"
        baudRate: 115200
        dataBits: 8
        parity: SerialScanner.NoParity
        stopBits: 1

        onCharacterScanned: {
            var val = String.fromCharCode(c);
            if( c == 10 ) return;
            if( c == 13 ) {
                handleBuffer();
                return;
            }
            console.log("Serial: "+c+" == "+val);
            buffer += val;
        }

        function handleBuffer() {
            console.log("SERIAL:"+buffer);

            if( buffer == 'PIN_0' )
                pedalBoard.pedalA();
            else if( buffer == 'PIN_1' )
                pedalBoard.pedalB();
            else if( buffer == 'PIN_2' )
                pedalBoard.pedalC();
            else if( buffer == 'PIN_3' )
                pedalBoard.pedalD();
            buffer = '';
        }
    }

    Component.onCompleted: {
        serial.open = true;
    }
}
