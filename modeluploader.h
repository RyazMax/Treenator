#ifndef MODELUPLOADER_H
#define MODELUPLOADER_H

#include <memory>

#include "Model/polygionmodel.h"
#include "baseuploader.h"
#include "Builder/polygonmodelbuilder.h"
#include "baseuploaderimp.h"

class ModelUploader : public BaseUploader
{
public:
    ModelUploader(std::shared_ptr<BaseUploaderImp> imp);
    ~ModelUploader() = default;

    std::shared_ptr<VertixModel> load_model(std::shared_ptr<PolygonModelBuilder> builder);
};

#endif // MODELUPLOADER_H
