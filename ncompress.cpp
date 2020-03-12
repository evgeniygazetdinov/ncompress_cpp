#include "ncompress.hpp"
#include <iostream>
#include <fstream>
#include <string>


Ncompress::Ncompress()
{
    res = "1fh";
    filename = "output.txt";

}

void Ncompress::write_to_file(string &for_save)
{ 
    std::of
    stream out("output.txt");
    out << for_save;
    out.close();
};

void Ncompress::compress()
{
  const std::string uncompressed = "xaxa"; 
  int dictSize = 256;
  std::map<std::string,int> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[std::string(1, i)] = i;
  std::string w;
  for (std::string::const_iterator it = uncompressed.begin();
       it != uncompressed.end(); ++it) {
    char c = *it;
    std::string wc = w + c;
    if (dictionary.count(wc))
      w = wc;
    else {
      this->write_to_file(dictionary[w]);
      dictionary[wc] = dictSize++;
      w = std::string(1, c);
    }
  }
 
  if (!w.empty())
    this->write_to_file(dictionary[w]);

};
void Ncompress::decompress()
{
    std::cout<<"decompress"<<std::endl;
};
