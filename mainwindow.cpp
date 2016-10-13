#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    image.load("Pic1.jpg");
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());

    ui->mainImage->setScene(scene);
    m_button = new QPushButton("Change images", this);
    m_button->setGeometry(QRect(QPoint(270, 270), QSize(100, 50)));

    connect(m_button, SIGNAL(released()), this, SLOT (handleButton()));
}

void MainWindow::handleButton()
{
    ui->lblStatus->setText("Image Changed");
    image.load("logo.png");
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());

    ui->mainImage->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}
