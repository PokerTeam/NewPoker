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
        x: 10
        y: 10
        label: "Exit"
        labelColor: "#FFB0B0B0"
        gradientColorTop: "#80202020"
        gradientOnHoverColorTop: "#A0303030"
        gradientColorBottom: "#80101010"
        gradientOnHoverColorBottom: "#A0202020"
        borderSize: 2
    }

    Button {
        id: buttonFold

        height: 32
        x: 10
        y: parent.height - height * 1.5
        label: "Fold"
        labelColor: "#FFB0B0B0"
        gradientColorTop: "#80202020"
        gradientOnHoverColorTop: "#A0303030"
        gradientColorBottom: "#80101010"
        gradientOnHoverColorBottom: "#A0202020"
        borderSize: 2
    }

    Button {
        id: buttonCall

        height: 32
        x: buttonFold.x + buttonFold.width + 10
        y: parent.height - height * 1.5
        label: "Call"
        labelColor: "#FFB0B0B0"
        gradientColorTop: "#80202020"
        gradientOnHoverColorTop: "#A0303030"
        gradientColorBottom: "#80101010"
        gradientOnHoverColorBottom: "#A0202020"
        borderSize: 2
    }

    Button {
        id: buttonRaise

        height: 32
        x: buttonCall.x + buttonCall.width + 10
        y: parent.height - height * 1.5
        label: "Raise"
        labelColor: "#FFB0B0B0"
        gradientColorTop: "#80202020"
        gradientOnHoverColorTop: "#A0303030"
        gradientColorBottom: "#80101010"
        gradientOnHoverColorBottom: "#A0202020"
        borderSize: 2
    }

    Rectangle {
        id: blockRaiseValue

        width: buttonAdd.width + textRaiseValue.width + buttonDel.width + 20
        height: 32
        x: buttonRaise.x + buttonRaise.width + 30
        y: parent.height - height * 1.5
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
            gradientColorTop: "#80202020"
            gradientOnHoverColorTop: "#A0303030"
            gradientColorBottom: "#80101010"
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
            gradientColorTop: "#80202020"
            gradientOnHoverColorTop: "#A0303030"
            gradientColorBottom: "#80101010"
            gradientOnHoverColorBottom: "#A0202020"
            borderSize: 2
        }
    }

    Gradient {
        GradientStop { position: 0.0; color: "#FF393939" }
        GradientStop { position: 1.0; color: "#FF222222" }
    }
}
