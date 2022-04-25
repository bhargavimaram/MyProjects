#include "WeatherModel.h"

WeatherModel::WeatherModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<endl;
    init();

}

int WeatherModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_weather.size();

}

QVariant WeatherModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<endl;

    int row=index.row();
    Weather *wr=m_weather.at(row);
    switch(role)
    {
    case 1:return wr->temperature();
//        break;
    case 2:return wr->climate();
//        break;
    case 3:return wr->time();
//        break;
    case 4: return wr->image();
    }

    return "iugfc";

}

QHash<int, QByteArray> WeatherModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    QHash<int,QByteArray> roles;
    roles[1]="temparature";
    roles[2]="climate";
    roles[3]="time";
    roles[4] = "climate_image";
    return roles;
}

void WeatherModel::init()
{
    qDebug()<<Q_FUNC_INFO<<endl;

    for(int i=1;i<=24;i++)
    {
        Weather *w=new Weather;
        if(i<5)
        {
            w->setTemperature(QString::number(10+i)+"°C");
            w->setClimate("Rain");
            w->setTime(QString::number(i)+"am");
            w->setImage("qrc:/Rain.jpg");
        }
        if(i>=5 && i<15)
        {
            w->setTemperature(QString::number(15+i)+"°C");
            w->setClimate("Sun");
            w->setTime(QString::number(i)+"am");
            w->setImage("qrc:/Sun.jpg");
        }
        if(i>=15 && i<=24)
        {
            w->setTemperature(QString::number(i)+"°C");
            w->setClimate("Cloud");
            w->setTime(QString::number(i)+"am");
            w->setImage("qrc:/Cloud.png");
        }
        m_weather.append(w);
        qDebug()<<Q_FUNC_INFO<<"size="<<m_weather.size()<<endl;

    }
}

Weather* WeatherModel::getWeather(int index)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    int row=index;
    Weather *obj=m_weather.at(index);
    return obj;

}

const QString &WeatherModel::cityname() const
{
    return m_cityname;
}

void WeatherModel::setCityname(const QString &newCityname)
{
    m_cityname = newCityname;
}

