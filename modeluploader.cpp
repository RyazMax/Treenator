#include "modeluploader.h"

ModelUploader::ModelUploader(std::shared_ptr<BaseUploaderImp> imp) : BaseUploader(imp)
{

}

std::shared_ptr<VertixModel> ModelUploader::load_model(std::shared_ptr<PolygonModelBuilder> builder)
{
    builder->build_model();
    size_t cnt = _imp->read_uint();
    for (size_t i = 0; i < cnt; ++i) {
        double x, y, z;
        x = _imp->read_double();
        y = _imp->read_double();
        z = _imp->read_double();
        builder->build_vert(x, y, z);
    }

    cnt = _imp->read_uint();
    for (size_t i = 0; i < cnt; ++i) {
        size_t first, second, third, red, green, blue, flag;

        first = _imp->read_uint();
        second = _imp->read_uint();
        third = _imp->read_uint();

        red = _imp->read_uint();
        green = _imp->read_uint();
        blue = _imp->read_uint();

        flag = _imp->read_uint();

        builder->build_polygon(first, second, third, QColor(red, green, blue), (bool)flag);
    }

    return builder->get_model();
}
