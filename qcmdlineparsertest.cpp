#include "qcmdlineparsertest.h"
#include <QtTest/QTest>
#include "qcmdlineparser.h"
#include "qcmdlineoption.h"

bool QCmdLineParserTest::parseThis(QCmdLineParser &parser, const QByteArray &args)
{
    QList<QByteArray> argList = args.split(' ');
    argList.prepend("APPNAME");
    int argc = argList.count();
    const char** argv = new const char*[argc];
    QList<QByteArray>::const_iterator it = argList.begin();
    for (int i = 0; i < argc; ++i)
        argv[i] = argList.at(i).constData();
    return parser.parse(argc, argv);
}

void QCmdLineParserTest::test1()
{
    QCmdLineParser parser;
    parser.addOption("-f");
    parser.addOption("-foo");
    QVERIFY(parseThis(parser, "-f 3 -foo 2"));
}

QTEST_APPLESS_MAIN(QCmdLineParserTest)
