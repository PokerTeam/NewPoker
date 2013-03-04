// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: loginScreen

    property int loginScreenWidth: 360
    property int loginScreenHeight: 380

    width: loginScreenWidth
    height: loginScreenHeight
    anchors.fill: parent
    gradient: Gradient {
        GradientStop { position: 0.0; color: "#FF393939" }
        GradientStop { position: 1.0; color: "#FF222222" }
    }

    TextArea {
        id: textAreaLogin

        x: textAreaPassword.x
        y: textAreaPassword.y - 2.6 * textAreaPassword.height
        width: buttonRegister.width + buttonLogin.width + 20
        height: 32
        borderRadius: 18
        textMaxLength: 24
        textAreaLabel: "Login"
        textAreaLabelSize: 12
        textAreaHint: "Wrong user name"
    }

    TextArea {
        id: textAreaPassword

        anchors.centerIn: parent
        width: buttonRegister.width + buttonLogin.width + 20
        height: 32
        borderRadius: 18
        textAreaLabel: "Password"
        textAreaLabelSize: 12
        textAreaHint: "Wrong password"
        textPassword: true
    }    

    Button {
        id: buttonLogin

        height: 30
        x: parent.width / 2 - width - 10
        y: textAreaPassword.y + 2.1 * textAreaPassword.height
        label: "Login"
        labelColor: "#FFB0B0B0"
    }

    Button {
        id: buttonRegister

        height: 30
        x: parent.width / 2 + 10
        y: textAreaPassword.y + 2.1 * textAreaPassword.height
        label: "Register"
        labelColor: "#FFB0B0B0"

    }
}
