import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
Rectangle {
    id:rect2
    width:  window.width/5
    height: window.heigh/6
    color: "aqua";
    ColumnLayout{
        Label{
            text: name
            font.pixelSize: 20
            Layout.alignment: Qt.AlignHCenter
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log("clicked");
        }
    }


}

