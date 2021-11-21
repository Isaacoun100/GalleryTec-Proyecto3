//
// Created by maxgm on 21/11/21.
//

#include "GalleryTEC_GUI.h"
#include <iostream>

GalleryTEC_GUI::GalleryTEC_GUI() {
    window.resize(1000,550);
    window.setWindowTitle(QApplication::translate("toplevel","Registro-GalleryTEC"));
    window.setFixedSize(window.size().width(),window.size().height());
    window.show();


    setUpWidgets();
}

GalleryTEC_GUI::~GalleryTEC_GUI() {

}

void GalleryTEC_GUI::setUpBotones() {
    botonEntrar = new QPushButton(QApplication::translate("childwidget","Entrar"), &window);
    botonEntrar->move(500,275);
    botonEntrar->show();

    QObject::connect(botonEntrar,SIGNAL(clicked()),this,SLOT(clickedEntrar()));

}

void GalleryTEC_GUI::setUpLabels() {

}

void GalleryTEC_GUI::setUpEntry() {
    username = new QLineEdit(QApplication::translate("childwidget",""),&window);
    password = new QLineEdit(QApplication::translate("childwidget",""),&window);
    password->setEchoMode(QLineEdit::Password);

    username->move(220,100);
    password->move(220, 120);
    //inputGenerations->resize(50,inputGenerations->size().height()-10);
    username->show();
    password->show();
}

void GalleryTEC_GUI::setUpWidgets() {
    setUpBotones();
    setUpEntry();

}

void GalleryTEC_GUI::clickedRegistrarse() {

}

void GalleryTEC_GUI::clickedEntrar() {
    ma = new MainApp();
    //ma->show();
    window.hide();


}


