// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: button

    property int buttonWidth: 120
    property int buttonHeight: 32
    property int borderSize: 4
    property int borderRadius: 8
    property int animationDuration: 120

    property color gradientColorTop: "#FF202020"
    property color onHoverGradientColorTop: "#FF303030"
    property color gradientColorBottom: "#FF101010"
    property color onHoverGradientColorBottom: "#FF202020"
    property color borderColor: "#20FFFFFF"
    property color onHoverBorderColor: "#24FFFFFF"

    property color labelColor: "#FFFFFFFF"
    property bool labelBold: true
    property bool labelItalic: false
    property string labelFontFamily: "Segoe UI"
    property string label: "button"
    property real labelSize: 11

    width: buttonWidth
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
            color: buttonLogin.gradientColorTop }
        GradientStop { position: 1.0;
            Behavior on color { ColorAnimation { duration: animationDuration } }
            color: buttonLogin.gradientColorBottom }
    }

    Text {
        text: label
        color: labelColor
        anchors.centerIn: parent;
        font.pointSize: labelSize
        font.bold: labelBold
        font.italic: labelItalic
        font.family: labelFontFamily
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onClicked: buttonClick()
        onEntered: onButtonHover(true)
        onExited:  onButtonHover(false)
    }

    signal buttonClick()

    function onButtonHover(isHover) {
        if (isHover) {
            border.color = onHoverBorderColor
            gradient.stops[0].color = onHoverGradientColorTop
            gradient.stops[1].color = onHoverGradientColorBottom
        }
        else {
            border.color = borderColor
            gradient.stops[0].color = gradientColorTop
            gradient.stops[1].color = gradientColorBottom
        }
    }

}
