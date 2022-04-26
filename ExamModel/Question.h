#ifndef QUESTION_H
#define QUESTION_H
#include<QDebug>
#include<QString>


class Question
{
public:
    Question();

   const QString &question() const;
    void setQuestion(const QString &newQuestion);

    const QString &option1() const;
    void setOption1(const QString &newOption1);

    const QString &option2() const;
    void setOption2(const QString &newOption2);

    const QString &option3() const;
    void setOption3(const QString &newOption3);

    const QString &option4() const;
    void setOption4(const QString &newOption4);

    const QString &answer() const;
    void setAnswer(const QString &newAnswer);

    const QString &userselect() const;
    void setUserselect(const QString &newUserselect);

private:
    QString m_question;
    QString m_option1;
    QString m_option2;
    QString m_option3;
    QString m_option4;
    QString m_answer;
    QString m_userselect;

};

#endif // QUESTION_H
