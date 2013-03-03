// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: textArea

    property int textAreaWidth: 300
    property int textAreaHeight: 70
    property int borderSize: 2
    property int borderRadius: 12
    property int animationDuration: 120

    property color baseColor: "#FF606060"
    property color baseOnHoverColor: "#FF707070"
    property color baseFocusedColor: "#FF666666"
    property color borderColor: "#20000000"
    property color borderOnHoverColor: "#30FFFFFF"

    property string textAreaLabel: "Text area"
    property int textAreaLabelSize: 11
    property color textAreaLabelColor: "#FFD0D0D0"
    property color textAreaLaberOnHoverColor: "#FFE5E5E5"
    property color textAreaLaberFocusedColor: "#FFE0E0E0"

    property string textAreaHint: ""
    property int textAreaHintSize: 8
    property color textAreaHintColor: "#FFD06060"
    property color textAreaHintOnHoverColor: "#FFD07070"
    property color textAreaHintFocusedColor: "#FFE06060"

    property alias textContent: textInputArea.text
    property int textMaxLength: 16
    property color textColor: "#FFD0D0D0"
    property int textSize: 10
    property string textFamily: "Segoe UI"
    property bool textBold: false
    property bool textItalic: true
    property bool textPassword: false

    color: "transparent"
    width: textAreaWidth
    height: textAreaHeight

    Rectangle {
        id: blockLabel

        color: "transparent"
        width: parent.width - 2 * borderRadius
        height: parent.height * 0.36
        x: parent.x + borderRadius
        y: parent.y

        Text {
            id: blockLabelText

            text: textAreaLabel
            font.pointSize: textAreaLabelSize
            font.bold: true
            color: textAreaLabelColor
            Behavior on color { ColorAnimation { duration: animationDuration } }
        }
    }

    Rectangle {
        id: blockText

        width: parent.width
        height: parent.height * 0.34
        x: parent.x
        y: parent.y + blockLabel.height

        color: baseColor
        Behavior on color { ColorAnimation { duration: animationDuration } }
        radius: borderRadius
        smooth: true
        border {
            width: borderSize;
            Behavior on color { ColorAnimation { duration: animationDuration } }
            color: borderColor
        }

        Flickable {
            id: flickableArea

            anchors.centerIn: parent
            width: parent.width - 2 * borderRadius
            height: parent.height - 4 * borderSize
            boundsBehavior: Flickable.StopAtBounds
            flickableDirection: Flickable.HorizontalFlick
            interactive: true

            MouseArea {
                id: mouseArea

                anchors.fill: parent
                hoverEnabled: true
                onEntered: blockOnHover(true)
                onExited: blockOnHover(false)
                onClicked: blockOnHover(false)

                TextInput {
                    id: textInputArea

                    anchors.fill: parent
                    maximumLength: textMaxLength
                    color: textColor
                    Behavior on color { ColorAnimation { duration: animationDuration } }
                    font.pointSize: textSize
                    font.family: textFamily
                    font.bold: textBold
                    font.italic: textItalic
                    onFocusChanged: blockOnHover(false)
                    echoMode: textPassword ? TextInput.Password : TextInput.Normal
                }
            }
        }
    }

    Rectangle {
        id: blockHint

        color: "transparent"
        width: parent.width - 2 * borderRadius
        height: parent.height * 0.24
        x: parent.x + borderRadius
        y: parent.y + blockLabel.height + blockText.height +
           textAreaHeight * 0.06

        Text {
            id: blockHintText

            text: textAreaHint
            font.pointSize: textAreaHintSize
            font.bold: true
            color: textAreaHintColor
            Behavior on color { ColorAnimation { duration: animationDuration } }
        }
    }

    function blockOnHover(isHover) {
        if (isHover) {
            blockLabelText.color = textAreaLaberOnHoverColor
            blockText.color = baseOnHoverColor
            blockText.border.color = borderOnHoverColor
            blockHintText.color = textAreaHintOnHoverColor
        }
        else {
            blockLabelText.color =
                    textInputArea.focus ? textAreaLaberFocusedColor : textAreaLabelColor
            blockText.color =
                    textInputArea.focus ? baseFocusedColor : baseColor
            blockText.border.color = borderColor
            blockHintText.color =
                    textInputArea.focus ? textAreaHintFocusedColor : textAreaHintColor
        }
    }
}
