#include "ncompress.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <QByteArray>


#define FILENAME "output.txt"




Ncompress::Ncompress()
{
    res = "1fh";
}

void Ncompress::write_numbers_to_file(int for_write)
{   
  //convert number to string
  std::string number_for_write;
  std::stringstream ss;
  ss << for_write;
  number_for_write = ss.str();
  //write this into textfile
  std::ofstream out;
  out.open(FILENAME, std::ios::app);
  out << "\n";
  out << number_for_write;
};
int Ncompress::count_numbers()
{
  //this case use for undestand which length need for create QByteArray for return
  int quantity_numbers = 0;
  string line;
  ifstream file(FILENAME);
  while(getline(file,line))
    {
       quantity_numbers++;
    }
  return quantity_numbers;
};


std::string Ncompress::read_numbers()
{
  //extract all from file and push stuff into
  //QbyteArray after than delete it.
  std::ifstream input(FILENAME);
  std::string name = "one";
  return name;
};



QByteArray Ncompress::compress(const QByteArray&  for_compress)
{   
    int dictSize = 256;
    const std::string uncompressed = "xaxax"; 
    std::map<std::string,int> dict;
    for (int i = 0; i < 256; i++)
    {
        dict[std::string(1, i)] = i;
    }
    std::string w;
    for (std::string::const_iterator it = uncompressed.begin();
      it != uncompressed.end(); ++it) {
    char c = *it;
    std::string wc = w + c;
    if (dict.count(wc))
      w = wc;
 
    else {
      this->write_numbers_to_file(dict[w]);
      dict[wc] = dictSize++;
      w = std::string(1, c);
    }
  }
  // TODO add read from file
  // add create Qbytearr and push numbers into him

  if (!w.empty())
    this->write_numbers_to_file(dict[w]);
    
  return for_compress;


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
