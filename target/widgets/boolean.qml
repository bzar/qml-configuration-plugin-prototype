import Qt 4.7

Rectangle {
    id: control
    property QtObject configurationItem: parent.item

    width: 25
    height: 25
    color: "#fee"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            control.configurationItem.value = !control.configurationItem.value
            flipable.flipped = !flipable.flipped
        }

    }

    Flipable {
        id: flipable

        property bool flipped: control.configurationItem.value
        anchors.fill: parent
        anchors.margins: 2

        front: Rectangle {
            color: "#eaa"
            anchors.fill: parent
        }
        back: Rectangle {
            color: "#aea"
            anchors.fill: parent
        }

        transform: Rotation {
           id: rotation
           origin.x: flipable.width/2
           origin.y: flipable.height/2
           axis.x: 0; axis.y: 1; axis.z: 0
           angle: 0
       }

       states: State {
           name: "back"
           PropertyChanges { target: rotation; angle: 180 }
           when: flipable.flipped
       }

       transitions: Transition {
           NumberAnimation { target: rotation; property: "angle"; duration: 500 }
       }
    }
}
