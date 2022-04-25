#ifndef WEATHERMODEL_H
#define WEATHERMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include<QList>
#include<QDebug>
#include"Weather.h"

class WeatherModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit WeatherModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const;
    void init();
    Q_INVOKABLE Weather* getWeather(int index);

    const QString &cityname() const;
    void setCityname(const QString &newCityname);

private:
    QList<Weather*> m_weather;
    QString m_cityname;
};

#endif // WEATHERMODEL_H
