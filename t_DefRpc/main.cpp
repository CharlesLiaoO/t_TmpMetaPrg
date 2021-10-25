#include <QCoreApplication>
#include "t_DefRpc.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testRpc();

    return a.exec();
}


