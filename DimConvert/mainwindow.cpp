#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->txtIn, SIGNAL(textEdited(QString)), this, SLOT(txtInChanged(QString)));
    connect(ui->txtMils, SIGNAL(textEdited(QString)), this, SLOT(txtMilsChanged(QString)));
    connect(ui->txtMm, SIGNAL(textEdited(QString)), this, SLOT(txtMmChanged(QString)));
    jsEngine = new QJSEngine();
    mathEx = new QRegularExpression("[\\(\\)\\/\\*\\+\\-]"); // -> ()/*+-
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::txtInChanged(QString txt) {
    try {
        double in = 0;
        if(mathEx->match(txt).hasMatch()) {
            // Evaluate as an expression with QJSEngine
            QJSValue r = jsEngine->evaluate(txt);
            if(r.isError()) {
                ui->txtIn->setStyleSheet("background-color: orange;");
                ui->txtMils->setText("");
                ui->txtMm->setText("");
                return;
            } else {
                in = r.toNumber();
            }
        } else {
            in = txt.toDouble();
        }
        ui->txtMils->setText(QString("%1").arg(in * 1000, 0, 'f', 1));
        ui->txtMm->setText(QString("%1").arg(in * 25.4, 0, 'f', 3));
        ui->txtIn->setStyleSheet("");
    } catch (std::exception & ex) {
        ex.what();
    }
}

void MainWindow::txtMmChanged(QString txt) {
    try {
        double mm = 0;
        if(mathEx->match(txt).hasMatch()) {
            // Evaluate as an expression with QJSEngine
            QJSValue r = jsEngine->evaluate(txt);
            if(r.isError()) {
                ui->txtMm->setStyleSheet("background-color: orange;");
                ui->txtMils->setText("");
                ui->txtIn->setText("");
                return;
            } else {
                mm = r.toNumber();
            }
        } else {
            mm = txt.toDouble();
        }
        ui->txtIn->setText(QString("%1").arg(mm / 25.4, 0, 'f', 3));
        ui->txtMils->setText(QString("%1").arg(mm * 1000 / 25.4, 0, 'f', 1));
        ui->txtMm->setStyleSheet("");
    } catch (std::exception & ex) {
        ex.what();
    }
}

void MainWindow::txtMilsChanged(QString txt) {
    try {
        double mils = 0;
        if(mathEx->match(txt).hasMatch()) {
            // Evaluate as an expression with QJSEngine
            QJSValue r = jsEngine->evaluate(txt);
            if(r.isError()) {
                ui->txtMils->setStyleSheet("background-color: orange;");
                ui->txtIn->setText("");
                ui->txtMm->setText("");
                return;
            } else {
                mils = r.toNumber();
            }
        } else {
            mils = txt.toDouble();
        }
        ui->txtIn->setText(QString("%1").arg(mils / 1000, 0, 'f', 3));
        ui->txtMm->setText(QString("%1").arg(mils / 1000 * 25.4, 0, 'f', 3));
        ui->txtMils->setStyleSheet("");
    } catch (std::exception & ex) {
        ex.what();
    }

}
