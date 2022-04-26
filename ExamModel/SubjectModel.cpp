#include "SubjectModel.h"
#include<QDebug>
SubjectModel::SubjectModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}

int SubjectModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_sub.size();
}

QVariant SubjectModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row =index.row();
    QuestionModel *q=m_sub.at(row);
    switch(role)
    {
    case 1:return q->subjectname();
    }
}

QHash<int, QByteArray> SubjectModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;

    QHash<int,QByteArray> roles;
    roles[1]="sub";

    return roles;
}

QuestionModel *SubjectModel::getsub(int index)
{
        qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QuestionModel *obj1=m_sub.at(index);
    return obj1;
}

void SubjectModel::init()
{
    qDebug()<<Q_FUNC_INFO<<"init function called"<<Qt::endl;
    for(int i=0 ; i<6;i++){
        QuestionModel *qm=new QuestionModel;
        if(i==0)
            qm->setSubjectname("maths");
        if(i==1)
            qm->setSubjectname("social");
        if(i==2)
            qm->setSubjectname("science");
        if(i==3)
            qm->setSubjectname("english");
        if(i==4)
            qm->setSubjectname("hindi");
        if(i==5)
            qm->setSubjectname("telugu");

        m_sub.append(qm);

    }
}
