import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
Rectangle {
    id:rect1
    color: "green"
    width:  window.width/5
    height: window.heigh/6
    Label{
        id:l1
        text: name
        font.pixelSize: 20
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log("clicked");
        }
    }
}


