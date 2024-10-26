#include<iostream>
#include<string>
#include <limits>

#include "dbStream.h"

using namespace std;

class BusAdmin{
    private:
        int id;
        string name;
        string email;
        string passcode;
        string home_address;
        string route_id;
    public:

        int login_admin(){
            return 1;
        }

        int register_admin(){

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            cout << "Enter your name\n";
            getline(cin, name);

            cout << "Enter your address (Town name)\n";
            getline(cin, email);

            cout << "Enter the passcode\n";
            getline(cin, passcode);

            cout << "Enter your home address\n";
            getline(cin, home_address);

            if(saveBusAdminData(name, email, passcode, home_address, 2)){
                cout << "bus Admin details saved successfully.\n";
            }

            return 1;
        }

        void get_buses_info(){

        }

};