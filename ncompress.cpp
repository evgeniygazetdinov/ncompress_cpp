#include "ncompress.hpp"
#include <iostream>
#include <fstream>
#include <string>


Ncompress::Ncompress()
{
    res = "1fh";
    filename = "output.txt";

}

void Ncompress::write_to_file()
{   
   
 std::ofstream out;

 // std::ios::app is the open mode "append" meaning
 // new data will be written to the end of the file.
 out.open("myfile.txt", std::ios::app);

 std::string str = "I am here.";
 out << str;
};

void Ncompress::compress()
{   
    int dictSize = 256;
    const std::string uncompressed = "xaxa"; 
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
      
      dict[wc] = dictSize++;
      w = std::string(1, c);
    }
       }

};
void Ncompress::decompress()
{
    std::cout<<"decompress"<<std::endl;
};
