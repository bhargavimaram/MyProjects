#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include<QString>

class Subject : public QObject
{
    Q_OBJECT
public:
    explicit Subject(QObject *parent = nullptr);
    Q_PROPERTY(QString id READ id);
    Q_PROPERTY(QString name READ name);

    const QString &getId() const;
    void setId(const QString &newId);

    const QString &getName() const;
    void setName(const QString &newName);

signals:
private:
    QString id;
    QString name;


};

#endif // SUBJECT_H
