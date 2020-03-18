#include "ncompress.hpp"
#include <iostream>
#include <stdio.h> 
#include <string>
#include <QByteArray>
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QVector>
#include <QFile>
#include <QDataStream>
QByteArray Ncompress::serialize(QVector<int> vec)
{
    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_5);
    stream << vec;
    QFile file("1.bin");
    if(file.open(QIODevice::WriteOnly))
    {
    QDataStream stream(&file);
    stream << vec;
    file.close();
    }
    return byteArray;
};

QByteArray Ncompress::deserialize(QByteArray for_decompress)
{  
    return for_decompress;
};

QByteArray Ncompress::compress(const QByteArray  for_compress)
{   
  QVector<int> res2;
  QByteArray res;
  int dictSize = 256;
  std::map<std::string,int> dict;
  for (int i = 0; i < 256; i++)
  {
      dict[std::string(1, i)] = i;
  } 
  std::string w;
  //convert qbyte to string
  std::string ar (for_compress.constData(), for_compress.length());
  for (string::const_iterator it = ar.begin();
    it != ar.end(); ++it) {
  char c = *it;
  std::string wc = w+ c;
  
  if (dict.count(wc))
    {
      w = wc;

    }
  else {
    //right one
    res2.push_back(dict[w]);
    dict[wc] = dictSize++;
    
    w = std::string(1, c);
  }
}
if (!w.empty())
  {
    res2.push_back(dict[w]);
  }
res = (this->serialize(res2));

return res;
};

QByteArray Ncompress::decompress(const QByteArray& for_decompress)
{

  QByteArray byteArray = this->deserialize(for_decompress);


  return for_decompress;
};
