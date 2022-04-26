#ifndef SUBJECTMODEL_H
#define SUBJECTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include<QuestionModel.h>

class SubjectModel : public QAbstractListModel
{
    Q_OBJECT

    void init();
public:
    explicit SubjectModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &index)const override;
    Q_INVOKABLE QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const override;
    Q_INVOKABLE QuestionModel* getsub(int index);



private:
    QList<QuestionModel*> m_sub;
};

#endif // SUBJECTMODEL_H
