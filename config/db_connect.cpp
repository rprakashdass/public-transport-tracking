// g++ db_connect.cpp -o db -lsqlite3
#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

// Function to open or create a database
int createDB(const char* s) {
    sqlite3* DB;
    int exit = sqlite3_open(s, &DB);

    if (exit) {
        cerr << "Error opening DB: " << sqlite3_errmsg(DB) << endl;
        return -1;
    } else {
        cout << "Opened Database Successfully!" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

// Function to create a table
int createTable(const char* s, const string& sql) {
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open(s, &DB);

    if (exit) {
        cerr << "Error opening DB: " << sqlite3_errmsg(DB) << endl;
        return -1;
    }

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        cerr << "Error creating table: " << messageError << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Table created successfully!" << endl;
    }

    sqlite3_close(DB);
    return 0;
}

// Main function
int main() {
    const char* dir = "bus_management_system.db";

    string routes = "CREATE TABLE IF NOT EXISTS routes ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "start_route TEXT NOT NULL,"
                    "start_time TEXT NOT NULL,"
                    "end_route TEXT NOT NULL,"
                    "end_time TEXT NOT NULL,"
                    "stops_with_time TEXT NOT NULL"
                    ");";

    string appAdmin = "CREATE TABLE IF NOT EXISTS appAdmin ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT NOT NULL,"
                      "email TEXT NOT NULL,"
                      "passcode TEXT NOT NULL,"
                      "office_id TEXT NOT NULL,"
                      "loggedin_at DATETIME DEFAULT CURRENT_TIMESTAMP"
                      ");";

    string busAdmin = "CREATE TABLE IF NOT EXISTS busAdmin ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT NOT NULL,"
                      "email TEXT NOT NULL,"
                      "passcode TEXT NOT NULL,"
                      "home_address TEXT NOT NULL,"
                      "loggedin_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
                      "route_id INTEGER,"
                      "FOREIGN KEY (route_id) REFERENCES routes(id)"
                      ");";

    // Create or open the database
    createDB(dir);

    // Create tables
    createTable(dir, routes);
    createTable(dir, appAdmin);
    createTable(dir, busAdmin);

    return 0;
}