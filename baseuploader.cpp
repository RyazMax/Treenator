#include "baseuploader.h"

BaseUploader::BaseUploader(std::shared_ptr<BaseUploaderImp> imp) : _imp(imp)
{
}
