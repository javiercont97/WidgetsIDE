import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Extras 1.4


Item {
    id: root
    property double max: 100
    property double min: 0
    property double value: 0

    CircularGauge {
        id: gauge
        value: root.value
        maximumValue: root.max
        minimumValue: root.min
        anchors.fill: parent

        Behavior on value {
            NumberAnimation {
                duration: 1000
            }
        }
    }

}
