#include <iostream>
#include <string>
#include <sqlite3.h>

using namespace std;

int saveBusAdminData(string name, string email, string passcode, string home_address, int route_id) {
    sqlite3* DB;
    char* errorMessage;

    int exit = sqlite3_open("bus_management_system.db", &DB);
    if (exit) {
        cerr << "Error opening database: " << sqlite3_errmsg(DB) << endl;
        return exit;
    }

    sqlite3_stmt* stmt;
    string sql = "INSERT INTO busAdmin (name, email, passcode, home_address, route_id) VALUES (?, ?, ?, ?, ?)";

    // Prepare the SQL statement
    exit = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0);
    if (exit != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(DB) << endl;
        sqlite3_close(DB);
        return exit;
    }

    // Bind parameters to the SQL statement
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, passcode.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, home_address.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, route_id);

    // Execute the statement
    int result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        cerr << "SQL error: " << sqlite3_errmsg(DB) << endl;
    } else {
        cout << "Record inserted successfully in busAdmin." << endl;
    }

    // Finalize the statement and close the database
    sqlite3_finalize(stmt);
    sqlite3_close(DB);
    return result;
}

int saveAppAdminData(string name, string email, string passcode, string office_id) {
    sqlite3* DB;
    char* errorMessage;

    int exit = sqlite3_open("bus_management_system.db", &DB);
    if (exit) {
        cerr << "Error opening database: " << sqlite3_errmsg(DB) << endl;
        return exit;
    }

    // Use a parameterized SQL query to prevent SQL injection
    sqlite3_stmt* stmt;
    string sql = "INSERT INTO appAdmin (name, email, passcode, office_id) VALUES (?, ?, ?, ?)";

    exit = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0);
    if (exit != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(DB) << endl;
        sqlite3_close(DB);
        return exit;
    }

    // Bind the values to the SQL statement
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, passcode.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, office_id.c_str(), -1, SQLITE_STATIC);

    int result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        cerr << "SQL error: " << sqlite3_errmsg(DB) << endl;
    } else {
        cout << "Record inserted successfully in appAdmin." << endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
    return result;
}
