# QmlPedalboard
A Udev rule, a tiny Arduino program, a Qml Component, and a test Qml app to interface a pedal board with QML.

## Arduino
The sketch assumes your pedals are connected on pins 2, 3, 4, and 5. If you use different pins, update the defines at the top.

## UDEV:
* Edit 20-pedalboard.rules to match your user
* Copy 20-pedalboard.rules to /etc/udev/rules.d/

## QML
* Build and install the SerialScanner component (qmake, make, sudo make install)
* Run main.qml using qmlscene, triggers will display on the terminal.

## Watch the video:
https://www.youtube.com/watch?v=aOwuXJ_fbTo&t=23s

## My Mixer channel:
http://mixer.com/LittleDrummerGuy

## My OBS QML source plugin:
https://github.com/danieloneill/obs-qmlview

