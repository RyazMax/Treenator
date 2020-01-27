#include "baseexception.h"

BaseException::BaseException(std::string msg) : _msg(msg)
{

}

const char *BaseException::what() const noexcept
{
    return _msg.c_str();
}
