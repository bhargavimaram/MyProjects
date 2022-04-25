#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include<QString>
#include<QDebug>

class Weather : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString temparature READ temperature);
    Q_PROPERTY(QString image READ image WRITE setImage);
public:
    explicit Weather(QObject *parent = nullptr);

    const QString &temperature() const;
    void setTemperature(const QString &newTemperature);

    const QString &climate() const;
    void setClimate(const QString &newClimate);

    const QString &time() const;
    void setTime(const QString &newTime);

    const QString &image() const;
    void setImage(const QString &newImage);


signals:
private:
    QString m_temperature;
    QString m_climate;
    QString m_time;
    QString m_image;

};

#endif // WEATHER_H
