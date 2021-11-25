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
#include "SignInWindow.h"

using namespace std;

#ifndef GALLERYTEC_PROYECTO3_GALLERYTEC_GUI_H
#define GALLERYTEC_PROYECTO3_GALLERYTEC_GUI_H

/**
 * @file GalleryTEC_GUI.h
 * @authors Max Garro Mora
 * @brief Clase encargada mostrar la ventana para entrar a la aplicacion, se debe ingresar nombre de usuario y contrasena.
 * @version 2.0
 * @date 21/11/2021
 */


class GalleryTEC_GUI:public QMainWindow {
Q_OBJECT
public:
    /**
     * @brief constructor de la clase GalleryTEC_GUI.
     */
    GalleryTEC_GUI();

    /**
     * @brief destructor de la clase GalleryTEC_GUI.
     */
    virtual ~GalleryTEC_GUI();


private:
    QWidget window;
    MainApp *ma;
    SignInWindow *siw;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *registrarse;
    QPushButton *botonEntrar;

    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *noTieneCuentaLabel;

    /**
     * @brief metodo encargado de crear los botones y mostrarlos en pantalla.
     */
    void setUpBotones();

    /**
     * @brief metodo encargado de crear y mostrar los labels en pantalla.
     */
    void setUpLabels();

    /**
     * @brief metodo encargado de crear y mostrar los entries en pantalla.
     */
    void setUpEntry();

    /**
     * @brief metodo encargado de correr todos los demas metodos, este se llama en el constructor de la clase.
     */
    void setUpWidgets();


public slots:

    /**
     * @brief este metodo se llama cuando se le da click al boton "registrarse" y abre una nueva ventana hecha por la clase SignInWindow.h
     */
    void clickedRegistrarse();

    /**
     * @brief este metodo se llama cuando se le da click al boton "Entrar" y abre una ventana creada por la clase MainApp.h
     */
    void clickedEntrar();


};


#endif //GALLERYTEC_PROYECTO3_GALLERYTEC_GUI_H
