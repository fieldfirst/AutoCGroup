#include <gtkmm-3.0/gtkmm.h>
#include "MainWindow.h"
#include <iostream>

int main(int argc, char *argv[]) {

    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.fieldfirst.AutoCGroup");
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    try {
        builder->add_from_file("/home/fieldfirst/GladeProject/AutoCGroup.glade");
    }
    catch (const Glib::FileError &ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (const Gtk::BuilderError &ex) {
        std::cerr << ex.what() << std::endl;
    }

    MainWindow *pMainWindow = nullptr;
    builder->get_widget_derived("mainwindow", pMainWindow);

    return app->run(*pMainWindow);
}