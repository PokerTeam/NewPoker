#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtGui/QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QGraphicsObject>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QDeclarativeView *ui;
    QObject *root;

    void SetupUI(QString path);

    void SetLoginScreen();
    void SetupLoginControls(QObject *aRoot);
    void SetupLoginTextAreas(QObject *aRoot);
    void SetupLoginButtons(QObject *aRoot);

    void SetGameScreen();
    void SetupGameControls(QObject *aRoot);
    void SetupGameTextAreas(QObject *aRoot);
    void SetupGameButtons(QObject *aRoot);

private slots:
    void OnButtonLoginClick();
    void OnButtonRegisterClick();
};

#endif // MAINWINDOW_H
