import Qt 4.7

Rectangle {
    id: control
    property QtObject configurationItem: parent.item

    width: 100
    height: 25
    gradient: Gradient { GradientStop { position: 0.5; color: "#fff" } GradientStop { position: 1; color: "#ddd" } }
    radius: 5
    smooth: true
    border {
        width: 1
        color: "#111";
    }

    TextInput {
        id: inputField
        anchors.fill: parent
        anchors.margins: 3
        anchors.verticalCenter: parent.verticalCenter
        text: control.configurationItem.value
        onTextChanged: {
            if(control.configurationItem.value != inputField.text)
            {
                control.configurationItem.value = inputField.text;
            }
        }

    }
}
