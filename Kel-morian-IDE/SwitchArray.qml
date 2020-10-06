import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Label {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: array.top  // anchor to the top of Column component
        anchors.bottomMargin: 10 // set a margin of 10
        font.pointSize: 25
        text: "Switch array"
    }

    Column { // It is possible to change "Column" with "Row" to achieve a horizontal arrangement
        id: array
        anchors.centerIn: parent
        spacing: 5

        Switch {
            text: "Switch 1"

            onCheckedChanged: {
                // this is a javascript function provided as callback for on checked change event
                console.log(`${text} was switched to ${checked}`)  // access to this switch text and checked properties
                if(checked) {
                    // switch is on
                } else {
                    // switch is off
                }
            }
        }

        Switch {
            text: "Switch 2"
            checked: true  // set initial state as checked

            onCheckedChanged: {
                // this is a javascript function provided as callback for on checked change event
                console.log(`${text} was switched to ${checked}`)  // access to this switch text and checked properties
            }
        }

        Switch {
            text: "Switch 3"

            onCheckedChanged: {
                // this is a javascript function provided as callback for on checked change event
                console.log(`${text} was switched to ${checked}`)  // access to this switch text and checked properties
            }
        }

        Switch {
            text: "Switch 4"

            onCheckedChanged: {
                // this is a javascript function provided as callback for on checked change event
                console.log(`${text} was switched to ${checked}`)  // access to this switch text and checked properties
            }
        }
    }
}
