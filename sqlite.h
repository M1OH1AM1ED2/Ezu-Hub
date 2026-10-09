#ifndef SQLITE_H
#define SQLITE_H

#include <sqlite3.h>
#include <string>

class SQLite
{
public:
    SQLite();
    ~SQLite();

    bool openDatabase(const std::string& path);
    void closeDatabase();

    bool createSettingsTable();

    bool insertSetting(
         const std::string& name,
         const std::string& value,
         const std::string& type
        );

    bool updateSetting(
        const std::string& name,
        const std::string& value
        );

    bool settingExists(
         const std::string& name
        );

    std::string getSetting(
         const std::string& name
        );

private:
    sqlite3* db;
};

#endif
