#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class TradingPlatform;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Ui::MainWindow *ui;

private:
    std::shared_ptr<TradingPlatform> mTP;

private slots:
    void on_LEBuyAmount_returnPressed();
    void on_LEAddtoWalletAmount_returnPressed();
    void on_LERemovefromWalletAmount_returnPressed();
    void on_LESellAmount_returnPressed();
};
#endif // MAINWINDOW_H
