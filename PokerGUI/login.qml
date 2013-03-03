// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 600
    height: 600
    anchors.fill: parent

    gradient: Gradient {
             GradientStop { position: 0.0; color: "#FF404040" }
             GradientStop { position: 1.0; color: "#FF202020" }
    }

    property int spliterWidth: 40
    property int spliterHeight: 32

    Rectangle {
        id: labelLogin
        color: "transparent"
        width: 60
        height: 30
        x: textAreaLogin.x + 20;
        y: textAreaLogin.y - height;

        Text {
            text: "User login"
            font.pointSize: 12
            font.bold: true
            color: "#A0FFFFFF"
        }
    }

    Rectangle {
        id: textAreaLogin

        property int textAreaWidth: 280
        property int textAreaHeight: 28
        property int borderSize: 2
        property int borderRadius: 8
        property real labelSize: 12
        property color fontColor: "#FFCFCFE0"
        property alias textContent: textEditLogin.text
        property color borderColor: "#60000000"
        property color onHoverBorderColor: "#40606080"

        width: textAreaWidth
        height: textAreaHeight
        x: parent.width / 2 - textAreaLogin.width / 2;
        y: parent.height / 2 - 2 * textAreaLogin.textAreaHeight -
           parent.spliterHeight - labelPassword.height;

        radius: borderRadius
        smooth: true
        border { width: borderSize;
            Behavior on color { ColorAnimation{ duration: 160 } }
            color: textAreaLogin.borderColor }

        function onHover(isHover) {
            if (isHover) {
                border.color = textAreaLogin.onHoverBorderColor
            }
            else {
                border.color = textAreaLogin.borderColor
            }
        }

        Flickable {
            id: flickAreaLogin
            anchors.centerIn: parent
            width: parent.width - parent.borderSize * 4;
            height: parent.height - parent.borderSize *4;
            boundsBehavior: Flickable.StopAtBounds
            flickableDirection: Flickable.HorizontalFlick
            interactive: true

            MouseArea {
                anchors.centerIn: parent
                width: parent.width
                height: parent.height
                hoverEnabled: true
                onEntered: textAreaLogin.onHover(true)
                onExited: textAreaLogin.onHover(false)

                TextInput {
                    id: textEditLogin
                    focus: true
                    anchors.centerIn: parent
                    width: parent.width
                    height: parent.height
                    color: textAreaLogin.fontColor;
                    font.pointSize: textAreaLogin.labelSize;
                }
            }
        }

        color: textEditLogin.focus ? "#60FFFFFF" : "#40FFFFFF"
        Behavior on color { ColorAnimation{ duration: 160 } }
    }

    Rectangle {
        id: labelPassword
        color: "transparent"
        width: 60
        height: 30
        x: textAreaPassword.x + 20;
        y: textAreaPassword.y - height;

        Text {
            text: "User password"
            font.pointSize: 12
            font.bold: true
            color: "#A0FFFFFF"
        }
    }

    Rectangle {
        id: textAreaPassword

        property int textAreaWidth: 280
        property int textAreaHeight: 28
        property int borderSize: 2
        property int borderRadius: 8
        property real labelSize: 12
        property color fontColor: "#FFCFCFE0"
        property alias textContent: textEditPassword.text
        property color borderColor: "#60000000"
        property color onHoverBorderColor: "#40606080"

        width: textAreaWidth
        height: textAreaHeight
        x: parent.width / 2 - textAreaPassword.width / 2;
        y: parent.height / 2 - textAreaPassword.textAreaHeight - parent.spliterHeight / 2;

        radius: borderRadius
        smooth: true
        border { width: borderSize;
            Behavior on color { ColorAnimation{ duration: 160 } }
            color: textAreaPassword.borderColor }

        function onHover(isHover) {
            if (isHover) {
                border.color = textAreaPassword.onHoverBorderColor
            }
            else {
                border.color = textAreaPassword.borderColor
            }
        }


        Flickable {
            id: flickAreaPassword
            anchors.centerIn: parent
            width: parent.width - parent.borderSize * 4;
            height: parent.height - parent.borderSize * 4;
            boundsBehavior: Flickable.StopAtBounds
            flickableDirection: Flickable.HorizontalFlick
            interactive: true

            MouseArea {
                anchors.centerIn: parent
                width: parent.width
                height: parent.height
                hoverEnabled: true
                onEntered: textAreaPassword.onHover(true)
                onExited: textAreaPassword.onHover(false)

                TextInput {
                    id: textEditPassword
                    anchors.centerIn: parent
                    width: parent.width
                    height: parent.height
                    color: textAreaPassword.fontColor;
                    font.pointSize: textAreaPassword.labelSize;
                }
            }
        }

        color: textEditPassword.focus ? "#60FFFFFF" : "#40FFFFFF"
        Behavior on color { ColorAnimation{ duration: 160 } }
    }

    Rectangle {
        id: buttonLogin

        property int buttonWidth: 120
        property int buttonHeight: 32
        property int borderSize: 4
        property int borderRadius: 8

        property color gradientColorTop: "#FFB0B0B0"
        property color onHoverGradientColorTop: "#FF969696"
        property color gradientColorBottom: "#FF828282"
        property color onHoverGradientColorBottom: "#FF606060"
        property color borderColor: "#50FFFFFF"
        property color onHoverBorderColor: "#40000000"

        property string label: "Login"
        property real labelSize: 14

        width: buttonWidth
        height: buttonHeight
        x: parent.width / 2 - buttonWidth - parent.spliterWidth / 2;
        y: parent.height / 2 + spliterHeight / 2;

        radius: borderRadius
        smooth: true
        border { width: borderSize;
            Behavior on color { ColorAnimation { duration: 120 } }
            color: borderColor }
        gradient: Gradient {
            GradientStop { position: 0.0;
                Behavior on color { ColorAnimation { duration: 120 } }
                color: buttonLogin.gradientColorTop }
            GradientStop { position: 1.0;
                Behavior on color { ColorAnimation { duration: 120 } }
                color: buttonLogin.gradientColorBottom }
        }

        Text {
            text: parent.label
            anchors.centerIn: parent;
            font.pointSize: parent.labelSize
        }

        signal buttonClick()

        function onHover(isHover) {
            if (isHover) {
                border.color = buttonLogin.onHoverBorderColor
                gradient.stops[0].color = buttonLogin.onHoverGradientColorTop
                gradient.stops[1].color = buttonLogin.onHoverGradientColorBottom
            }
            else {
                border.color = buttonLogin.borderColor
                gradient.stops[0].color = buttonLogin.gradientColorTop
                gradient.stops[1].color = buttonLogin.gradientColorBottom
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: buttonClick()
            hoverEnabled: true
            onEntered: parent.onHover(true)
            onExited:  parent.onHover(false)
        }
    }

    Rectangle {
        id: buttonRegister

        property int buttonWidth: 120
        property int buttonHeight: 32
        property int borderSize: 4
        property int borderRadius: 8

        property color gradientColorTop: "#FFB0B0B0"
        property color onHoverGradientColorTop: "#FF969696"
        property color gradientColorBottom: "#FF828282"
        property color onHoverGradientColorBottom: "#FF606060"
        property color borderColor: "#50FFFFFF"
        property color onHoverBorderColor: "#40000000"

        property string label: "Register"
        property real labelSize: 14

        width: buttonWidth
        height: buttonHeight
        x: parent.width / 2 + parent.spliterWidth / 2;
        y: parent.height / 2 + spliterHeight / 2;

        radius: borderRadius
        smooth: true
        border { width: borderSize;
            Behavior on color { ColorAnimation { duration: 120 } }
            color: borderColor }
        gradient: Gradient {
            GradientStop { position: 0.0;
                Behavior on color { ColorAnimation { duration: 120 } }
                color: buttonRegister.gradientColorTop }
            GradientStop { position: 1.0;
                Behavior on color { ColorAnimation { duration: 120 } }
                color: buttonRegister.gradientColorBottom }
        }

        Text {
            text: parent.label
            anchors.centerIn: parent;
            font.pointSize: parent.labelSize
        }

        signal buttonClick()

        function onHover(isHover) {
            if (isHover)
            {
                border.color = buttonRegister.onHoverBorderColor
                gradient.stops[0].color = buttonRegister.onHoverGradientColorTop
                gradient.stops[1].color = buttonRegister.onHoverGradientColorBottom
            }
            else
            {
                border.color = buttonRegister.borderColor
                gradient.stops[0].color = buttonRegister.gradientColorTop
                gradient.stops[1].color = buttonRegister.gradientColorBottom
            }
        }

        MouseArea {
            id: buttonMouseAreaRegister
            anchors.fill: parent
            onClicked: buttonClick()
            hoverEnabled: true
            onEntered: parent.onHover(true)
            onExited:  parent.onHover(false)
        }
    }
}
