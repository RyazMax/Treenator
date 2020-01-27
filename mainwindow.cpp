#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     srand(time(0));

     // Настройка цвета света и pixmap в интерфейсе
    _lightColor = Qt::white;
    QPixmap lightpxp = QPixmap(ui->lightColorLabel->width(), ui->lightColorLabel->height());
    lightpxp.fill(_lightColor);
    ui->lightColorLabel->setPixmap(lightpxp);

    // Настройка цвета листа
    _leafColor = Qt::green;
    QPixmap leafpxp = QPixmap(ui->treeLeafColor->width(), ui->treeLeafColor->height());
    leafpxp.fill(_leafColor);
    ui->treeLeafColor->setPixmap(leafpxp);

    // Настройка цвета коры
    _treeColor = QColor(150, 75, 0);
    QPixmap treepxp = QPixmap(ui->treeColor->width(), ui->treeColor->height());
    treepxp.fill(_treeColor);
    ui->treeColor->setPixmap(treepxp);


    _color = QColor(0, 230, 255);
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<ChangeLightCommand>(new ChangeLightCommand(get_light_dir(), _lightColor, get_intens())));
    cmd->add_command(std::shared_ptr<DrawAreaCommand>(new DrawAreaCommand(get_area_center(), get_area_rad())));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
    setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    std::string filename = QFileDialog::getOpenFileName(this, "Имя файла", ".", "*.3dm").toStdString();
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<UploadCommand>(new UploadCommand(filename.c_str())));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
     case Qt::Key_Up:
        on_UP_pressed();
        break;
     case Qt::Key_Left:
        on_LEFT_pressed();
        break;
     case Qt::Key_Down:
        on_DOWN_pressed();
        break;
     case Qt::Key_Right:
        on_RIGHT_pressed();
        break;
     case Qt::Key_Space:
        on_SPACE_pressed();
        break;
     case Qt::Key_Shift:
        on_SHIFT_pressed();
        break;
     case Qt::Key_W:
        on_W_pressed();
        break;
    case Qt::Key_S:
        on_S_pressed();
        break;
    case Qt::Key_A:
        on_A_pressed();
        break;
    case Qt::Key_D:
        on_D_pressed();
        break;
    case Qt::Key_Q:
        on_Q_pressed();
        break;
    case Qt::Key_E:
        on_E_pressed();
        break;
    case Qt::Key_Escape:
        setFocus();
        break;
    }
}

void MainWindow::on_UP_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new ShiftCameraCommand(Point3D(20, 0, 0))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_DOWN_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new ShiftCameraCommand(Point3D(-20, 0, 0))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_LEFT_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new ShiftCameraCommand(Point3D(0, -20, 0))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_RIGHT_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new ShiftCameraCommand(Point3D(0, 20, 0))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_SHIFT_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new ShiftCameraCommand(Point3D(0, 0, -20))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_SPACE_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new ShiftCameraCommand(Point3D(0, 0, 20))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_W_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new RotateCameraCommand(Point3D(-5, 0, 0))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_S_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new RotateCameraCommand(Point3D(5, 0, 0))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_A_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new RotateCameraCommand(Point3D(0, 5, 0))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_D_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new RotateCameraCommand(Point3D(0, -5, 0))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_Q_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new RotateCameraCommand(Point3D(0, 0, -5))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_E_pressed()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new RotateCameraCommand(Point3D(0, 0, 5))));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

std::shared_ptr<BaseDrawerImp> MainWindow::create_drawer()
{
    int width = ui->canvas->width();
    int height = ui->canvas->height();
    QImage image({width, height}, QImage::Format_RGBA8888);
    image.fill(_color);
    std::shared_ptr<QtImageDrawerImp> drawer(new QtImageDrawerImp(image, ui->canvas));
    return drawer;
}

Vec3i<float> MainWindow::get_area_center() const
{
    float x = ui->zoneX->value();
    float z = ui->zoneZ->value();
    return Vec3i<float>(x, 0, z);
}

