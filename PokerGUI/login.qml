// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 360
    height: 300
    anchors.fill: parent

    gradient: Gradient {
             GradientStop { position: 0.0; color: "#FF393939" }
             GradientStop { position: 1.0; color: "#FF222222" }
    }

    property int spliterWidth: 20

    TextArea {
        id: textAreaLogin

        x: textAreaPassword.x
        y: textAreaPassword.y - 2.6 * textAreaPassword.height
        width: buttonRegister.width + buttonLogin.width + spliterWidth
        height: 28
        textMaxLength: 24
        textAreaLabel: "Login"
        textAreaHint: "Wrong user name"
    }

    TextArea {
        id: textAreaPassword

        anchors.centerIn: parent
        width: buttonRegister.width + buttonLogin.width + spliterWidth
        height: 28
        textAreaLabel: "Password"
        textAreaHint: "Wrong password"
        textPassword: true
    }    

    Button {
        id: buttonLogin

        height: 28
        x: parent.width / 2 - width - spliterWidth / 2
        y: textAreaPassword.y + 2 * textAreaPassword.height
        label: "Login"
        labelColor: "#FFB0B0B0"
    }

    Button {
        id: buttonRegister

        height: 28
        x: parent.width / 2 + spliterWidth / 2
        y: textAreaPassword.y + 2 * textAreaPassword.height
        label: "Register"
        labelColor: "#FFB0B0B0"

    }
}
