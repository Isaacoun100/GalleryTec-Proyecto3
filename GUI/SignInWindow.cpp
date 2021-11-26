//
// Created by maxgm on 22/11/21.
//

#include "SignInWindow.h"

SignInWindow::SignInWindow() {
    windowSI.resize(400,225);
    windowSI.setWindowTitle(QApplication::translate("toplevel","SignIn-GalleryTEC"));
    windowSI.setFixedSize(windowSI.size().width(),windowSI.size().height());
    windowSI.show();

    setUpWidgets();

}

SignInWindow::~SignInWindow() {

}

void SignInWindow::setUpBotones() {
    newUserButton = new QPushButton(QApplication::translate("childwidget","Registrarse"), &windowSI);
    newUserButton->move(250,170);
    newUserButton->show();

    QObject::connect(newUserButton,SIGNAL(clicked()),this,SLOT(clickedRegistrar()));
}

void SignInWindow::setUpLabels() {
    newUsernameLabel = new QLabel(QApplication::translate("childwidget", "Usuario: "), &windowSI);
    newUsernameLabel->move(105, 105);
    newUsernameLabel->show();

    newPasswordLabel = new QLabel(QApplication::translate("childwidget", "Contrasena: "), &windowSI);
    newPasswordLabel->move(85, 145);
    newPasswordLabel->show();

}

void SignInWindow::setUpEntries() {
    newUsername = new QLineEdit(QApplication::translate("childwidget",""),&windowSI);
    newPassword = new QLineEdit(QApplication::translate("childwidget",""),&windowSI);
    newPassword->setEchoMode(QLineEdit::Password);

    newUsername->move(165,100);
    newPassword->move(165, 140);

    newUsername->show();
    newPassword->show();
    clickedRegistrar(newUsername->text(), newPassword->text());

}

void SignInWindow::setUpWidgets() {
    setUpBotones();
    setUpLabels();
    setUpEntries();

}

void SignInWindow::clickedRegistrar(QString usr, QString pswd) {
    DBhandler.insertUserToDB(usr, pswd);

}


