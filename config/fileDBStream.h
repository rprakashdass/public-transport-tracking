#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int saveAppAdminData(const string& name, const string& office_area, const string& office_zone){
    // ios -> input output stream
    // app -> append, it makes the file ready to write data
    ofstream file("app_admin_database.txt", ios::app);
    if(!file){
        cerr << "Error opening that file" << endl;
        return 0;
    }

    static int admin_id = 1000;

    file << "Admin id: " << ++admin_id << "\n"
            "Admin Name: " << name << "\n"
            "Office zone: " << office_zone << "\n"
            "Office Location: " << office_area << "\n"
             << "------------------------\n";

    file.close();

    return 1;

}

int saveBusAdminData(const string& name, const string& town_name, const string& bus_name){
    
    // app -> append, it makes the file ready to write data
    ofstream file("bus_admin_database.txt", ios::app);
    if(!file){
        cerr << "Error opening that file" << endl;
        return 0;
    }

    static int bus_id = 1000;

    file << "Bus id: " << ++bus_id << "\n"
            "Admin Name: " << name << "\n"
            "Address: " << town_name << "\n"
            "Bus Name: " << bus_name << "\n"
             << "------------------------\n";

    file.close();

    return 1;

}