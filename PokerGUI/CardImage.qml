// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: card

    property real cardSize: 1
    property int currentFrame: 0
    property int framesCountX: 14
    property int framesCountY: 6

    width: 84 * cardSize
    height: 118 * cardSize
    color: "transparent"

    Item{
        id: cardBody

        anchors.centerIn: parent
        clip: true
        width: cardImage.width / framesCountX
        height: cardImage.height / framesCountY

        Image{
            id: cardImage

            source: "cards.png"
            width: cardSize * sourceSize.width
            height: cardSize * sourceSize.height
            smooth: true
            x: -cardImage.width * getFrameX() / framesCountX
            y: -cardImage.height * getFrameY() / framesCountY
        }
    }

    /*Timer{
        id: cardTimer

        interval: 500
        running: true
        repeat: true
        onTriggered: currentFrame++
    }*/

    function getFrameCount() {
        return framesCountX * framesCountY
    }

    function getCurrentFrame() {
        return currentFrame % getFrameCount()
    }

    function getFrameX() {
        return getCurrentFrame() % framesCountX
    }

    function getFrameY() {
        return Math.floor(getCurrentFrame() / framesCountX)
    }
}
