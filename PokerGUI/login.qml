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

    TextArea {
        id: textAreaLogin
        x: 10
        y: 10
        width: 180
        height: 36
        textAreaLabel: "Login"
        textAreaHint: "Unknown user name"
    }

    TextArea {
        id: textAreaPassword
        x: 10
        y: textAreaLogin.y + 36
        width: 180
        height: 36
        textAreaLabel: "Register"
        textAreaHint: "Unknown password"
    }

    Button {
        id: buttonLogin
        x: parent.width / 2 - width - spliterWidth / 2
        y: parent.height / 2 + spliterHeight / 2
        label: "Login"
        labelColor: "#FFB0B0B0"
    }

    Button {
        id: buttonRegister
        x: parent.width / 2 + spliterWidth / 2
        y: parent.height / 2 + spliterHeight / 2
        label: "Register"
        labelColor: "#FFB0B0B0"

    }
}
