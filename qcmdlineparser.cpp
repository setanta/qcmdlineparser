
#include "qcmdlineparser.h"
#include "qcmdlineoption.h"
#include <QLinkedList>
#include <QMap>
#include <QDebug>

class QCmdLineParser::QCmdLineParserPrivate
{
public:
    QString description;
    QMap<QString, QCmdLineOption> optionalArg;
    QLinkedList<QCmdLineOption> positionalArg;
};

QCmdLineParser::QCmdLineParser(const QString &description) : m_d(new QCmdLineParserPrivate)
{
    m_d->description = description;
}

QCmdLineParser::~QCmdLineParser()
{
    delete m_d;
}

bool QCmdLineParser::parse(int argc, const char **argv, QString *error)
{
    for (int i = 0; i < argc; ++i) {
        if (argv[i][0] == '-') {
            // Try to search for the entire string
            if (m_d->optionalArg.contains(argv[i])) {
                qDebug() << "optional arg: " << argv[i];
            }
        } else {
            // positional arguments!
            qDebug() << "positional arg?" << argv[i];
        }

    }
    return false;
}

void QCmdLineParser::addOption(const QCmdLineOption &option)
{
    const QString optName = option.name();
    if (optName.startsWith('-'))
        m_d->optionalArg.insert(optName, option);
    else
        m_d->positionalArg << option;
}

