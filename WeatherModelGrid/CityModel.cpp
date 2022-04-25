#include "CityModel.h"

CityModel::CityModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<endl;
    init();
}

int CityModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_city.size();
}

QVariant CityModel::data(const QModelIndex &index, int role) const
{

     qDebug()<<Q_FUNC_INFO<<endl;
     int row=index.row();
     WeatherModel *wm=m_city.at(row);
     switch (role)
     {
     case 1:return wm->cityname();
     }
     return "gfcvb";

}

QHash<int, QByteArray> CityModel::roleNames() const
{
     qDebug()<<Q_FUNC_INFO<<endl;
    QHash<int,QByteArray> roles;
    roles[1]="city";
    return roles;
}

WeatherModel *CityModel::getCity(int index)
{
    qDebug()<<Q_FUNC_INFO<<endl;
   WeatherModel *obj1=m_city.at(index);
   return obj1;

}

void CityModel::init()
{
     qDebug()<<Q_FUNC_INFO<<endl;

    for(int i=0;i<10;i++)
    {
        WeatherModel *w=new WeatherModel;
        if(i==0)
        {
            w->setCityname("Banglore");
        }
        else if(i==1)
        {
            w->setCityname("Mysore");
        }
        else if(i==2)
        {
            w->setCityname("Hubli");
        }
        else if(i==3)
        {
            w->setCityname("Davanagere");
        }
        else if(i==4)
        {
            w->setCityname("Bijapur");
        }
        else if(i==5)
        {
            w->setCityname("Madikeri");
        }
        else if(i==6)
        {
            w->setCityname("Kolar");
        }
        else if(i==7)
        {
            w->setCityname("Chikmangalur");
        }
        else if(i==8)
        {
            w->setCityname("Mangalore");
        }
        else if(i==9)
        {
            w->setCityname("Udupi");
        }
         m_city.append(w);
    }


}

