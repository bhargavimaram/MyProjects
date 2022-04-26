#include "GrandFatherModel.h"

GrandFatherModel::GrandFatherModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}
int GrandFatherModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_father.size();
}
QVariant GrandFatherModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row=index.row();
    FatherModel *f=m_father.at(row);
    switch (role)
    {
//    case 1:return f.

    }
    return 0;

}

QHash<int, QByteArray> GrandFatherModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    QHash<int,QByteArray> roles;
    roles[1]="gfather";
    return roles;
}

FatherModel *GrandFatherModel::getfather(int index)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    FatherModel *obj1=m_father.at(index);
    return obj1;

}

void GrandFatherModel::init()
{

}
