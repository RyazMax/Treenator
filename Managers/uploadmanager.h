#ifndef UPLOADMANAGER_H
#define UPLOADMANAGER_H

#include <memory>

#include "basemanager.h"
#include "modeluploader.h"
#include "Uploader/textfileloaderimp.h"
#include "Builder/polygonmodelbuilder.h"
#include "Model/polygionmodel.h"

class UploadManager : public BaseManager
{
public:
    UploadManager();
    ~UploadManager() = default;

    std::shared_ptr<VertixModel> load_model(const char *filename) const;
};

#endif // UPLOADMANAGER_H
