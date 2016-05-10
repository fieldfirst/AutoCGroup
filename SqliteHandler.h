#include <sqlite3.h>

#ifndef AUTOCGROUP_SQLITEHANDLER_H
#define AUTOCGROUP_SQLITEHANDLER_H

class SqliteHandler {

public:
    enum STATUS_CODE {
        SQLITE_HANDLER_OK,
        SQLITE_HANDLER_ERROR,
        SQLITE_HANDLER_BUSY
    };
    SqliteHandler();
    ~SqliteHandler();

    STATUS_CODE openDatabase(const char* fileName);
    STATUS_CODE  closeDatabase();
    const char* getLastError();


private:
    sqlite3* databaseConnection;

};


#endif //AUTOCGROUP_SQLITEHANDLER_H
