#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QDebug>
//#include <QSettings>
//#include <QRect>
//#include <QDesktopWidget>
namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();
    void saveSettings();
    void loadSettings();
private slots:

    void on_actionExit_triggered();

//    void on_actionOpen_triggered();

private:
    Ui::MainView *ui;
};

#endif // MAINVIEW_H
