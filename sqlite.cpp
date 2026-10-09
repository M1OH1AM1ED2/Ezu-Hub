#include "sqlite.h"
#include "toastwidget.h"
#include <QDebug>
SQLite::SQLite()
{
    db = nullptr;
}

SQLite::~SQLite()
{
    closeDatabase();
}
bool SQLite::openDatabase(const std::string& path)
{
    int result = sqlite3_open(path.c_str(), &db);

    if (result != SQLITE_OK)
    {
        qDebug()<< "database not work";
        return false;
    }

    qDebug()<< "Database opened successfully" << path.c_str();

    return true;
}

void SQLite::closeDatabase()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool SQLite::createSettingsTable()
{
    const char* sql = R"(CREATE TABLE IF NOT EXISTS settings( id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT UNIQUE NOT NULL,value TEXT, type TEXT );)";
  
    char* errorMessage = nullptr;

    int result = sqlite3_exec(
        db,
        sql,
        nullptr,
        nullptr,
        &errorMessage
        );

    if (result != SQLITE_OK)
    {

        qDebug()<< "Create table error: ";
        sqlite3_free(errorMessage);

        return false;
    }

    return true;
}


bool SQLite::insertSetting(
    const std::string& name,
    const std::string& value,
    const std::string& type)
{
    const char* sql = R"(
        INSERT OR IGNORE INTO settings
        (name, value, type)
        VALUES (?, ?, ?);
    )";

    sqlite3_stmt* stmt = nullptr;

    int result = sqlite3_prepare_v2(
        db,
        sql,
        -1,
        &stmt,
        nullptr
        );

    if (result != SQLITE_OK)
    {
        qDebug()<<"Prepare error:";
        return false;
    }

    sqlite3_bind_text(
        stmt,
        1,
        name.c_str(),
        -1,
        SQLITE_TRANSIENT
        );

    sqlite3_bind_text(
        stmt,
        2,
        value.c_str(),
        -1,
        SQLITE_TRANSIENT
        );

    sqlite3_bind_text(
        stmt,
        3,
        type.c_str(),
        -1,
        SQLITE_TRANSIENT
        );

    result = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (result != SQLITE_DONE)
    {
         qDebug()<<"insert error:";

        return false;
    }

    return true;
}

bool SQLite::updateSetting(
    const std::string& name,
    const std::string& value)
{
    const char* sql = R"(
        UPDATE settings
        SET value = ?
        WHERE name = ?;
    )";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(
            db,
            sql,
            -1,
            &stmt,
            nullptr) != SQLITE_OK)
    {
        return false;
    }

    sqlite3_bind_text(
        stmt,
        1,
        value.c_str(),
        -1,
        SQLITE_TRANSIENT
        );

    sqlite3_bind_text(
        stmt,
        2,
        name.c_str(),
        -1,
        SQLITE_TRANSIENT
        );

    int result = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    return result == SQLITE_DONE;
}

std::string SQLite::getSetting(
    const std::string& name)
{
    const char* sql = R"(
        SELECT value
        FROM settings
        WHERE name = ?;
    )";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(
            db,
            sql,
            -1,
            &stmt,
            nullptr) != SQLITE_OK)
    {
        return "";
    }

    sqlite3_bind_text(
        stmt,
        1,
        name.c_str(),
        -1,
        SQLITE_TRANSIENT
        );

    std::string value = "";

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char* text =
            sqlite3_column_text(stmt, 0);
 

        if (text != nullptr)
        {
            value =
     
                reinterpret_cast<const char*>(text);
  
        }
    }

    sqlite3_finalize(stmt);

    return value;
}

bool SQLite::settingExists(
    const std::string& name)
{
    const char* sql = R"(
        SELECT 1
        FROM settings
        WHERE name = ?
        LIMIT 1;
    )";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(
            db,
            sql,
            -1,
            &stmt,
            nullptr) != SQLITE_OK)
    {
        return false;
    }

    sqlite3_bind_text(
        stmt,
        1,
        name.c_str(),
        -1,
        SQLITE_TRANSIENT
        );

    bool exists =
        sqlite3_step(stmt) == SQLITE_ROW;

    sqlite3_finalize(stmt);

    return exists;
}



























































































