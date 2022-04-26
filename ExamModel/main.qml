import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
Window {
    id:w1
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Timer{
        interval: 5000
        running: true
        onTriggered: {
            lv1.enabled=true
        }
    }
    RowLayout{
        id:rl1
        spacing: 5
        ListView{
            id:lv1
            anchors.left: w1.left
            spacing :5
            width: w1.width/4
            height: w1.height
            enabled: false
            model: subject

            delegate:SubjectDelegate{id:sd
                Connections{
                    target:sd
                    onSend:{
                        lv.visible = true
                        lv.model=indx;
                    }
                    onSendval:{
                        lv.str=name1;
                    }
                }
            }
        }
        ListView{
            id:lv
            spacing: 5
            visible: false
            width: w1.width/4
            height: w1.height
            anchors.left: lv1.right
            property  string str;
            delegate: QuestionDelegate{
                id:qd
                onClickMe:{
                    col1.visible=true
                    q2.text=name;
                    rb1.text="A";
                    rb2.text="B";
                    rb3.text="C";
                    rb4.text="D";
                    rb1.checked=false
                    rb2.checked=false
                    rb3.checked=false
                    rb4.checked=false
                    close.visible=false;
                    if(index===29)
                    {
                        close.visible=true;
                    }
                    sub.ind=index;
                }
                Connections{
                    target: qd
                    onClickMe:{
                        r1.visible = true
                    }
                }
            }
        }

        Rectangle{
            id:r1
            visible: false
            width:w1.width/2
            height: w1.height
            color: "gray"
            anchors.left: lv.right
            ColumnLayout{
                id:col1
                spacing: 5
                anchors.centerIn: parent
                Label{
                    id:q2
                    scale: 1.5
                    text: "question1"
                    font.pixelSize: 20
                }
                RadioButton{
                    id:rb1
                    text: "A"
                }
                RadioButton{
                    id:rb2
                    text: "B"
                }
                RadioButton{
                    id:rb3
                    text: "C"
                }
                RadioButton{
                    id:rb4
                    text: "D"
                }
                RowLayout{
                    Button{
                        id:sub
                        property  var  ind;
                        text:"submit"
                        onClicked: {
                            rl1.checkMe(ind);
                            console.log("submited");
                        }
                    }
                    Button{
                        id:close
                        text: "Close"
                        font.pixelSize: 15
                        visible: false
                        onClicked: {
                            rl1.close();
                            r1.visible=false
                        }
                    }
                }

            }
        }

        function checkMe(value)
        {
            if(rb1.checked==true)
            {
                lv.model.submit(value,"A");
            }
            if(rb2.checked==true)
            {
                lv.model.submit(value,"B");
            }
            if(rb3.checked==true)
            {
                lv.model.submit(value,"C");
            }
            if(rb4.checked==true)
            {
                lv.model.submit(value,"D")
            }
        }
        function close()
        {
            var r=lv.model.rightAns();
            var w=lv.model.wrongAns();
            t1.text="RightAnswer  "+r
            t2.text="wrongAnswer  "+w
            complete.visible=true
            col1.visible=false
            lv1.visible=false

        }
    }
    Summary{
        id:complete
        visible: false
        ColumnLayout{
            spacing: 10
            anchors.centerIn: parent
            Text {
                id:t1
                font.pixelSize: 15
            }
            Text {
                id:t2
                font.pixelSize: 15
            }
        }
    }
}



