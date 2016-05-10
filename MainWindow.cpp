#include "MainWindow.h"
#include "AboutDialog.h"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
        Gtk::ApplicationWindow (cobject),
        builder (builder),
        sqliteHandler (new SqliteHandler()) {

    // Map the actions
    this->add_action("exit", sigc::mem_fun(*this, &MainWindow::quit));
    this->add_action("about", sigc::mem_fun(*this, &MainWindow::showAboutDialog));

    // Some initial setup
    this->set_default_size(600, 400);
    this->set_size_request(600, 400);

    // Load and restore the UI
    this->initProfile();

}

MainWindow::~MainWindow() {
    this->sqliteHandler->closeDatabase();
    delete this->sqliteHandler;
}

void MainWindow::quit() {
    this->close();
}

void MainWindow::showAboutDialog() {
    AboutDialog* aboutDialog = nullptr;
    this->builder->get_widget_derived("aboutdialog", aboutDialog);
    aboutDialog->set_transient_for(*static_cast<Gtk::Window* >(this));
    aboutDialog->show();
}

void MainWindow::initProfile() {
    /*
     * Check if the $HOME/.config/AutoCGroup is existed, if not then create a new one
     */
    std::string profilePath = Glib::get_home_dir();
    profilePath.append("/.config/AutoCGroup");

    // Create a dir along with its parents
    g_mkdir_with_parents(profilePath.c_str(), 0744);

    // A full path
    profilePath.append("/profile.sqlite");

    if (this->sqliteHandler->openDatabase(profilePath.c_str()) == SqliteHandler::SQLITE_HANDLER_OK) {
    }
    else {
        Gtk::MessageDialog msgDialog(*this, "Unable to load the profile",
                                     false, Gtk::MESSAGE_ERROR,
                                     Gtk::BUTTONS_OK);
        msgDialog.set_secondary_text(this->sqliteHandler->getLastError());
        msgDialog.run();
    }
}