#include "QuestionModel.h"

QuestionModel::QuestionModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<endl;
    init();

}

int QuestionModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<endl;
   return m_questions.size();
}

QVariant QuestionModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<endl;

    int row=index.row();
    Question *qsn=m_questions.at(row);
    switch(role)
    {
    case 1:return qsn->question();
        break;
    case 2:return qsn->option1();
        break;
    case 3:return qsn->option2();
        break;
    case 4:return qsn->option3();
        break;
    case 5:return qsn->option4();
        break;
    case 6:return qsn->answer();
        break;
    case 7:return qsn->userselect();
        break;
    }
    return "sdfghjk";
}

QHash<int, QByteArray> QuestionModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<endl;

    QHash<int,QByteArray> roles;
    roles[1]="question1";
    roles[2]="A";
    roles[3]="B";
    roles[4]="C";
    roles[5]="D";
    roles[6]="answer";
    roles[7]="userinput";
    return roles;

}

void QuestionModel::init()
{
    qDebug()<<Q_FUNC_INFO<<endl;


    for(int i=0;i<30;i++)
    {

        Question *q=new Question;
        q->setQuestion("question"+QString::number(i));
        if(i<10)
        {
            q->setAnswer("A");
        }
        else if(i<20 && i>10)
        {
            q->setAnswer("D");
        }
        else if(i<25 && i>20)
        {
            q->setAnswer("C");
        }
        else
        {
            q->setAnswer("B");
        }
        q->setOption1("A");
        q->setOption2("B");
        q->setOption3("C");
        q->setOption4("D");
        m_questions.append(q);

//        m_questions.push_back(q);
    }
}
QVariant QuestionModel::getQuestion(int index)
{
      qDebug()<<Q_FUNC_INFO<<endl;

        int row=index;
        Question *obj=m_questions.at(row);
        return obj->question();
}

QString QuestionModel::submit(int index, QString str)
{
    Question *obj1=m_questions.at(index);
    obj1->setUserselect(str);
    int row=index;
    if(m_questions.at(row)->answer().compare(str)==0)
    {
        ++m_rightAns;
    }
    else
    {
        ++m_wrongAns;
    }
    qDebug()<<Q_FUNC_INFO<<"Question="<<index<<"selectAnswre="<<str<<endl;

    return str;
}
int QuestionModel::rightAns() const
{
    return m_rightAns;
}

int QuestionModel::wrongAns() const
{
    return m_wrongAns;
}

const QString &QuestionModel::subjectname() const
{
    return m_subjectname;
}

void QuestionModel::setSubjectname(const QString &newSubjectname)
{
    m_subjectname = newSubjectname;
}



