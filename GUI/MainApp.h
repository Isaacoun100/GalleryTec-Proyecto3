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
    QPushButton *anteriorButton;
    QPushButton *verMetadataButton;
    QPushButton *siguienteButton;
    QPushButton *eliminarImagenButton;
    const QSize BUTTON_SIZE = QSize(50, 50);

    QLabel *nombreGaleria;
    QLabel *nombreImagen;

    QString nombreCombobox;

    QComboBox *verGalerias;

    void setUpBotones();
    void setUpLabels();
    void setUpCombobox();
    void setUpWidgets();

public slots:
    void clickedVerMetadata();
    void clickedEliminarImagen();

};


#endif //GALLERYTEC_PROYECTO3_MAINAPP_H
