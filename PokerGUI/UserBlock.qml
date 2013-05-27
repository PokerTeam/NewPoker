import QtQuick 1.1

Rectangle {
    id: urer

    property int ublockWidth: 120
    property int ublockHeight: 32
    property int borderSize: 3
    property int animationDuration: 120

    property color gradientColorTop: "#F2151515"
    property color gradientOnActiveColorTop: "#F2361616"
    property color gradientOnFailColorTop: "#F2202036"
    property color gradientColorBottom: "#F2000000"
    property color gradientOnActiveColorBottom: "#F2161616"
    property color gradientOnFailColorBottom: "#F2101018"
    property color borderColor: "#B0FFFFFF"
    property color borderOnActiveColor: "#F0FF2020"
    property color borderOnFailColor: "#F0365080"

    property color labelColor: "#FFFFFFFF"
    property bool labelBold: true
    property bool labelItalic: false
    property string labelFontFamily: "Segoe UI"
    property string labelUsername: "Username"
    property string labelUsercash: "empty"
    property real labelSize: 10

    property bool activeUser: false
    property bool failedUser: true
    property bool selfUser: false
    property int userAvaImage: 0
    property real cardsSize: 1
    property int card1: 42
    property int card2: 43

    width: ublockWidth
    height: ublockHeight
    color: "#00000000"

    CardImage {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 10 + 28 * cardsSize

        currentFrame: card1
        cardSize: cardsSize
    }

    CardImage {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 10

        currentFrame: card2
        cardSize: cardsSize
    }

    Rectangle {
        radius: (selfUser) ? 8 : 0
        anchors.fill: parent
        smooth: true
        clip: true
        border {
            width: (selfUser) ? (borderSize * 2) : (!activeUser) ? borderSize : 2;
            Behavior on color { ColorAnimation { duration: animationDuration } }
            color: (!activeUser) ?
                       ((!failedUser) ? borderColor : borderOnFailColor) :
                       borderOnActiveColor }
        gradient: Gradient {
            GradientStop { position: 0.0;
                Behavior on color { ColorAnimation { duration: animationDuration } }
                color: (!activeUser) ?
                           ((!failedUser) ? gradientColorTop : gradientOnFailColorTop) :
                           gradientOnActiveColorTop }
            GradientStop { position: 1.0;
                Behavior on color { ColorAnimation { duration: animationDuration } }
                color: (!activeUser) ?
                           ((!failedUser) ? gradientColorBottom : gradientOnFailColorBottom) :
                           gradientOnActiveColorBottom }
        }

        AnimatedImage{
            id: userAva

            source: getAvaSource(userAvaImage)
            width: ublockHeight - 2 * borderSize
            height: ublockHeight - 2 * borderSize
            smooth: true
            playing: true
            anchors.left: parent.left
            anchors.leftMargin: borderSize
            anchors.top: parent.top
            anchors.topMargin: borderSize
        }

        Text {
            id: userLabel

            text: labelUsername + "\n" + labelUsercash
            color: labelColor
            anchors.left: userAva.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: (parent.height - paintedHeight) / 2
            font.pointSize: labelSize
            font.bold: labelBold
            font.italic: labelItalic
            font.family: labelFontFamily
        }
    }

    function getAvaSource(num) {
        switch (num) {
        case 0:
            return "unknown.jpg"
        case 1:
            return "ava_1.gif";
        case 2:
            return "ava_2.gif"
        case 3:
            return "ava_3.gif"
        case 4:
            return "ava_4.gif"
        default:
            return "ava_5.gif"
        }
    }
}
