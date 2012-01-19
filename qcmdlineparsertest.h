#ifndef QCMDLINEPARSERTEST_H
#define QCMDLINEPARSERTEST_H

#include <QObject>

class QCmdLineParser;
class QCmdLineParserTest : public QObject
{
    Q_OBJECT
private slots:
    void test1();
private:
    bool parseThis(QCmdLineParser &parser, const QByteArray &args);
};

#endif
