#include "ChildModel.h"
int j=1;
int k=1;
int count=0;
int c=1;
ChildModel::ChildModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
    k++;
    count++;
    c++;
}
int ChildModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_child.size();
}
QVariant ChildModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row=index.row();
    Child *c=m_child.at(row);
    switch (role)
    {
    case 1:return c->name();
    }
    return 0;
}
QHash<int, QByteArray> ChildModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int,QByteArray> roles;
    roles[1]="name";
    return roles;
}
void ChildModel::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(c==1)
    {

        for(int i=1;i<=3;i++)
        {
            Child *ch=new Child;

            ch->setName("children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            ch->setName("Children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            ch->setName("Children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            m_child.append(ch);
        }
    }
    if(c==2)
    {
        for(int i=1;i<=3;i++)
        {
            Child *ch1=new Child;

            ch1->setName("children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            ch1->setName("Children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            ch1->setName("Children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            m_child.append(ch1);
        }

    }
    if(c==3)
    {
        for(int i=1;i<=3;i++)
        {
            Child *ch2=new Child;
            ch2->setName("children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            ch2->setName("Children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            ch2->setName("Children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            m_child.append(ch2);
        }

    }
    if(c==4)
    {
        for(int i=1;i<=2;i++)
        {
            Child *ch3=new Child;
            ch3->setName("children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            ch3->setName("Children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            m_child.append(ch3);
        }
    }
    if(c==5)
    {
        for(int i=1;i<=2;i++)
        {
            Child *ch4=new Child;

            ch4->setName("children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            ch4->setName("Children "+QString::number(j)+"."+QString::number(k)+QString::number(i));
            m_child.append(ch4);
        }
    }
    if(c==6)
    {
        Child *ch4=new Child;
        ch4->setName("children "+QString::number(j)+"."+QString::number(k)+QString::number(1));
        m_child.append(ch4);
    }

    if(count==2){
        j++;
        k=0;
    }
    if(count==3){
        k=1;
    }
    if(count==4)
    {
        j=3;
        k=0;
    }
}

Child *ChildModel::getchild(int index)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row=index;
    Child *obj=m_child.at(index);
    return obj;
}

const QString &ChildModel::fathername() const
{
    return m_fathername;
}

void ChildModel::setFathername(const QString &newFathername)
{
    m_fathername = newFathername;
}
