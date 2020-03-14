#include <QApplication>
#include <QLabel>
#include <QWidget>
#include "ncompress.cpp"
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QList>

QByteArray create_array_from_string(string for_convert)
{
    QString str = QString::fromStdString(for_convert);
    QByteArray converted = str.toUtf8();
    return converted;
}

int main(int argc, char *argv[ ])
{
    
    QByteArray for_compress = create_array_from_string("xaxaxa");
    Ncompress d;
    qDebug()<< d.compress(for_compress);
    QApplication app(argc, argv);
    QLabel hello("<center>Welcome to my first Qt program</center>");
    hello.setWindowTitle("My First Qt Program");
    hello.resize(400, 400);
    hello.show();
    return app.exec();

}
