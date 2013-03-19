import QtQuick 1.1

Rectangle {
    id: button

    property int buttonWidth: 110
    property int buttonHeight: 32
    property int borderSize: 4
    property int borderRadius: 6
    property int animationDuration: 120

    property color gradientColorTop: "#FF202020"
    property color gradientOnHoverColorTop: "#FF303030"
    property color gradientColorBottom: "#FF101010"
    property color gradientOnHoverColorBottom: "#FF202020"
    property color borderColor: "#20FFFFFF"
    property color borderOnHoverColor: "#24FFFFFF"

    property color labelColor: "#FFFFFFFF"
    property bool labelBold: true
    property bool labelItalic: false
    property string labelFontFamily: "Segoe UI"
    property string label: "button"
    property real labelSize: 11

    signal buttonClick()

    width: (buttonLabel.paintedWidth <= (buttonWidth - 4 * borderRadius)) ? (buttonWidth) : (buttonLabel.paintedWidth + 4 * borderRadius)
    height: buttonHeight
    radius: borderRadius
    smooth: true
    border {
        width: borderSize;
        Behavior on color { ColorAnimation { duration: animationDuration } }
        color: borderColor }
    gradient: Gradient {
        GradientStop { position: 0.0;
            Behavior on color { ColorAnimation { duration: animationDuration } }
            color: gradientColorTop }
        GradientStop { position: 1.0;
            Behavior on color { ColorAnimation { duration: animationDuration } }
            color: gradientColorBottom }
    }

    Text {
        id: buttonLabel

        text: label
        color: labelColor
        anchors.centerIn: parent
        font.pointSize: labelSize
        font.bold: labelBold
        font.italic: labelItalic
        font.family: labelFontFamily
    }

    MouseArea {
        id: buttonMouseArea

        anchors.fill: parent
        hoverEnabled: true
        onClicked: buttonClick()
        onEntered: buttonOnHover(true)
        onExited:  buttonOnHover(false)
    }    

    function buttonOnHover(isHover) {
        if (isHover) {
            border.color = borderOnHoverColor
            gradient.stops[0].color = gradientOnHoverColorTop
            gradient.stops[1].color = gradientOnHoverColorBottom
        }
        else {
            border.color = borderColor
            gradient.stops[0].color = gradientColorTop
            gradient.stops[1].color = gradientColorBottom
        }
    }

}
