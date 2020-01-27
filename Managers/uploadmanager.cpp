#include "uploadmanager.h"

UploadManager::UploadManager()
{

}

std::shared_ptr<VertixModel> UploadManager::load_model(const char *filename) const
{
    std::shared_ptr<TextFileLoaderImp> loader_imp(new TextFileLoaderImp(filename));
    std::shared_ptr<BaseUploaderImp> baseloader_imp = std::static_pointer_cast<BaseUploaderImp>(loader_imp);
    ModelUploader loader(baseloader_imp);
    return loader.load_model(std::shared_ptr<PolygonModelBuilder>(new PolygonModelBuilder));
}
