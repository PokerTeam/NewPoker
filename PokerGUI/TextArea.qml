// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: textArea

    property int textAreaWidth: 200
    property int textAreaHeight: 28
    property int borderSize: 2
    property int borderRadius: 4
    property int animationDuration: 120

    property color baseColor: "#FF666666"
    property color baseOnHoverColor: "#FF707B7F"
    property color baseFocusedColor: "#FF666B6F"

    property color borderColor: "#60000000"
    property color borderOnHoverColor: "#6080A0B0"

    property string textAreaLabel: "Text area"
    property int textAreaLabelSize: 11
    property color textAreaLabelColor: "#FFB8B8B8"
    property color textAreaLaberOnHoverColor: "#FFEFEFEF"
    property color textAreaLaberFocusedColor: "#FFE0E0E0"

    property string textAreaHint: ""
    property int textAreaHintSize: 8
    property color textAreaHintColor: "#FFB05050"
    property color textAreaHintOnHoverColor: "#FFEF6060"
    property color textAreaHintFocusedColor: "#FFD06060"

    property alias textContent: textInputArea.text
    property color textColor: "#FFD0D0D0"
    property int textMaxLength: 16    
    property int textSize: 11
    property string textFamily: "Segoe UI"
    property bool textBold: false
    property bool textItalic: true
    property bool textPassword: false      

    color: "transparent"
    width: textAreaWidth
    height: textAreaHeight
    onFocusChanged: blockOnFocus(focus)

    Rectangle {
        id: blockLabel

        color: "transparent"
        width: parent.width
        height: parent.height
        anchors.left: parent.left
        anchors.leftMargin: borderRadius
        anchors.bottom: parent.top
        anchors.bottomMargin: 5

        Text {
            id: blockLabelText

            anchors.fill: parent
            verticalAlignment: Text.AlignBottom
            text: textAreaLabel
            font.pointSize: textAreaLabelSize
            font.bold: true
            color: textAreaLabelColor
            Behavior on color { ColorAnimation { duration: animationDuration } }
        }
    }

    Rectangle {
        id: blockText

        anchors.fill: parent
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
            width: parent.width - 2 * borderRadius - 16
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
                    onFocusChanged: blockOnFocus(focus)
                    echoMode: textPassword ? TextInput.Password : TextInput.Normal
                }
            }
        }
    }

    Rectangle {
        id: blockHint

        color: "transparent"
        width: parent.width
        height: parent.height
        anchors.right: parent.right
        anchors.rightMargin: 2 * borderRadius
        anchors.top: parent.bottom
        anchors.topMargin: 2

        Text {
            id: blockHintText

            anchors.fill: parent
            text: textAreaHint
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignTop
            font.pointSize: textAreaHintSize
            font.bold: true
            color: textAreaHintColor
            Behavior on color { ColorAnimation { duration: animationDuration } }
        }
    }

    function blockOnFocus(isFocus) {
        if (textInputArea.focus != isFocus)
            textInputArea.focus = isFocus
        blockLabelText.color =
                textInputArea.focus ? textAreaLaberFocusedColor : textAreaLabelColor
        blockText.color =
                textInputArea.focus ? baseFocusedColor : baseColor
        blockText.border.color = borderColor
        blockHintText.color =
                textInputArea.focus ? textAreaHintFocusedColor : textAreaHintColor        
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
