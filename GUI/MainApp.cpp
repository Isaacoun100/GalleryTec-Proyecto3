//
// Created by maxgm on 21/11/21.
//

#include "MainApp.h"

MainApp::MainApp() {
    windowApp.resize(1000,550);
    windowApp.setWindowTitle(QApplication::translate("toplevel","MainApp"));
    windowApp.setFixedSize(windowApp.size().width(),windowApp.size().height());
    windowApp.show();

    setUpWidgets();

}

MainApp::~MainApp() {

}

void MainApp::setUpBotones() {
    anteriorButton = new QPushButton(QApplication::translate("childwidget","Anterior"), &windowApp);
    anteriorButton->setMinimumSize(BUTTON_SIZE);
    anteriorButton->move(315,475);
    anteriorButton->show();

    verMetadataButton = new QPushButton(QApplication::translate("childwidget","Ver Metadata"), &windowApp);
    verMetadataButton->setMinimumSize(BUTTON_SIZE);
    verMetadataButton->move(455,475);
    verMetadataButton->show();

    siguienteButton = new QPushButton(QApplication::translate("childwidget","Siguiente"), &windowApp);
    siguienteButton->setMinimumSize(BUTTON_SIZE);
    siguienteButton->move(595,475);
    siguienteButton->show();

    eliminarImagenButton = new QPushButton(QApplication::translate("childwidget","Eliminar Imagen"), &windowApp);
    eliminarImagenButton->setMinimumSize(BUTTON_SIZE);
    eliminarImagenButton->move(175,475);
    eliminarImagenButton->show();


    //QObject::connect(anteriorButton,SIGNAL(clicked()),this,SLOT(clickedVerMetadata()));

}

void MainApp::setUpLabels() {

}


void MainApp::setUpCombobox() {
    verGalerias = new QComboBox(&windowApp);
    verGalerias->move(25, 25);

    for(int i = 0; i < 10; i++){
        verGalerias->addItem("galeria " + QString::number(i) );
    }
    verGalerias->show();

}

void MainApp::setUpWidgets() {
    setUpBotones();
    setUpLabels();
    setUpCombobox();

}

void MainApp::clickedVerMetadata() {

}

void MainApp::clickedEliminarImagen() {

}


