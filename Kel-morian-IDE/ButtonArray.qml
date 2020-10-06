import QtQuick 2.12
import QtQuick.Controls 2.12

Item {

    Label {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: array.top  // anchor to the top of Column component
        anchors.bottomMargin: 10 // set a margin of 10
        font.pointSize: 25
        text: "Button array"
    }

    Column {  // It is possible to change "Column" with "Row" to achieve a horizontal arrangement
        id: array
        anchors.centerIn: parent
        spacing: 5

        Button {
            text: "Button 1"

            onClicked: {
                // this is a javascript function provided as callback for on click event
                console.log(`${text} was clicked`)  // access to this button text property
            }
        }

        Button {
            text: "Button 2"
            onClicked: {
                console.log(`${text} was clicked`)  // access to this button text property
            }
        }

        Button {
            text: "Button 3"
            onClicked: {
                console.log(`${text} was clicked.`)  // access to this button text property
            }
        }

        Button {
            text: "Button 4"
            onClicked: {
                console.log(`${text} was clicked`)  // access to this button text property
            }
        }
    }
}
