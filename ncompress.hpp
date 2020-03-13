// #include <string>

using namespace std;
class Ncompress {
  public:
    void compress();
    void decompress();
    Ncompress();
  private:
    void write_numbers_to_file(int from_res);
    string read_numbers();
    int count_numbers();
    string res;
};