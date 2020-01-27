#include "textfileloaderimp.h"

TextFileLoaderImp::TextFileLoaderImp(const char *filename)
{
    _input_stream = std::ifstream(filename);
    if (!_input_stream.is_open()) throw UploadException("Can not open file");
}

TextFileLoaderImp::~TextFileLoaderImp()
{
    if (_input_stream.is_open()) _input_stream.close();
}

double TextFileLoaderImp::read_double()
{
    double ret;
    _input_stream >> ret;
    if (_input_stream.fail()) throw UploadException("Invalid data in file");
    return ret;
}

int TextFileLoaderImp::read_int()
{
    int ret;
    _input_stream >> ret;
    if (_input_stream.fail()) throw UploadException("Invalid data in file");
    return ret;
}

unsigned int TextFileLoaderImp::read_uint()
{
    unsigned int ret;
    _input_stream >> ret;
    if (_input_stream.fail()) throw UploadException("Invalid data in file");
    return ret;
}
