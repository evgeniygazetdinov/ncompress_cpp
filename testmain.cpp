#include <QApplication>
#include <QLabel>
#include <QWidget>
#include "ncompress.cpp"
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QList>
#include <vector>






int main(int argc, char *argv[ ])
{  
    QByteArray for_compress("SPS");
    Ncompress d;
    QByteArray compressed = d.compress(for_compress);
    //qDebug()<< compressed;
    //QByteArray uncompressed = d.decompress(compressed);
    
    //qDebug()<< argv[1];
    QApplication app(argc, argv);
    QLabel hello("<center>Welcome to my first Qt program</center>");

    hello.resize(400, 400); (d.compress(for_compress));
    hello.show();
    return app.exec();
}
