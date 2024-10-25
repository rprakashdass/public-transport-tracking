#include<iostream>
#include<string>

#include "Guest.cpp"
#include "BusAdmin.cpp"
#include "AppAdmin.cpp"

using namespace std;

void guest_login(string name="", string location=""){
    cout << "Enter your name\n";
    cin >> name;
    getline(cin, name);

    cout << "Enter your location\n";
    cin >> location;
    getline(cin, location);

    Guest guest(name, location);
    guest.welcome();
}

void appAdmin(){

    AppAdmin admin;

    int choice;
    cout << "Enter 1 to register as app Admin\n"
            "Enter 2 to login as app Admin\n";
    cin >> choice;

    if(choice == 1){
        if(admin.register_admin()) cout << "Successfully registerd!" << endl;
    } else {
        if(admin.login_admin()) cout << "Logged in Successfully!" << endl;
    }
    
}

void busAdmin(){

    BusAdmin admin;

    int choice;
    cout << "Enter 1 to register as bus Admin\n"
            "Enter 2 to login bus Admin\n";
    cin >> choice;

    if(choice == 1){
        if(admin.register_admin()) cout << "Successfully registerd!";
    } else {
        if(admin.login_admin()) cout << "Logged in Successfully!";
    }
    
}

void login(){
    int input = -1;
    cout << "Enter 1 to login as a guest\n"
            "Enter 2 to login as a bus admin\n"
            "Enter 3 to login as a app admin" << endl;
    cin >> input;
    if(input == 1){
        guest_login();
    } else if (input == 2){
        busAdmin();
    } else if(input == 3){
        appAdmin();
    }
    else{
        cout << "Exit - Invaid Credentils" << endl;
    }

}

int main(){

    login();

    return 0;
}