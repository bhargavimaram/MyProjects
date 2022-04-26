#include "Child.h"

Child::Child(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;

}

const QString &Child::name() const
{
    return m_name;
}

void Child::setName(const QString &newName)
{
    m_name = newName;
}
