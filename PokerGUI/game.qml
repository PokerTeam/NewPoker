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

        width: buttonAdd.width + textRaiseValue.width + buttonDel.width + 20
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
            id: buttonDel

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

            width: paintedWidth + 10
            height: 32
            anchors.centerIn: parent
            text: "1025"
            color: "#FFB0B0B0"
            font.bold: true
            font.family: "Sagoe UI"
            font.pointSize: 11
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            id: buttonAdd

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

        anchors.top: parent.top
        anchors.topMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 6
        ublockWidth: 212
        ublockHeight: 64
        labelSize: 12
        userAvaImage: 3
        activeUser: true
    }

    UserBlock {
        id: user2

        anchors.top: parent.top
        anchors.topMargin: 6
        anchors.right: user3.left
        anchors.rightMargin: 18
        ublockWidth: 212
        ublockHeight: 64
        labelSize: 12
        userAvaImage: 0
        failedUser: true
    }

    UserBlock {
        id: user1

        anchors.top: parent.top
        anchors.topMargin: 6
        anchors.right: user2.left
        anchors.rightMargin: 18
        ublockWidth: 212
        ublockHeight: 64
        labelSize: 12
        userAvaImage: 4
    }

    CardImage {
        id: cardImageSelf1

        cardSize: 1
        currentFrame: 0
        anchors.top: parent.bottom
        anchors.topMargin: -126
        anchors.left: parent.right
        anchors.leftMargin: -140
    }

    CardImage {
        id: cardImageSelf2

        cardSize: 1
        currentFrame: 2
        anchors.top: parent.bottom
        anchors.topMargin: -126
        anchors.left: parent.right
        anchors.leftMargin: -106
    }

    UserBlock {
        id: userSelf

        anchors.top: parent.bottom
        anchors.topMargin: -60 - 6
        anchors.left: parent.right
        anchors.leftMargin: -250 - 6
        ublockWidth: 250
        ublockHeight: 60
        labelSize: 12
        userAvaImage: 1
        gradientColorTop: "#FB101010"
        gradientOnActiveColorTop: "#FB303030"
        gradientOnFailColorTop: "#FB606060"
        gradientColorBottom: "#FB000000"
        gradientOnActiveColorBottom: "#FB202020"
    }

    CardImage {
        id: card3

        cardSize: 1
        currentFrame: 3
        anchors.centerIn: parent
    }

    CardImage {
        id: card2

        cardSize: 1
        currentFrame: 4
        anchors.top: card3.top
        anchors.right: card3.left
        anchors.rightMargin: 18
    }

    CardImage {
        id: card1

        cardSize: 1
        currentFrame: 5
        anchors.top: card3.top
        anchors.right: card2.left
        anchors.rightMargin: 18
    }

    CardImage {
        id: card4

        cardSize: 1
        currentFrame: 6
        anchors.top: card3.top
        anchors.left: card3.right
        anchors.leftMargin: 18
    }

    CardImage {
        id: card5

        cardSize: 1
        currentFrame: 7
        anchors.top: card3.top
        anchors.left: card4.right
        anchors.leftMargin: 18
    }

    Gradient {
        GradientStop { position: 0.0; color: "#FF393939" }
        GradientStop { position: 1.0; color: "#FF222222" }
    }
}
