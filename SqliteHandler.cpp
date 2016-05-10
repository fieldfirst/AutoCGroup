#include "SqliteHandler.h"

SqliteHandler::SqliteHandler() {

}

SqliteHandler::~SqliteHandler() {

}

SqliteHandler::STATUS_CODE SqliteHandler::openDatabase(const char *fileName) {
    if (sqlite3_open(fileName, &this->databaseConnection) == SQLITE_OK) {
        return SQLITE_HANDLER_OK;
    }
    else
        return SQLITE_HANDLER_ERROR;
}

SqliteHandler::STATUS_CODE SqliteHandler::closeDatabase() {
    if (sqlite3_close(this->databaseConnection) == SQLITE_BUSY) {
        return SQLITE_HANDLER_BUSY;
    }
    else
        return SQLITE_HANDLER_OK;
}

const char* SqliteHandler::getLastError() {
    return sqlite3_errmsg(this->databaseConnection);
}