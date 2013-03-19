// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: gameScreen

    property int gameScreenWidth: 1024
    property int gameScreenHeight: 600

    width: gameScreenWidth
    height: gameScreenHeight
    anchors.fill: parent

    Image {
        id: tableFonImage
        source: "table.png"
        fillMode: Image.Tile
        anchors.fill: parent
    }

    Image {
        id: tableMaskImage
        source: "mask.png"
        fillMode: Image.Stretch
        anchors.fill: parent
    }

    Button {
        id: buttonExit
        objectName: "buttonExit"

        height: 32
        x: 8
        y: 8
        label: "Exit"
        labelColor: "#FFB0B0B0"
        gradientColorTop: "#A0101010"
        gradientOnHoverColorTop: "#A0303030"
        gradientColorBottom: "#A0000000"
        gradientOnHoverColorBottom: "#A0202020"
        borderSize: 2
    }

    Button {
        id: buttonFold
        objectName: "buttonFold"

        height: 32
        x: 8
        y: parent.height - height - 8
        label: "Fold"
        labelColor: "#FFB0B0B0"
        gradientColorTop: "#A0101010"
        gradientOnHoverColorTop: "#A0303030"
        gradientColorBottom: "#A0000000"
        gradientOnHoverColorBottom: "#A0202020"
        borderSize: 2
    }

    Button {
        id: buttonCall
        objectName: "buttonCall"

        height: 32
        x: buttonFold.x + buttonFold.width + 10
        y: parent.height - height - 8
        label: "Call"
        labelColor: "#FFB0B0B0"
        gradientColorTop: "#A0101010"
        gradientOnHoverColorTop: "#A0303030"
        gradientColorBottom: "#A0000000"
        gradientOnHoverColorBottom: "#A0202020"
        borderSize: 2
    }

    Button {
        id: buttonRaise
        objectName: "buttonRaise"

        height: 32
        x: buttonCall.x + buttonCall.width + 10
        y: parent.height - height - 8
        label: "Raise"
        labelColor: "#FFB0B0B0"
        gradientColorTop: "#A0101010"
        gradientOnHoverColorTop: "#A0303030"
        gradientColorBottom: "#A0000000"
        gradientOnHoverColorBottom: "#A0202020"
        borderSize: 2
    }

    Rectangle {
        id: blockRaiseValue

        width: buttonInc.width + textRaiseValue.width + buttonDec.width + 20
        height: 32
        x: buttonRaise.x + buttonRaise.width + 30
        y: parent.height - height - 8
        color: "#60303030"
        border {
            width: 2;
            Behavior on color { ColorAnimation { duration: animationDuration } }
            color: "#20FFFFFF"
        }
        radius: 8
        smooth: true

        Button {
            id: buttonDec
            objectName: "buttonDec"

            width: 36
            height: 32
            anchors.left: parent.left
            anchors.top: parent.top
            label: "-"
            labelSize: 12
            labelColor: "#FFB0B0B0"
            gradientColorTop: "#A0101010"
            gradientOnHoverColorTop: "#A0303030"
            gradientColorBottom: "#A0000000"
            gradientOnHoverColorBottom: "#A0202020"
            borderSize: 2
        }

        Text {
            id: textRaiseValue
            objectName: "textRaiseValue"

            property string raiseValue: "1024"

            height: 32
            anchors.centerIn: parent
            text: raiseValue
            color: "#FFB0B0B0"
            font.bold: true
            font.family: "Sagoe UI"
            font.pointSize: 11
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            id: buttonInc
            objectName: "buttonInc"

            width: 36
            height: 32
            anchors.right: parent.right
            anchors.top: parent.top
            label: "+"
            labelSize: 12
            labelColor: "#FFB0B0B0"
            gradientColorTop: "#A0101010"
            gradientOnHoverColorTop: "#A0303030"
            gradientColorBottom: "#A0000000"
            gradientOnHoverColorBottom: "#A0202020"
            borderSize: 2
        }
    }

    UserBlock {
        id: user3
        objectName: "user3"

        anchors.top: parent.top
        anchors.topMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 6
        ublockWidth: 212
        ublockHeight: 64
        labelSize: 12
    }

    UserBlock {
        id: user2
        objectName: "user2"

        anchors.top: parent.top
        anchors.topMargin: 6
        anchors.right: user3.left
        anchors.rightMargin: 18
        ublockWidth: 212
        ublockHeight: 64
        labelSize: 12
    }

    UserBlock {
        id: user1
        objectName: "user1"

        anchors.top: parent.top
        anchors.topMargin: 6
        anchors.right: user2.left
        anchors.rightMargin: 18
        ublockWidth: 212
        ublockHeight: 64
        labelSize: 12        
    }

    CardImage {
        id: cardImageSelf1
        objectName: "cardImageSelf1"

        anchors.top: parent.bottom
        anchors.topMargin: -126
        anchors.left: parent.right
        anchors.leftMargin: -140
    }

    CardImage {
        id: cardImageSelf2
        objectName: "cardImageSelf2"

        anchors.top: parent.bottom
        anchors.topMargin: -126
        anchors.left: parent.right
        anchors.leftMargin: -106
    }

    UserBlock {
        id: userSelf
        objectName: "userSelf"

        anchors.top: parent.bottom
        anchors.topMargin: -60 - 6
        anchors.left: parent.right
        anchors.leftMargin: -250 - 6
        ublockWidth: 250
        ublockHeight: 60
        labelSize: 12
        userAvaImage: 1
        failedUser: false
        gradientColorTop: "#FB101010"
        gradientOnActiveColorTop: "#FB303030"
        gradientOnFailColorTop: "#FB606060"
        gradientColorBottom: "#FB000000"
        gradientOnActiveColorBottom: "#FB202020"
    }

    CardImage {
        id: card3
        objectName: "card3"

        anchors.centerIn: parent
    }

    CardImage {
        id: card2
        objectName: "card2"

        anchors.top: card3.top
        anchors.right: card3.left
        anchors.rightMargin: 18
    }

    CardImage {
        id: card1
        objectName: "card1"

        anchors.top: card3.top
        anchors.right: card2.left
        anchors.rightMargin: 18
    }

    CardImage {
        id: card4
        objectName: "card4"

        anchors.top: card3.top
        anchors.left: card3.right
        anchors.leftMargin: 18
    }

    CardImage {
        id: card5
        objectName: "card5"

        anchors.top: card3.top
        anchors.left: card4.right
        anchors.leftMargin: 18
    }

    Gradient {
        GradientStop { position: 0.0; color: "#FF393939" }
        GradientStop { position: 1.0; color: "#FF222222" }
    }
}
