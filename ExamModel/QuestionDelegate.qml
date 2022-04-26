import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
Rectangle {
    width: w1.width/4
    height: w1.height/5
    color: "green"
    signal clickMe(string name);
    RowLayout{
        id:rl
        spacing:5
        anchors.fill: parent
        Label{
            anchors.centerIn: parent
            id:q1
            text:lv.str + "Question "+index
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log("clicked");
            clickMe(q1.text);
        }
    }


}
