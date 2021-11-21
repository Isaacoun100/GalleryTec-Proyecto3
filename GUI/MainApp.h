//
// Created by maxgm on 21/11/21.
//
#include <iostream>
#include <QtWidgets>
#include <QObject>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QString>

using namespace std;

#ifndef GALLERYTEC_PROYECTO3_MAINAPP_H
#define GALLERYTEC_PROYECTO3_MAINAPP_H


class MainApp:public QWindow {
    Q_OBJECT
public:
    MainApp();

    virtual ~MainApp();

private:
    QWidget windowApp;

};


#endif //GALLERYTEC_PROYECTO3_MAINAPP_H
