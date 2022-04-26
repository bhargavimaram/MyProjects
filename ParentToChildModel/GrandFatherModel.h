#ifndef GRANDFATHERMODEL_H
#define GRANDFATHERMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include<QDebug>
#include<FatherModel.h>

class GrandFatherModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit GrandFatherModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const;

    Q_INVOKABLE FatherModel* getfather(int index);
    void init();
    const QString &fname() const;
    void setFname(const QString &newGfname);

private:
    QList<FatherModel*> m_father;
    QString m_fname;
};

#endif // GRANDFATHERMODEL_H
