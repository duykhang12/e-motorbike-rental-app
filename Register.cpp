#include <register.h>
void Register::registerUser(){
    string name, password;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> password;
    User newUser(newID, name, password);
    users.push_back(newUser);
    cout << "User registered successfully with ID: " << newID << endl;
    newID++;
};
