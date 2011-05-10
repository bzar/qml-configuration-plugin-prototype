import Qt 4.7
import Configuration 1.0

Rectangle {
    width: 640
    height: 480

    ListView {
        model: configurationModel
        anchors.fill: parent

        delegate: Rectangle {
            width: parent.width
            height: 30

            gradient: Gradient { GradientStop { position: 0.5; color: "#ddf" } GradientStop { position: 1; color: "#bbd" } }
            radius: 10
            smooth: true
            border {
                width: 1
                color: "#111";
            }


            Text {
                id: labelText
                text: label
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
            }
            ConfigurationWidget {
                item: configurationItem
                width: childrenRect.width
                height: childrenRect.height
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
            }
        }

    }

}
