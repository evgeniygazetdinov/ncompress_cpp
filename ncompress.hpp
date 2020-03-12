#include <string>
#include <iostream>
using namespace std;
class Ncompress {
  public:
    void compress();
    void decompress();
    Ncompress();
  private:
    void write_to_file(string from_res);
    string res;
    string filename;
};