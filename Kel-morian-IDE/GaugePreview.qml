import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Label {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: gauge.top // anchor to the top of the gauge
        anchors.bottomMargin: 10 // set a margin of 10
        font.pointSize: 25
        text: "Gauge"
    }

    Gauge {
        id: gauge
        value: accelerating ? maximumValue : 0
        anchors.centerIn: parent
        width: 200
        height: 200
        /*
            This section is for demostrative purposes. Remove this and set "value" property to change gause position (gauge.value = anyvalue)
        */
        property bool accelerating: false
        Keys.onSpacePressed: accelerating = true
        Keys.onReleased: {
            if (event.key === Qt.Key_Space) {
                accelerating = false;
                event.accepted = true;
            }
        }
        Component.onCompleted: forceActiveFocus()
        // remove above section
    }

}
