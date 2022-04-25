#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include<QDebug>
#include<QString>
#include<WeatherModel.h>
class CityModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CityModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const;

   Q_INVOKABLE WeatherModel* getCity(int index);
    void init();
    const QString &image() const;
    void setImage(const QString &newImage);

private:
    QList<WeatherModel*> m_city;
};

#endif // CITYMODEL_H
