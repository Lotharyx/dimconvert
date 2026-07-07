#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJSEngine>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QJSEngine * jsEngine;
    QRegularExpression * mathEx;


private slots:
    void txtInChanged(QString txt);
    void txtMilsChanged(QString txt);
    void txtMmChanged(QString txt);
};
#endif // MAINWINDOW_H
