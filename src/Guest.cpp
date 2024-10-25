#include<iostream>
#include<string>
using namespace std;

class Guest{
    private:
        string name;
        string location;
    public:
        Guest(string name, string location) : name(name), location(location) {};
       void welcome(){
            cout << "You are logged in as Guest User, as " << name << " from, " << location << endl;
       }
};