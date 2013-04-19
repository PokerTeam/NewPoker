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

    Button {
        id: buttonCheck
        objectName: "buttonCheck"

        height: 32
        x: buttonRaise.x + buttonRaise.width + 10
        y: parent.height - height - 8
        label: "Check"
        labelColor: "#FFB0B0B0"
        gradientColorTop: "#A0101010"
        gradientOnHoverColorTop: "#A0303030"
        gradientColorBottom: "#A0000000"
        gradientOnHoverColorBottom: "#A0202020"
        borderSize: 2
    }

    Rectangle {
        id: blockRaiseValue

        width: buttonInc.width + buttonDec.width +
               textRaiseValue.paintedWidth + textBankValue.paintedWidth + 16 * 4
        height: 32
        x: buttonCheck.x + buttonCheck.width + 30
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
            objectName: "buttonDecObj"

            anchors.left: parent.left
            anchors.top: parent.top
            width: 36
            height: 32
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
            objectName: "textRaiseValueObj"

            property string raiseValue: "1024"

            anchors.left: buttonDec.right
            anchors.leftMargin: 16
            anchors.top: parent.top
            anchors.topMargin: (parent.height - paintedHeight) * 0.5
            width: paintedWidth
            height: 0
            text: raiseValue
            color: "#FFB0B0B0"
            font.bold: true
            font.family: "Sagoe UI"
            font.pointSize: 11
        }

        Button {
            id: buttonInc
            objectName: "buttonIncObj"

            anchors.left: textRaiseValue.right
            anchors.leftMargin: 16
            anchors.top: parent.top
            width: 36
            height: 32            
            label: "+"
            labelSize: 12
            labelColor: "#FFB0B0B0"
            gradientColorTop: "#A0101010"
            gradientOnHoverColorTop: "#A0303030"
            gradientColorBottom: "#A0000000"
            gradientOnHoverColorBottom: "#A0202020"
            borderSize: 2
        }

        Text {
            id: textBankValue
            objectName: "textBankValueObj"

            property string bankValue: "60"

            anchors.left: buttonInc.right
            anchors.leftMargin: 16
            anchors.top: parent.top
            anchors.topMargin: (parent.height - paintedHeight) * 0.5
            width: paintedWidth
            height: 0
            text: "Bank: " + bankValue
            color: "#FFB0B0B0"
            font.bold: true
            font.family: "Sagoe UI"
            font.pointSize: 11
        }
    }

    CardImage {
        id: cardImage1User3
        objectName: "cardImage1User3"

        cardSize: 0.75
        anchors.top: user3.bottom
        anchors.topMargin: 6
        anchors.right: user3.right
        anchors.rightMargin: 40
    }

    CardImage {
        id: cardImage2User3
        objectName: "cardImage2User3"

        cardSize: 0.75
        anchors.top: user3.bottom
        anchors.topMargin: 6
        anchors.right: user3.right
        anchors.rightMargin: 10
    }

    UserBlock {
        id: user3
        objectName: "user3"

        anchors.top: parent.top
        anchors.topMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 6
        ublockWidth: 260
        ublockHeight: 64
        labelSize: 12        
    }

    CardImage {
        id: cardImage1User2
        objectName: "cardImage1User2"

        cardSize: 0.75
        anchors.top: user2.bottom
        anchors.topMargin: 6
        anchors.right: user2.right
        anchors.rightMargin: 40
    }

    CardImage {
        id: cardImage2User2
        objectName: "cardImage2User2"

        cardSize: 0.75
        anchors.top: user2.bottom
        anchors.topMargin: 6
        anchors.right: user2.right
        anchors.rightMargin: 10
    }

    UserBlock {
        id: user2
        objectName: "user2"

        anchors.top: parent.top
        anchors.topMargin: 6
        anchors.right: user3.left
        anchors.rightMargin: 12
        ublockWidth: 260
        ublockHeight: 64
        labelSize: 12
    }   

    CardImage {
        id: cardImage1User1
        objectName: "cardImage1User1"

        cardSize: 0.75
        anchors.top: user1.bottom
        anchors.topMargin: 6
        anchors.right: user1.right
        anchors.rightMargin: 40
    }

    CardImage {
        id: cardImage2User1
        objectName: "cardImage2User1"

        cardSize: 0.75
        anchors.top: user1.bottom
        anchors.topMargin: 6
        anchors.right: user1.right
        anchors.rightMargin: 10
    }

    UserBlock {
        id: user1
        objectName: "user1"

        anchors.top: parent.top
        anchors.topMargin: 6
        anchors.right: user2.left
        anchors.rightMargin: 12
        ublockWidth: 260
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
        anchors.leftMargin: -260 - 6
        ublockWidth: 260
        ublockHeight: 60
        labelSize: 12
        userAvaImage: 4
        failedUser: false
        gradientColorTop: "#FB101010"
        gradientOnActiveColorTop: "#FB303030"
        gradientOnFailColorTop: "#FB303040"
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
