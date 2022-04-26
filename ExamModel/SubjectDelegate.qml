import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
Rectangle{
    id:r1
    width: w1.width/4
    height:w1.height/5
    color: "lime"
    signal send(var indx);
    signal sendval(string name1);

        Label{
            id:q1
            text: sub
            anchors.centerIn: r1
        }
    MouseArea{
        anchors.fill: parent
        onClicked: {
         console.log("sended");
         var obj=subject.getsub(index);
            send(obj);
            sendval(q1.text);
        }
    }

}
