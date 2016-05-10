#include <gtkmm.h>
#ifndef AUTOCGROUP_ABOUTDIALOG_H
#define AUTOCGROUP_ABOUTDIALOG_H
class AboutDialog: public Gtk::AboutDialog {
public:
    AboutDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    ~AboutDialog();
protected:
    void closeDialog();
};
#endif //AUTOCGROUP_ABOUTDIALOG_H
