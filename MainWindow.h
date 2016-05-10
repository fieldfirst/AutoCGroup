#include <gtkmm.h>
#include "SqliteHandler.h"

#ifndef AUTOCGROUP_MAINWINDOW_H
#define AUTOCGROUP_MAINWINDOW_H

class MainWindow : public Gtk::ApplicationWindow {
public:
    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    ~MainWindow();
protected:
    void quit();
    void showAboutDialog();
private:
    Glib::RefPtr<Gtk::Builder> builder;
    SqliteHandler* sqliteHandler;
    void initProfile();
};

#endif //AUTOCGROUP_MAINWINDOW_H
