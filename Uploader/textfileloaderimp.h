#ifndef TEXTFILELOADERIMP_H
#define TEXTFILELOADERIMP_H

#include <fstream>

#include "baseuploaderimp.h"

class TextFileLoaderImp : public BaseUploaderImp
{
public:
    TextFileLoaderImp(const char* filename);
    ~TextFileLoaderImp();

    virtual double read_double() override;
    virtual int read_int() override;
    virtual unsigned int read_uint() override;
private:
    std::ifstream _input_stream;
};

#endif // TEXTFILELOADERIMP_H
