import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
Rectangle {
    id:rect2
    width: w1.width/7
    height: w1.height/6
    color: "aqua"
    signal sendimg();
    ColumnLayout{
        Label{
            id:l1
            text: time
            font.pixelSize: 20
            Layout.alignment: Qt.AlignHCenter
        }
        Label{
            id:l2
            text: temparature
            font.pixelSize: 20
            Layout.alignment: Qt.AlignHCenter
        }
        Label{
            id:l3
            text: climate
            font.pixelSize: 20
            Layout.alignment: Qt.AlignHCenter
        }

        Image {
            id: img
            source: climate_image
            scale: 0.5
            Layout.preferredWidth: 100
            Layout.preferredHeight: 100
        }
    }


    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log("clicked");
           sendimg();

        }
    }

}
