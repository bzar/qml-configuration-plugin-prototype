import Qt 4.7

Item {
    id: control
    property QtObject configurationItem: parent.item

    width: 100
    height: 25

    Rectangle {
        x: 5
        height: 3
        width: 90
        color: "#111"
        radius: 1
        smooth: true

        anchors.centerIn: parent
    }

    Rectangle {
        y: control.configurationItem.value
        width: 10
        height: 20
        color: "#eee"
        radius: 2
        smooth: true
        border {
            width: 1
            color: "#111"
        }

        anchors.verticalCenter: parent.verticalCenter

        MouseArea {
            anchors.fill: parent
            drag {
                target: parent
                axis: Drag.XAxis
                minimumX: 0
                maximumX: 90
            }

            onPositionChanged: {
                var item = control.configurationItem;
                item.value = (item.maxValue - item.minValue) * parent.x / drag.maximumX + item.minValue;
            }

        }
    }
}
