import QtQuick 2.0
import QtQuick.Controls 2.5
Rectangle {
    id:rect2
    width: window.width/4
    height: window.height/7
    color: "aqua"
    signal click();
    Label{
        text: fathername
        font.pixelSize: 20
        anchors.centerIn: rect2
       }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log("clicked");
            click();
        }
    }

}
