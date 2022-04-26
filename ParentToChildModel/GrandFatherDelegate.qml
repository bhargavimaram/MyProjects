import QtQuick 2.0
import QtQuick.Controls 2.5
Rectangle{
    id:rect1
    width: window.width/2
    height: window.height/8
    color: "aqua"
   signal send();
 Label{
     id:g1
     text: grandfather
     font.pixelSize: 20
     anchors.centerIn: parent

 }
 MouseArea{
     anchors.fill: parent
     onClicked: {
         console.log("Clicked");
         send();
     }
 }

}
