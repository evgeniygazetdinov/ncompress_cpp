#include <string>
#include <iostream>
using namespace std;
class Ncompress {
  public:
    void compress();
    void decompress();
  private:
    void write_to_file();
    string res;
    string filename;
};