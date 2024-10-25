#include<iostream>
#include<string>

// #include "util/dbStream.cpp"

using namespace std;


class AppAdmin{
    private:
        int id;
        string name;
        string office_Address;
        string office_zone;
    public:

        int login_admin(){
            return 1;
        }

        int register_admin(){

            cout << "Enter your name\n";
            getline(cin, name);

            cout << "Enter the office address (Town name)\n";
            getline(cin, office_Address);

            cout << "Enter the office no\n";
            getline(cin, office_zone);

            // if(saveAppAdminData(name, office_Address, office_zone)){
            //     cout << "bus Admin details saved successfully.\n";
            // }

            return 1;
        }

};