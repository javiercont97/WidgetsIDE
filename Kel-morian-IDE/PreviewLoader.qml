import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Extras 1.4

Item {
    id: root
    property string sourcePath: ""

    Loader {
        id: loader
        anchors.fill: parent
        source: root.sourcePath
    }
}
