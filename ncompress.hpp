

using namespace std;
class Ncompress {
  public:
    QByteArray compress(const QByteArray&  for_compression);
    QByteArray decompress(const QByteArray&  for_decompression);
    Ncompress();
  private:
    void write_numbers_to_file(int from_res);
    string read_numbers();
    int count_numbers();
    string res;
};