#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>

#include <string>

#include "viewerfacade.h"
#include "Drawer/qtimagedrawerimp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_lightIntens_valueChanged(int value);

    void on_lightColorButton_clicked();

    void on_treeColorButton_clicked();

    void on_leafColorButton_clicked();

    void on_zoneX_valueChanged(int arg1);

    void on_zoneZ_valueChanged(int arg1);

    void on_zoneRad_valueChanged(int arg1);

    void on_generateButton_clicked();

    void on_lightPropButton_clicked();

    void on_clean_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    void on_UP_pressed();
    void on_DOWN_pressed();
    void on_LEFT_pressed();
    void on_RIGHT_pressed();
    void on_SHIFT_pressed();
    void on_SPACE_pressed();
    void on_W_pressed();
    void on_S_pressed();
    void on_A_pressed();
    void on_D_pressed();
    void on_Q_pressed();
    void on_E_pressed();

    std::shared_ptr<BaseDrawerImp> create_drawer();

    Vec3i<float> get_area_center() const;
    float get_area_rad() const;
    float get_intens() const;
    TreeParams get_tree_params() const;
    LeafParams get_leaf_params() const;
    AreaParams get_area_params() const;
    Vec3i<float> get_light_dir() const;

    Ui::MainWindow *ui;
    ViewerFacade _facade;
    QPixmap pxp;

    QColor _color;

    QColor _treeColor;
    QColor _lightColor;
    QColor _leafColor;
};

#endif // MAINWINDOW_H
