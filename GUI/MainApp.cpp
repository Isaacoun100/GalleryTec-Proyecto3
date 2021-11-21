//
// Created by maxgm on 21/11/21.
//

#include "MainApp.h"

MainApp::MainApp() {
    windowApp.resize(1000,550);
    windowApp.setWindowTitle(QApplication::translate("toplevel","MainApp"));
    windowApp.setFixedSize(windowApp.size().width(),windowApp.size().height());
    windowApp.show();

}

MainApp::~MainApp() {

}
