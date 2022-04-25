import QtQuick 2.0
import QtQuick.Controls 2.5

Rectangle{
    id:r1
    width: w1.width/4
    height: w1.height/5
    color: "transparent"
    signal send();
    Label{
        id:c1
        text: city
        anchors.centerIn: r1
        font.pixelSize: 20
    }

    //    MouseArea{
    //        anchors.fill: parent
    //        onClicked: {
    //            console.log("Clicked");
    Component.onCompleted: {
        send();

    }
//    Component.onDestruction: {
//        send();
//    }
}
