#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include <iostream>

#include "params.h"
#include "mediator.h"
#include "verticle.h"
#include "Drawer/basedrawerimp.h"

class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;
    virtual void execute(Mediator &mediator) = 0;
};

class TransformCommand : public BaseCommand
{
public:
    TransformCommand() = default;
    ~TransformCommand() = default;
    virtual void execute(Mediator &mediator) = 0;
};

class ScaleCommand : public TransformCommand
{
public:
    ScaleCommand(const Point3D& koefs, const Point3D& center, size_t obj_id);
    ~ScaleCommand() = default;
    virtual void execute(Mediator &mediator) override;
private:
    Point3D _koefs;
    Point3D _center;
    size_t _obj_id;
};

class RotateCommand : public TransformCommand
{
public:
    RotateCommand(const Point3D& angle, const Point3D& center, size_t obj_id);
    ~RotateCommand() = default;
    virtual void execute(Mediator &mediator) override;
private:
    Point3D _angle;
    Point3D _center;
    size_t _obj_id;
};

class RotateCameraCommand : public TransformCommand
{
public:
    RotateCameraCommand(const Point3D &angle);
    ~RotateCameraCommand() = default;
    virtual void execute(Mediator &mediator) override;
private:
    Point3D _angle;
};

class ShiftCommand : public TransformCommand
{
public:
    ShiftCommand(const Point3D& delta, size_t obj_id);
    ~ShiftCommand() = default;
    virtual void execute(Mediator &mediator) override;
private:
    Point3D _delta;
    size_t _obj_id;
};

class ShiftCameraCommand : public TransformCommand
{
public:
    ShiftCameraCommand(const Point3D& delta);
    ~ShiftCameraCommand() = default;
    virtual void execute(Mediator &mediator) override;
private:
    Point3D _delta;
};

class UploadCommand : public BaseCommand
{
public:
    UploadCommand(const char *name);
    ~UploadCommand() = default;
    virtual void execute(Mediator &mediator) override;
private:
    const char *_filename;
};

class DrawAreaCommand : public BaseCommand
{
public:
    DrawAreaCommand(Vec3i<float> center, float rad);
    ~DrawAreaCommand() = default;
    void execute(Mediator &mediator) override;
private:
    Vec3i<float> _center;
    float _rad;
};

class RemoveModelCommand : public BaseCommand
{
public:
    RemoveModelCommand(size_t obj_id);
    ~RemoveModelCommand() = default;
    virtual void execute(Mediator &mediator) override;
private:
    size_t _obj_id;
};

class DrawSceneCommand : public BaseCommand
{
public:
    DrawSceneCommand(std::shared_ptr<BaseDrawerImp> drawer);
    ~DrawSceneCommand() = default;
    virtual void execute(Mediator &mediator) override;
private:
    std::shared_ptr<BaseDrawerImp> _drawer;
};

class GenerateTreeCommand : public BaseCommand
{
public:
    GenerateTreeCommand(TreeParams tParams, LeafParams lParams, AreaParams aParams);
    ~GenerateTreeCommand() = default;
    void execute(Mediator &mediator) override;
private:
    TreeParams _t;
    LeafParams _l;
    AreaParams _a;
};

class ChangeLightCommand : public BaseCommand
{
public:
    ChangeLightCommand(Vec3i<float> dir, QColor color, double intens);
    ~ChangeLightCommand() = default;
    virtual void execute(Mediator &mediator) override;
private:
    Vec3i<float> _dir;
    QColor _color;
    double _intens;
};

class CleanSceneCommand : public BaseCommand
{
public:
    CleanSceneCommand() = default;
    ~CleanSceneCommand() = default;
    virtual void execute(Mediator &mediator) override;
};

class CompositeCommand : public BaseCommand
{
public:
    CompositeCommand() = default;
    CompositeCommand(std::initializer_list<std::shared_ptr<BaseCommand>> lst);
    ~CompositeCommand() = default;
    virtual void execute(Mediator &mediator) override;

    void add_command(std::shared_ptr<BaseCommand> cmd);
private:
    std::vector<std::shared_ptr<BaseCommand>> _cmds;
};

#endif // BASECOMMAND_H
