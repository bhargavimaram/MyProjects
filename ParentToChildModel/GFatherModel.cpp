#include "GFatherModel.h"

GFatherModel::GFatherModel(QObject *parent)
    : QAbstractItemModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}

int GFatherModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_gfather.size();
}
QVariant GFatherModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row=index.row();
    FatherModel *f=m_gfather.at(row);
    switch (role)
    {
    case 1:return f->fname();

    }
    return 0;
}

QHash<int, QByteArray> GFatherModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    QHash<int,QByteArray> roles;
    roles[1]="gfather";
    return roles;
}

FatherModel *GFatherModel::getfather(int index)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    FatherModel *obj1=m_gfather.at(index);
    return obj1;
}

void GFatherModel::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    for(int i=0;i<3;i++)
    {
        FatherModel *fm=new FatherModel;
        fm->setFname("Father"+QString::number(i));
    }
}
