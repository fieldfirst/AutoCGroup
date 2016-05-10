#include "AboutDialog.h"

AboutDialog::AboutDialog(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder):
        Gtk::AboutDialog(cobject) {

    Gtk::Button* closeButton = nullptr;
    builder->get_widget("closeButton", closeButton);

    closeButton->signal_clicked().connect(sigc::mem_fun(this, &AboutDialog::closeDialog));
}

AboutDialog::~AboutDialog() {

}

void AboutDialog::closeDialog() {
    this->hide();
}