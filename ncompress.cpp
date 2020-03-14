#include "ncompress.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <QByteArray>
#include <QDebug>

QByteArray Ncompress::compress(const QByteArray&  for_compress)
{   QByteArray compressed;
    qDebug()<<compressed;
    int dictSize = 256;
    std::map<std::string,int> dict;
    for (int i = 0; i < 256; i++)
    {
        dict[std::string(1, i)] = i;
    }
    std::string w;
    for (int i=0;i<for_compress.count(); ++i) {
    char c = for_compress[i];
    std::string wc = w + c;
    if (dict.count(wc))
      w = wc;
    else {
      compressed.append(dict[w]);
      dict[wc] = dictSize++;
      w = std::string(1, c);
    }
  }

  if (!w.empty())
    compressed.append(dict[w]);
  return compressed;


};
QByteArray Ncompress::decompress(const QByteArray& for_decompress)
{/*
  int end =1 ;
  int begin = 2;
  // Build the dictionary.
  int dictSize = 256;
  std::map<int,std::string> dict;
  for (int i = 0; i < 256; i++)
    dict[i] = std::string(1, i);
 
  std::string w(1, *begin++);
  std::string result = w;
  std::string entry;
  for ( ; begin != end; begin++) {
    int k = *begin;
    if (dict.count(k))
      entry = dict[k];
    else if (k == dictSize)
      entry = w + w[0];
    else
      throw "Bad compressed k";
 
    result += entry;
 
    // Add w+entry[0] to the dictionary.
    dict[dictSize++] = w + entry[0];
 
    w = entry;
  }*/
  return for_decompress;
};
