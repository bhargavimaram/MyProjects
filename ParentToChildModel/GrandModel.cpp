#include "GrandModel.h"

GrandModel::GrandModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}

int GrandModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_gfather.size();
}
QVariant GrandModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row=index.row();
    FatherModel *f=m_gfather.at(row);
    switch (role)
    {
    case 1:return f->gfname();

    }
    return 0;
}

QHash<int, QByteArray> GrandModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
   QHash<int,QByteArray> roles;
   roles[1]="grandfather";
   return roles;

}

FatherModel *GrandModel::getgrandf(int index)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
   FatherModel *obj2=m_gfather.at(index);
   return obj2;

}

void GrandModel::init()
{
     qDebug()<<Q_FUNC_INFO<<Qt::endl;
     for(int i=0;i<3;i++)
     {
         FatherModel *fm=new FatherModel;
         if(i==0)
         {
            fm->setGfname("grandfather1");
         }
         else if(i==1)
         {
             fm->setGfname("grandfather2");
         }
         else if(i==2)
         {
             fm->setGfname("grandfather3");
         }
         m_gfather.append(fm);
     }

}
