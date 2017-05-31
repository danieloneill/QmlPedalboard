import QtQuick 2.7

Item {
    id: main
    anchors.fill: parent

    SerialPedalBoard {
        id: spb
        onPedalA: {
            console.log("Pedal A!");
        }
        onPedalB: {
            console.log("Pedal B!");
        }
        onPedalC: {
            console.log("Pedal C!");
        }
        onPedalD: {
            console.log("Pedal D!");
        }
    }
}
