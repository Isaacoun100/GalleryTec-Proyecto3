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

using namespace std;

#ifndef GALLERYTEC_PROYECTO3_SIGNINWINDOW_H
#define GALLERYTEC_PROYECTO3_SIGNINWINDOW_H


class SignInWindow:public QWindow {
    Q_OBJECT
public:
    SignInWindow();

    virtual ~SignInWindow();

private:
    QWidget windowSI;
    QLineEdit *newUsername;
    QLineEdit *newPassword;
    QPushButton *newUserButton;

    QLabel *newUsernameLabel;
    QLabel *newPasswordLabel;

    void setUpBotones();
    void setUpLabels();
    void setUpEntries();
    void setUpWidgets();

public slots:

    void clickedRegistrar();

};


#endif //GALLERYTEC_PROYECTO3_SIGNINWINDOW_H
