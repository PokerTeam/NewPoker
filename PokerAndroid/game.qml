import QtQuick 1.1

Rectangle {
    id: gameScreen

    property int gameScreenWidth: 1024
    property int gameScreenHeight: 560

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
        borderSize: 2
    }

    Rectangle {
        id: blockRaiseValue

        width: buttonInc.width + buttonDec.width +
               textRaiseValue.paintedWidth + 16 * 2
        height: 32
        x: buttonCheck.x + buttonCheck.width + 30
        y: parent.height - height - 8
        color: "#80101010"
        border {
            width: 2;
            color: "#20FFFFFF"
        }
        radius: 2
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
            font.pointSize: 6
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
            borderSize: 2
        }        
    }    

    UserBlock {
        id: user1
        objectName: "user1"

        x: parent.width * 0.35 - width * 0.5
        y: 80 - height * 0.5

        ublockWidth: 160
        ublockHeight: 40
        cardsSize: 0.7
        labelSize: 5
    }   

    UserBlock {
        id: user2
        objectName: "user2"

        x: parent.width * 0.65 - width * 0.5
        y: 80 - height * 0.5

        ublockWidth: 160
        ublockHeight: 40
        cardsSize: 0.7
        labelSize: 5
    }   

    UserBlock {
        id: user3
        objectName: "user3"

        x: parent.width * 0.9 - width * 0.5
        y: parent.height * 0.35 - height * 0.5

        ublockWidth: 160
        ublockHeight: 40
        cardsSize: 0.7
        labelSize: 5
    }       

    UserBlock {
        id: user4
        objectName: "user4"

        x: parent.width * 0.9 - width * 0.5
        y: parent.height * 0.65 - height * 0.5

        ublockWidth: 160
        ublockHeight: 40
        cardsSize: 0.7
        labelSize: 5
    }

    UserBlock {
        id: user5
        objectName: "user5"

        x: parent.width * 0.65 - width * 0.5
        y: parent.height - 100 - height * 0.5

        ublockWidth: 160
        ublockHeight: 40
        cardsSize: 0.7
        labelSize: 5
    }

    UserBlock {
        id: user6
        objectName: "user6"

        x: parent.width * 0.35 - width * 0.5
        y: parent.height - 100 - height * 0.5

        ublockWidth: 160
        ublockHeight: 40
        cardsSize: 0.7
        labelSize: 5
    }

    UserBlock {
        id: user7
        objectName: "user7"

        x: parent.width * 0.1 - width * 0.5
        y: parent.height * 0.65 - height * 0.5

        ublockWidth: 160
        ublockHeight: 40
        cardsSize: 0.7
        labelSize: 5
    }

    UserBlock {
        id: user8
        objectName: "user8"

        x: parent.width * 0.1 - width * 0.5
        y: parent.height * 0.35 - height * 0.5

        ublockWidth: 160
        ublockHeight: 40
        cardsSize: 0.7
        labelSize: 5
    }

    CardImage {
        id: card1
        objectName: "card1"

        x: parent.width * 0.5 - width - getCard1Position()
        y: (parent.height - height * 1.4) * 0.5
    }

    CardImage {
        id: card2
        objectName: "card2"

        x: parent.width * 0.5 - width - getCard2Position()
        y: (parent.height - height * 1.4) * 0.5
    }

    CardImage {
        id: card3
        objectName: "card3"

        x: parent.width * 0.5 + getCard3Position()
        y: (parent.height - height * 1.4) * 0.5
    }

    CardImage {
        id: card4
        objectName: "card4"

        currentFrame: 83

        x: parent.width * 0.5 + getCard4Position()
        y: (parent.height - height * 1.4) * 0.5
    }

    CardImage {
        id: card5
        objectName: "card5"

        currentFrame: 83

        x: parent.width * 0.5 + getCard5Position()
        y: (parent.height - height * 1.4) * 0.5
    }

    Rectangle {
        id: blockBankValue

        width: textBankValue.paintedWidth + 16 * 2
        height: 32
        x: (parent.width - width) * 0.5
        y: parent.height * 0.5 + card1.height * 0.65 - height * 0.5
        color: "#80101010"
        border {
            width: 2;
            color: "#80000000"
        }
        radius: 2
        smooth: true

        Text {
            id: textBankValue
            objectName: "textBankValueObj"

            property string bankValue: "60"

            anchors.left: parent.left
            anchors.leftMargin: 16
            anchors.top: parent.top
            anchors.topMargin: (parent.height - paintedHeight) * 0.5
            width: paintedWidth
            height: 0
            text: "Bank: " + bankValue
            color: "#FFB0B0B0"
            font.bold: true
            font.family: "Sagoe UI"
            font.pointSize: 6
        }
    }

    Gradient {
        GradientStop { position: 0.0; color: "#FF393939" }
        GradientStop { position: 1.0; color: "#FF222222" }
    }

    function getCardsCount() {
        var count = 3
        if (card4.currentFrame != 83)
            ++count
        if (card5.currentFrame != 83)
            ++count
        return count
    }

    function getCard1Position() {
        switch (getCardsCount())
        {
        case 3: return card2.width * 0.5 + 18
        case 4: return card2.width + 18  + 18 * 0.5
        case 5: return card3.width * 0.5 + card2.width + 18 + 18
        default: return 0
        }
    }

    function getCard2Position() {
        switch (getCardsCount())
        {
        case 3: return -card2.width * 0.5
        case 4: return 18 * 0.5
        case 5: return card3.width * 0.5 + 18
        default: return 0
        }
    }

    function getCard3Position() {
        switch (getCardsCount())
        {
        case 3: return card2.width * 0.5 + 18
        case 4: return 18 * 0.5
        case 5: return -card3.width * 0.5
        default: return 0
        }
    }

    function getCard4Position() {
        switch (getCardsCount())
        {
        case 3: return 0
        case 4: return card3.width + 18  + 18 * 0.5
        case 5: return card3.width * 0.5 + 18
        default: return 0
        }
    }

    function getCard5Position() {
        switch (getCardsCount())
        {
        case 3: return 0
        case 4: return 0
        case 5: return card3.width * 0.5 + card4.width + 18 + 18
        default: return 0
        }
    }
}
