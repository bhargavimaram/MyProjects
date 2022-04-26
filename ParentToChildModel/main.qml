import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3

Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    ColumnLayout{
        id:c1
        spacing: 2
        ListView{
            id:lv1
            spacing:2
            width: window.width
            height: window.height/3
            model:Grandf
            delegate: GrandFatherDelegate{
                id:d1
                onSend: {
                    lv2.visible=true
                    lv2.model=Grandf.getgrandf(index);
//                    if(index==1)
//                    {
//                        lv2.visible=true;
//                    }
//                    if(count==1)
//                    {
//                        lv2.visible=false
//                    }
                }
            }
            orientation: Qt.Horizontal
        }
        ListView{
            id:lv2
            visible: false
            property var str;
            spacing: 10
            width: window.width
            height: window.height/4
            delegate: FatherDelegate{
                id:d2
                onClick: {
                  lv3.str1=lv2.model.getfather(index);
                }
            }
            orientation: Qt.Horizontal
        }
        ListView{
            id:lv3
            property var str1;
            spacing: 30
            width: window.width
            height: window.height/4
            model: str1
            delegate: ChildDelegate{}
            orientation: Qt.Horizontal
        }

    }
}

