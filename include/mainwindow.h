#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "CircularProgressBar.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    XQt::CircularProgressBar *progressBar;

  private:
    Ui::MainWindow *ui;
};

#endif  // MainWindow_H
