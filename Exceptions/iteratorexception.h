#ifndef ITERATOREXCEPTION_H
#define ITERATOREXCEPTION_H

#include "baseexception.h"

class IteratorException : public BaseException
{
public:
    IteratorException(std::string msg) : BaseException(msg) {}
    ~IteratorException() = default;
};

#endif // ITERATOREXCEPTION_H
