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
#include "MainApp.h"

using namespace std;

#ifndef GALLERYTEC_PROYECTO3_GALLERYTEC_GUI_H
#define GALLERYTEC_PROYECTO3_GALLERYTEC_GUI_H



class GalleryTEC_GUI:public QMainWindow {
Q_OBJECT
public:
    GalleryTEC_GUI();

    virtual ~GalleryTEC_GUI();


private:
    QWidget window;
    MainApp *ma;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *registrarse;
    QPushButton *botonEntrar;

    QLabel *label1;

    void setUpBotones();

    void setUpLabels();

    void setUpEntry();

    void setUpWidgets();


public slots:

    void clickedRegistrarse();

    void clickedEntrar();


};


#endif //GALLERYTEC_PROYECTO3_GALLERYTEC_GUI_H
