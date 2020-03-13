#include <string>
#include <iostream>
using namespace std;
class Ncompress {
  public:
    void compress();
    void decompress();
    Ncompress();
  private:
    void write_to_file(int from_res);
    string read_from();
    string res;
};