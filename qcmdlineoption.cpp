#include "qcmdlineoption.h"

class QCmdLineOption::QCmdLineOptionPrivate
{
public:
    QCmdLineOptionPrivate(const QString& name, QCmdLineOption::Action action)
        : name(name), action(action), isRequired(false)
    {
    }

    QString name;
    QCmdLineOption::Action action;
    bool isRequired;
};

QCmdLineOption::QCmdLineOption(const QString& name, QCmdLineOption::Action action)
    : m_d(new QCmdLineOptionPrivate(name, action))
{
}

QCmdLineOption::QCmdLineOption(const char* name, QCmdLineOption::Action action)
    : m_d(new QCmdLineOptionPrivate(name, action))
{
}

QCmdLineOption::QCmdLineOption(const QCmdLineOption& other) : m_d(new QCmdLineOptionPrivate(*other.m_d))
{
}

QCmdLineOption QCmdLineOption::operator=(const QCmdLineOption& other)
{
    return QCmdLineOption(*this);
}

QCmdLineOption::~QCmdLineOption()
{
    delete m_d;
}

QString QCmdLineOption::name() const
{
    return m_d->name;
}

void QCmdLineOption::setRequired(bool required)
{
    m_d->isRequired = required;
}

bool QCmdLineOption::isRequired() const
{
    return m_d->isRequired;
}

