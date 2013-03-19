// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: urer

    property int ublockWidth: 120
    property int ublockHeight: 32
    property int borderSize: 3
    property int animationDuration: 120

    property color gradientColorTop: "#A0101010"
    property color gradientOnActiveColorTop: "#A0303030"
    property color gradientOnFailColorTop: "#80000030"
    property color gradientColorBottom: "#A0000000"
    property color gradientOnActiveColorBottom: "#A0303030"
    property color gradientOnFailColorBottom: "#80000020"
    property color borderColor: "#80FFFFFF"
    property color borderOnActiveColor: "#A0FF2020"
    property color borderOnFailColor: "#A04040A0"

    property color labelColor: "#FFFFFFFF"
    property bool labelBold: true
    property bool labelItalic: false
    property string labelFontFamily: "Segoe UI"
    property string labelUsername: "Username"
    property string labelUsercash: "empty"
    property real labelSize: 10

    property bool activeUser: false
    property bool failedUser: true
    property int userAvaImage: 0

    width: ublockWidth
    height: ublockHeight
    smooth: true
    clip: true
    border {
        width: (!activeUser) ? borderSize : 2;
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
