#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->txtIn, SIGNAL(textEdited(QString)), this, SLOT(txtInChanged(QString)));
    connect(ui->txtMils, SIGNAL(textEdited(QString)), this, SLOT(txtMilsChanged(QString)));
    connect(ui->txtMm, SIGNAL(textEdited(QString)), this, SLOT(txtMmChanged(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::txtInChanged(QString txt) {
    try {
        double in = txt.toDouble();
        ui->txtMils->setText(QString("%1").arg(in * 1000, 0, 'f', 1));
        ui->txtMm->setText(QString("%1").arg(in * 25.4, 0, 'f', 3));
    } catch (std::exception & ex) {
        ex.what();
    }
}

void MainWindow::txtMmChanged(QString txt) {
    try {
        double mm = txt.toDouble();
        ui->txtIn->setText(QString("%1").arg(mm / 25.4, 0, 'f', 3));
        ui->txtMils->setText(QString("%1").arg(mm * 1000 / 25.4, 0, 'f', 1));
    } catch (std::exception & ex) {
        ex.what();
    }
}

void MainWindow::txtMilsChanged(QString txt) {
    try {
        double mils = txt.toDouble();
        ui->txtIn->setText(QString("%1").arg(mils / 1000, 0, 'f', 3));
        ui->txtMm->setText(QString("%1").arg(mils / 1000 * 25.4, 0, 'f', 3));
    } catch (std::exception & ex) {
        ex.what();
    }

}
