#ifndef MATRIXEXCEPTION_H
#define MATRIXEXCEPTION_H

#include "baseexception.h"

class MatrixException : public BaseException
{
public:
    MatrixException(std::string msg) : BaseException(msg) {}
    ~MatrixException() = default;
};

#endif // MATRIXEXCEPTION_H
