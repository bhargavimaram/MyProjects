#include "Question.h"

Question::Question()
{
    qDebug()<<Q_FUNC_INFO<<endl;
}
const QString &Question::question() const
{
    return m_question;
}

void Question::setQuestion(const QString &newQuestion)
{
    m_question = newQuestion;
}

const QString &Question::option1() const
{
    return m_option1;
}

void Question::setOption1(const QString &newOption1)
{
    m_option1 = newOption1;
}

const QString &Question::option2() const
{
    return m_option2;
}

void Question::setOption2(const QString &newOption2)
{
    m_option2 = newOption2;
}

const QString &Question::option3() const
{
    return m_option3;
}

void Question::setOption3(const QString &newOption3)
{
    m_option3 = newOption3;
}

const QString &Question::option4() const
{
    return m_option4;
}

void Question::setOption4(const QString &newOption4)
{
    m_option4 = newOption4;
}

const QString &Question::answer() const
{
    return m_answer;
}

void Question::setAnswer(const QString &newAnswer)
{
    m_answer = newAnswer;
}

const QString &Question::userselect() const
{
    return m_userselect;
}

void Question::setUserselect(const QString &newUserselect)
{
    m_userselect = newUserselect;
}