float MainWindow::get_area_rad() const
{
    return ui->zoneRad->value();
}

float MainWindow::get_intens() const
{
    return ui->lightIntens->value() / 100.;
}

TreeParams MainWindow::get_tree_params() const
{
    TreeParams t;
    t.branch_type = ui->treeBranchType->currentIndex();
    t.color =_treeColor;
    t.height = ui->treeHight->text().toInt();
    t.width = ui->treeWidth->text().toFloat();
    t.cap = ui->treeCap->value() / 100.;
    t.iter_count = ui->treeIterCount->value() - 1;
    return t;
}

LeafParams MainWindow::get_leaf_params() const
{
    LeafParams l;
    l.color = _leafColor;
    l.leaf_type = ui->leafType->currentIndex();
    l.size = ui->leafSize->text().toInt();
    return l;
}

AreaParams MainWindow::get_area_params() const
{
    AreaParams a;
    a.center = get_area_center();
    a.count = ui->zoneCap->value();
    a.rad = get_area_rad();
    return a;
}

Vec3i<float> MainWindow::get_light_dir() const
{
    float x = ui->lightDirX->text().toFloat();
    float y = ui->lightDirY->text().toFloat();
    float z = ui->lightDirZ->text().toFloat();
    return Vec3i<float>(x, y, z);
}

void MainWindow::on_lightIntens_valueChanged(int value)
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new ChangeLightCommand(get_light_dir(), _lightColor, get_intens())));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_lightColorButton_clicked()
{
    _lightColor = QColorDialog::getColor();
    QPixmap lightpxp(ui->lightColorLabel->width(), ui->lightColorLabel->height());
    lightpxp.fill(_lightColor);
    ui->lightColorLabel->setPixmap(lightpxp);

    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new ChangeLightCommand(get_light_dir(), _lightColor, get_intens())));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_treeColorButton_clicked()
{
    _treeColor = QColorDialog::getColor();
    QPixmap treepxp(ui->treeColor->width(), ui->treeColor->height());
    treepxp.fill(_treeColor);
    ui->treeColor->setPixmap(treepxp);
}

void MainWindow::on_leafColorButton_clicked()
{
    _leafColor = QColorDialog::getColor();
    QPixmap leafpxp(ui->treeLeafColor->width(), ui->treeLeafColor->height());
    leafpxp.fill(_leafColor);
    ui->treeLeafColor->setPixmap(leafpxp);
}

void MainWindow::on_zoneX_valueChanged(int arg1)
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());

    cmd->add_command(std::shared_ptr<DrawAreaCommand>(new DrawAreaCommand(get_area_center(), get_area_rad())));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_zoneZ_valueChanged(int arg1)
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());

    cmd->add_command(std::shared_ptr<DrawAreaCommand>(new DrawAreaCommand(get_area_center(), get_area_rad())));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_zoneRad_valueChanged(int arg1)
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());

    cmd->add_command(std::shared_ptr<DrawAreaCommand>(new DrawAreaCommand(get_area_center(), get_area_rad())));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_generateButton_clicked()
{
    TreeParams t = get_tree_params();
    LeafParams l = get_leaf_params();
    AreaParams a = get_area_params();

    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());

    cmd->add_command(std::shared_ptr<GenerateTreeCommand>(new GenerateTreeCommand(t, l, a)));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_lightPropButton_clicked()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new ChangeLightCommand(get_light_dir(), _lightColor, get_intens())));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}

void MainWindow::on_clean_clicked()
{
    std::shared_ptr<CompositeCommand> cmd = std::shared_ptr<CompositeCommand>(new CompositeCommand());
    cmd->add_command(std::shared_ptr<BaseCommand>(new CleanSceneCommand()));
    cmd->add_command(std::shared_ptr<DrawSceneCommand>(new DrawSceneCommand(create_drawer())));
    _facade.execute_command(cmd);
}
