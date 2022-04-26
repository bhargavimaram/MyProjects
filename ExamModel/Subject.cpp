#include "Subject.h"
#include<QDebug>
Subject::Subject(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<endl;

}

const QString &Subject::getId() const
{
    return id;
}

void Subject::setId(const QString &newId)
{
    id = newId;
}

const QString &Subject::getName() const
{
    return name;
}

void Subject::setName(const QString &newName)
{
    name = newName;
}
