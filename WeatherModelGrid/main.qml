import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Window {
    id:w1
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "aqua"
    GridView{
        id:lv1
        anchors.fill: parent
        cellWidth: w1.width/3
        cellHeight: w1.height/6
        model: cityMod
        delegate: CityDelegate{
            id:cd
            onSend:{
                lv.str=cityMod.getCity(index);
                rect2.val=lv.model.getWeather(new Date().getHours()).temparature
                popup.open();
                lv2.value=index;
            }
        }

        Popup {
            id: popup
            width: parent.width
            height: parent.height
            modal: true
            focus: true
            background: Rectangle{
                id:rect3
                color: "aqua"
            }
            ListView{
                id:lv
                property var str;
                width: w1.width
                height: w1.height
                anchors.top: rect2.bottom
                anchors.topMargin: parent.height/5
                model:str
                delegate: WeatherDelegate{
                      id:wd
                    onSendimg:{
                        rect2.val=lv.model.getWeather(index).temparature
                        rect2.img11=lv.model. getWeather(index).image

                   }

                }
                orientation: Qt.Horizontal
            }
            Rectangle{
                id:rect2
                width: 100
                height: 100
                color: "aqua"
                anchors.horizontalCenter: parent.horizontalCenter
                property var val;
                property var img11;

                Text {
                    id: t1
                    text:rect2.val
                    font.pixelSize: 50
                }

                Image {
                    id: img2
                    source:rect2.img11
                    width: 70
                    height: 70
                    anchors.top: t1.bottom

                }
            }
            ListView{
                id:lv2
                property  int value;
                anchors.fill: parent
                width: w1.width/4
                height: w1.height/8
                anchors.top: lv.bottom
                anchors.topMargin:w1.height/1.2
                currentIndex: value
                model: cityMod
                delegate:CityDelegate{
                    id:cd1
                }
                orientation: Qt.Horizontal
                preferredHighlightBegin:250
                preferredHighlightEnd:250
                highlightRangeMode :ListView.StrictlyEnforceRange
                highlightFollowsCurrentItem: true
                onCurrentIndexChanged:{
                    lv.model=cityMod.getCity(currentIndex);
                }

                highlight: Rectangle {
                    color: "gray"
                    radius: 5
                    opacity: 0.7
                }
                focus:true
            }
            Image {
                id: img1
                source: "Close.jfif"
                width: 30
                height: 30
                anchors.right: parent.right
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        popup.close();
                    }
                }
            }
        }
    }
}






