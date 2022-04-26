#include "Movie.h"
Movie::Movie(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
    updateData();
    t=new QTimer;
    t->setInterval(5000);
    QObject::connect(t,&QTimer::timeout,this,&Movie::updateData);
    t->start();
}
void Movie::updateData()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(c>=10){
        t->stop();
        return;
    }
    callMe(c);
    c++;
}
MyStruct Movie::getMyStruct() const
{
    return mystr;
}

void Movie::setMyStruct(MyStruct val)
{
    mystr = val;
}
void Movie::init()
{
    for(count=1;count<=10;count++)
    {
        if(count==1)
        {
            mystr.m_moviename="KGF2";
            mystr.m_movieActor="Yash";
            mystr.m_movierating=15;
            mystr.m_movieCollection=1206;
            m_movielist.append(mystr);
        }
        else if(count==2)
        {
            mystr.m_moviename="Pushpa";
            mystr.m_movieActor="AlluArjun";
            mystr.m_movierating=5;
            mystr.m_movieCollection=987;
            m_movielist.append(mystr);
        }
        else if(count==3)
        {
            mystr.m_moviename="RRR";
            mystr.m_movieActor="Ntr";
            mystr.m_movierating=4.5;
            mystr.m_movieCollection=876;
            m_movielist.append(mystr);
        }
        else if(count==4)
        {
            mystr.m_moviename="Beemlanayak";
            mystr.m_movieActor="Pawankalyan";
            mystr.m_movierating=4;
            mystr.m_movieCollection=567;
            m_movielist.append(mystr);
        }
       else if(count==5)
        {
            mystr.m_moviename="James";
            mystr.m_movieActor="PuneethRajKumar";
            mystr.m_movierating=5;
            mystr.m_movieCollection=567;
            m_movielist.append(mystr);

        }
        else if(count==6)
        {
            mystr.m_moviename="KGF1";
            mystr.m_movieActor="yash";
            mystr.m_movierating=10.5;
            mystr.m_movieCollection=7651;
            m_movielist.append(mystr);
        }
       else if(count==7)
        {
            mystr.m_moviename="Akanda";
            mystr.m_movieActor="Balakrishna";
            mystr.m_movierating=4.5;
            mystr.m_movieCollection=876;
            m_movielist.append(mystr);
        }
        else if(count==8)
        {
            mystr.m_moviename="Bahubali1";
            mystr.m_movieActor="Prabhas";
            mystr.m_movierating=4.5;
            mystr.m_movieCollection=456;
            m_movielist.append(mystr);
        }
        else if(count==9)
        {
            mystr.m_moviename="Alavikuntapuramulo";
            mystr.m_movieActor="Alluarjun";
            mystr.m_movierating=5;
            mystr.m_movieCollection=987;
            m_movielist.append(mystr);

        }
        else if(count==10)
        {
            mystr.m_moviename="Bahubali2";
            mystr.m_movieActor="Prabhas";
            mystr.m_movierating=5;
            mystr.m_movieCollection=567;
            m_movielist.append(mystr);
        }

    }
    qDebug()<<"size ="<<m_movielist.size();
}

MyStruct Movie::callMe(int indx)
{
    qDebug()<<Q_FUNC_INFO<<"Value : "<<indx<<Qt::endl;


        mystr =  m_movielist.at(indx);
        qDebug()<<"********** "<<Qt::endl;
        emit myStructChanged(mystr);
        qDebug()<<"~~~~signal emitted~~~~"<<Qt::endl;
        return mystr;
}


