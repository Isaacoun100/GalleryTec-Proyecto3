//
// Created by maxgm on 21/11/21.
//

#include "GUI/GalleryTEC_GUI.h"

#include <iostream>

GalleryTEC_GUI::GalleryTEC_GUI() {
    window.resize(600,350);
    window.setWindowTitle(QApplication::translate("toplevel","LogIn-GalleryTEC"));
    window.setFixedSize(window.size().width(),window.size().height());
    window.show();
    //DBhandler;



    setUpWidgets();
}

GalleryTEC_GUI::~GalleryTEC_GUI() {

}

void GalleryTEC_GUI::setUpBotones() {
    botonEntrar = new QPushButton(QApplication::translate("childwidget","Entrar"), &window);
    botonEntrar->move(300,170);
    botonEntrar->show();

    registrarse = new QPushButton(QApplication::translate("childwidget","Registrarse"), &window);
    registrarse->move(125,240);
    registrarse->show();

    QObject::connect(botonEntrar,SIGNAL(clicked()),this,SLOT(clickedEntrar()));
    QObject::connect(registrarse,SIGNAL(clicked()),this,SLOT(clickedRegistrarse()));

}

void GalleryTEC_GUI::setUpLabels() {
    usernameLabel = new QLabel(QApplication::translate("childwidget", "Usuario: "), &window);
    usernameLabel->move(145, 105);
    usernameLabel->show();

    passwordLabel = new QLabel(QApplication::translate("childwidget", "Contrasena: "), &window);
    passwordLabel->move(125, 145);
    passwordLabel->show();

    noTieneCuentaLabel = new QLabel(QApplication::translate("childwidget", "No posee cuenta? "), &window);
    noTieneCuentaLabel->move(125, 220);
    noTieneCuentaLabel->show();

}

void GalleryTEC_GUI::setUpEntry() {
    username = new QLineEdit(QApplication::translate("childwidget",""),&window);
    password = new QLineEdit(QApplication::translate("childwidget",""),&window);
    password->setEchoMode(QLineEdit::Password);

    username->move(200,100);
    password->move(200, 140);
    //inputGenerations->resize(50,inputGenerations->size().height()-10);
    username->show();
    password->show();
}

void GalleryTEC_GUI::setUpWidgets() {
    setUpBotones();
    setUpEntry();
    setUpLabels();

}

void GalleryTEC_GUI::clickedRegistrarse() {
    siw = new SignInWindow();
}

void GalleryTEC_GUI::clickedEntrar() {
    //if(username->text().toStdString() == )
    string usuario = username->text().toStdString();
    string clave = password->text().toStdString();
    ma = new MainApp(usuario, clave);

    //ma->show();
    window.hide();


}


