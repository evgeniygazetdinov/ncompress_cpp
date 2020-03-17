
using namespace std;
class Ncompress 
{
  public:
    QByteArray compress(const QByteArray for_compression);
    QByteArray decompress(const QByteArray&  for_decompression);
  private:
    QByteArray serialize(QVector<int> data);
    QByteArray deserialize(QByteArray for_decompress);

  };
