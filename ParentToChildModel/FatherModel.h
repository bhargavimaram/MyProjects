#ifndef FATHERMODEL_H
#define FATHERMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include<QList>
#include"ChildModel.h"

class FatherModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit FatherModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const;
    void init();
    Q_INVOKABLE ChildModel* getfather(int index);



    const QString &gfname() const;
    void setGfname(const QString &newFname);

private:
    QList<ChildModel*> m_father;
    QString m_gfname;
    QString last;
};

#endif // FATHERMODEL_H
