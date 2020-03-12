#include "ncompress.hpp"
#include <iostream>
#include <fstream>
#include <string>


Ncompress::Ncompress()
{
    res = "1fh";
    filename = "output.txt";
}

void Ncompress::write_to_file(string for_write)
{   
    std::ofstream out;
    out.open("myfile.txt", std::ios::app);
    std::string str =for_write;
    out << str;
};

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
      std::cout<<dict[w]<<endl;
    //   TODO HANDLE WRITE TO FILE THIS TYPE
    //   this->write_to_file(dict[w]);
      dict[wc] = dictSize++;
      w = std::string(1, c);
    }
       }

};
void Ncompress::decompress()
{
    std::cout<<"decompress"<<std::endl;
};
