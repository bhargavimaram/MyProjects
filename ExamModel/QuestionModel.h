#ifndef QUESTIONMODEL_H
#define QUESTIONMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include<QList>
#include"Question.h"

class QuestionModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit QuestionModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const;
    void init();
    Q_INVOKABLE QVariant getQuestion(int index);
    Q_INVOKABLE QString submit(int index,QString str);
    Q_INVOKABLE int rightAns() const;


   Q_INVOKABLE int wrongAns() const;

    const QString &subjectname() const;
    void setSubjectname(const QString &newSubjectname);

private:
    QList<Question*> m_questions;
    int m_rightAns=0;
    int m_wrongAns=0;
    QString m_subjectname;

};

#endif // QUESTIONMODEL_H
