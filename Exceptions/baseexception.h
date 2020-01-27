#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>

class BaseException : public std::exception
{
public:
    BaseException(std::string msg);
    virtual ~BaseException() = default;

    const char *what() const noexcept override;
private:
    std::string _msg;
};

#endif // BASEEXCEPTION_H
