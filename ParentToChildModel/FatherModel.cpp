#include "FatherModel.h"
#include"QList"
int f=1;
int count1=1;
FatherModel::FatherModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
    f++;
    count1++;

}
int FatherModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_father.size();
}

QVariant FatherModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row=index.row();
    ChildModel *cmodel=m_father.at(row);
    switch (role)
    {
    case 1:return cmodel->fathername();

    }
    return 0;
}

QHash<int, QByteArray> FatherModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int,QByteArray> roles;
    roles[1]="fathername";
    return roles;
}

ChildModel *FatherModel::getfather(int index)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    ChildModel *obj1=m_father.at(index);
    return obj1;

}
void FatherModel::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(count1==1)
    {
        for(int i=1;i<4;i++)
        {

            ChildModel *cm=new ChildModel;
            cm->setFathername("father"+QString::number(f)+"."+QString::number(i));
            m_father.append(cm);
        }
    }
    if(count1==2)
    {
        for(int i=1;i<3;i++)
        {
            ChildModel *cm1=new ChildModel;
            cm1->setFathername("father"+QString::number(f)+"."+QString::number(i));
            m_father.append(cm1);
        }
    }
    if(count1==3)
    {
        ChildModel *cm2=new ChildModel;
        cm2->setFathername("father"+QString::number(f)+"."+QString::number(1));
        m_father.append(cm2);
    }

}

const QString &FatherModel::gfname() const
{
    return m_gfname;
}

void FatherModel::setGfname(const QString &newFname)
{
    m_gfname = newFname;
}
