#ifndef QCMDLINEOPTION_H
#define QCMDLINEOPTION_H

#include <QString>

class QCmdLineOption
{
public:
    enum Action
    {
        StoreTrue,
        StoreValue,
        CountOccurences,
        AppendValue
    };

    QCmdLineOption(const QString &name, Action action = StoreTrue);
    QCmdLineOption(const char* name, QCmdLineOption::Action action = StoreTrue);
    QCmdLineOption(const QCmdLineOption &other);
    QCmdLineOption operator=(const QCmdLineOption &other);
    ~QCmdLineOption();

    QString name() const;

    void setRequired(bool required);
    bool isRequired() const;
private:
    class QCmdLineOptionPrivate;
    QCmdLineOptionPrivate * const m_d;
};

#endif
