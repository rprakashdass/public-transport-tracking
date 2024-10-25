#include<iostream>
#include<string>
#include <limits>

#include "util/dbStream.cpp"

using namespace std;


class BusAdmin{
    private:
        int id;
        string name;
        string town_name;
        string bus_name;
    public:

        int login_admin(){
            return 1;
        }

        int register_admin(){

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            cout << "Enter your name\n";
            getline(cin, name);

            cout << "Enter your address (Town name)\n";
            getline(cin, town_name);

            cout << "Enter the bus no\n";
            getline(cin, bus_name);

            if(saveBusAdminData(name, town_name, bus_name)){
                cout << "bus Admin details saved successfully.\n";
            }

            return 1;
        }

};