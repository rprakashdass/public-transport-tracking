// To Run
// g++ -o db db.cpp -lsqlite3

#include<iostream>
#include<sqlite3.h>
#include<string.h>
using namespace std;

int main() {
    sqlite3* DB;

    const char* dir = "bus_management_system.db";
    
    int exit = sqlite3_open(dir, &DB);

    if(exit)
        cerr << "Error opening DB: " << sqlite3_errmsg(DB) << endl;
    else
        cout << "Opened Database Successfully!" << endl;

    sqlite3_close(DB);
    return 0;
}