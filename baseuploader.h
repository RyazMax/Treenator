#ifndef BASEUPLOADER_H
#define BASEUPLOADER_H

#include <memory>

#include "baseuploaderimp.h"

class BaseUploader
{
public:
    explicit BaseUploader(std::shared_ptr<BaseUploaderImp> imp);
    virtual ~BaseUploader() = default;
protected:
    std::shared_ptr<BaseUploaderImp> _imp;
};


#endif // BASEUPLOADER_H
