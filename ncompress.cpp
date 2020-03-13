#include "ncompress.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <sstream>


#define FILENAME "output.txt"




Ncompress::Ncompress()
{
    res = "1fh";
}

void Ncompress::write_to_file(int for_write)
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

std::string read_from_file()
{
  std::string f ;
  f = "noncense";
  return f;

}


void Ncompress::compress()
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
      this->write_to_file(dict[w]);
      dict[wc] = dictSize++;
      w = std::string(1, c);
    }
  }
  // if (!w.empty())
    //this->dict[w];
  

};
void Ncompress::decompress()
{
    std::cout<<"decompress"<<std::endl;
};
