#include "Weather.h"

Weather::Weather(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<endl;

}

const QString &Weather::temperature() const
{
    return m_temperature;
}

void Weather::setTemperature(const QString &newTemperature)
{
    m_temperature = newTemperature;
}

const QString &Weather::climate() const
{
    return m_climate;
}

void Weather::setClimate(const QString &newClimate)
{
    m_climate = newClimate;
}

const QString &Weather::time() const
{
    return m_time;
}

void Weather::setTime(const QString &newTime)
{
    m_time = newTime;
}

const QString &Weather::image() const
{
    return m_image;
}

void Weather::setImage(const QString &newImage)
{
    m_image = newImage;
}
