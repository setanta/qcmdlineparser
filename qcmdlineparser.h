#ifndef QCMDLINEPARSER_H
#define QCMDLINEPARSER_H

#include <QString>

class QCmdLineOption;

class Q_CORE_EXPORT QCmdLineParser
{
public:
    QCmdLineParser(const QString &description = QString());
    ~QCmdLineParser();
    bool parse(int argc, const char **argv, QString *error = 0);
    void addOption(const QCmdLineOption &option);
private:
    Q_DISABLE_COPY(QCmdLineParser)

    class QCmdLineParserPrivate;
    QCmdLineParserPrivate * const m_d;
};

#endif
