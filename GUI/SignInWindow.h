//
// Created by maxgm on 22/11/21.
//
#include <iostream>
#include <QtWidgets>
#include <QObject>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QString>
#include "Database_Management/UsersDatabaseHandler.h"
#include "MemoryManagement/FileHandler.h"

using namespace std;

#ifndef GALLERYTEC_PROYECTO3_SIGNINWINDOW_H
#define GALLERYTEC_PROYECTO3_SIGNINWINDOW_H


class SignInWindow:public QWindow {
    Q_OBJECT
public:
    //UsersDatabaseHandler DBhandler;
    /**
     * @brief constructor de la clase SignInWindow.
     */
    SignInWindow();

    /**
     * @brief destructor de la clase SignInWindow.
     */
    virtual ~SignInWindow();

private:
    QWidget windowSI;
    FileHandler fileHandler;
    QLineEdit *newUsername;
    QLineEdit *newPassword;
    QPushButton *newUserButton;

    QLabel *newUsernameLabel;
    QLabel *newPasswordLabel;

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
    void setUpEntries();

    /**
     * @brief metodo encargado de correr todos los demas metodos, este se llama en el constructor de la clase.
     */
    void setUpWidgets();

public slots:

    /**
     * @brief este metodo se llama cuando se le da click al boton "Registrar" y abre la ventana creada por la clase GalleryTEC_GUI.
     */
    void clickedRegistrar();

};


#endif //GALLERYTEC_PROYECTO3_SIGNINWINDOW_H
