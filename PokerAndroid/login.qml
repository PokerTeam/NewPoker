import QtQuick 1.1

Rectangle {
    id: loginScreen

    property int loginScreenWidth: 1024
    property int loginScreenHeight: 560

    width: loginScreenWidth
    height: loginScreenHeight
    anchors.fill: parent    
    color: "#FF222222"

    Rectangle {
        id: loginSplash

        anchors.centerIn: parent
        width: textAreaLogin.width * 1.4
        height: parent.height
        color: "#FF404040"
    }

    Text {
        id: labelGameName

        text: "Amaizing Poker"
        color: "#FF161616"
        anchors.top: parent.top
        anchors.topMargin: paintedHeight + 6
        x: (parent.width - paintedWidth) * 0.5
        font.pointSize: 16
        font.bold: true
        font.family: "Segoe UI"
    }

    Text {
        text: "Amaizing Poker"
        color: "#FFD6D6D6"
        anchors.top: labelGameName.top
        anchors.topMargin: 2
        anchors.left: labelGameName.left
        anchors.leftMargin: 2
        font.pointSize: 16
        font.bold: true
        font.family: "Segoe UI"
    }

    Rectangle {
        anchors.right: loginSplash.left
        anchors.top: loginSplash.top
        width: loginSplash.width * 0.36
        height: parent.height
        color: "#00000000"

        Rectangle {
            anchors.centerIn: parent
            width: parent.height
            height: parent.width
            rotation: 270
            gradient: Gradient {
                GradientStop { position: 0.0; color: "#FF222222" }
                GradientStop { position: 1.0; color: "#FF060606" }
            }
        }
    }

    Rectangle {
        anchors.left: loginSplash.right
        anchors.top: loginSplash.top
        width: loginSplash.width * 0.36
        height: parent.height
        color: "#00000000"

        Rectangle {
            anchors.centerIn: parent
            width: parent.height
            height: parent.width
            rotation: 270
            gradient: Gradient {
                GradientStop { position: 0.0; color: "#FF060606" }
                GradientStop { position: 1.0; color: "#FF222222" }
            }
        }
    }

    TextArea {
        id: textAreaLogin
        objectName: "textAreaLogin"

        x: textAreaPassword.x
        y: textAreaPassword.y - 2.6 * textAreaPassword.height
        width: buttonRegister.width + buttonLogin.width + 20
        height: 46
        textMaxLength: 24
        textAreaLabel: "Login"
        textAreaLabelSize: 6
        textAreaHint: "Wrong user name"
        focus: true

        KeyNavigation.tab: textAreaPassword
        KeyNavigation.down: textAreaPassword
    }

    TextArea {
        id: textAreaPassword
        objectName: "textAreaPassword"

        anchors.centerIn: parent
        width: buttonRegister.width + buttonLogin.width + 20
        height: 46
        textAreaLabel: "Password"
        textAreaLabelSize: 6
        textAreaHint: "Wrong password"
        textPassword: true

        KeyNavigation.tab: buttonLogin
        KeyNavigation.down: buttonLogin
        KeyNavigation.up: textAreaLogin
    }    

    Button {
        id: buttonLogin
        objectName: "buttonLogin"

        height: 30
        x: parent.width / 2 - width - 10
        y: textAreaPassword.y + 2.1 * textAreaPassword.height
        label: "Login"
        labelColor: "#FFB0B0B0"

        KeyNavigation.tab: buttonRegister
        KeyNavigation.up: textAreaPassword
        KeyNavigation.right: buttonRegister
    }

    Button {
        id: buttonRegister
        objectName: "buttonRegister"

        height: 30
        x: parent.width / 2 + 10
        y: textAreaPassword.y + 2.1 * textAreaPassword.height
        label: "Register"
        labelColor: "#FFB0B0B0"

        KeyNavigation.tab: textAreaLogin
        KeyNavigation.up: textAreaPassword
        KeyNavigation.left: buttonLogin
    }
}
