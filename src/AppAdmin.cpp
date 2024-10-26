#include<iostream>
#include<string>

using namespace std;

class AppAdmin{
    private:
        int id;
        string name;
        string email;
        string passcode;
        string office_id;
    public:

        int login_admin(){
            return 1;
        }

        int register_admin(){

            cout << "Enter your name\n";
            getline(cin, name);

            cout << "Enter your email\n";
            getline(cin, email);

            cout << "Enter the passcode\n";
            getline(cin, passcode);

            cout << "Enter the office no\n";
            getline(cin, office_id);

            if(saveAppAdminData(name, email, passcode, office_id)){
                cout << "App Admin details saved successfully.\n";
            }

            return 1;
        }

};