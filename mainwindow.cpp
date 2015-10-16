#include "mainwindow.h"

#include "mainpartywidget.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  MainPartyWidget* main = new MainPartyWidget(this);
  this->setCentralWidget(main);
}

MainWindow::~MainWindow()
{

}
