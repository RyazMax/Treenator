#ifndef BASEUPLOADERIMP_H
#define BASEUPLOADERIMP_H

#include "Exceptions/baseexception.h"

class BaseUploaderImp
{
public:
    BaseUploaderImp();
    virtual ~BaseUploaderImp() = default;

    virtual double read_double() = 0;
    virtual int read_int() = 0;
    virtual unsigned int read_uint() = 0;
};

class UploadException : public BaseException
{
public:
    UploadException(std::string msg) : BaseException(msg){}
    ~UploadException() = default;
};

#endif // BASEUPLOADERIMP_H
