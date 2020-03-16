#include <QApplication>
#include <QLabel>
#include <QWidget>
#include "ncompress.cpp"
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QList>
#include <vector>




QByteArray create_barray_from_string(string for_convert)
{
    QByteArray converted(for_convert.data(), for_convert.length());
    return converted;
}

int main(int argc, char *argv[ ])
{
    QByteArray for_compress = create_barray_from_string("z323f3");
    Ncompress d;
    qDebug()<<d.compress(for_compress);
    //qDebug()<< argv[1];
    QApplication app(argc, argv);
    QLabel hello("<center>Welcome to my first Qt program</center>");
    hello.setWindowTitle("My First Qt Program");
    hello.resize(400, 400);
    hello.show();
    return app.exec();

}
