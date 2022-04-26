import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    id:window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Component.onCompleted: {
        console.log("Inside the main")
        console.log("obj :"+ myObj.mystr)
    }

    Rectangle {
        id:rect
        width: window.width
        height: window.height
        color: "aqua"
        Column{
            anchors.centerIn: parent
            spacing: 10
            Row{
                spacing: 10
                Text {
                    id: mn
                    text: "Movie Name"
                    font.pixelSize: 20
                }
                Rectangle{
                    id:rect1
                    width: 300
                    height: 50
                    color: "white"
                    border.color: "green"
                    border.width: 2
                    Text {
                        id: t1
                        text:myObj.mystr.moviename;
                        font.pixelSize: 20
                          anchors.centerIn: parent
                    }
                }
            }
            Row{
                spacing: 15
                Text {
                    id: an
                    text: "Actor Name"
                    font.pixelSize: 20
                }
                Rectangle{
                    id:rect2
                    width: 300
                    height: 50
                    color: "white"
                    border.color: "green"
                    border.width: 2
                    Text {
                        id: t2
                        text:myObj.mystr.movieactor;
                         font.pixelSize: 20
                           anchors.centerIn: parent
                    }

                }
            }
            Row{
                spacing: 60
                Text {
                    id: r1
                    text: "Rating"
                    font.pixelSize: 20;
                }
                Rectangle{
                    id:rect3
                    width: 300
                    height: 50
                    color: "white"
                    border.color: "green"
                    border.width: 2
                    Text {
                        id: t3
                        text:myObj.mystr.movierating;
                         font.pixelSize: 20
                           anchors.centerIn: parent
                    }
                }
            }
            Row{
                spacing: 30
                Text {
                    id: c1
                    text: "Collection"
                    font.pixelSize: 20
                }
                Rectangle{
                    id:rect4
                    width: 300
                    height: 50
                    color: "white"
                    border.color: "green"
                    border.width: 2

                   Text {
                        id: t4
                        text:myObj.mystr.movieCollection;
                         font.pixelSize: 20
                         anchors.centerIn: parent

                    }

                }
            }
        }
        Connections{
            target:myObj
            function onMyStructChanged(){
                console.log("signal caught")
                t1.text=myObj.mystr.moviename;
                t2.text=myObj.mystr.movieactor;
                t3.text=myObj.mystr.movierating;
                t4.text=myObj.mystr.movieCollection;
            }

        }

    }
}
