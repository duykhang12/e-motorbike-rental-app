#include <iostream>
#include<vector>
#include<iomanip>
#include <string>
#include "admin.h"
#include "member.h"
using namespace std;


void Admin::showMember_List(){
    for (auto i : Member_list){
        cout << i->showinfo() << endl;
    }
}

void Admin::showMotorbike_List(){
    for ( auto i : Motorbike_list){
        cout << i->showin() << endl;
    }
}

void Admin::showGeneralMotorbike_list(){
    cout << left 
         << "| " << setw(10) << "Brand"
         << "| " << setw(10) << "Model"
         << "| " << setw(10) << "Size"
         << "| " << setw(10) << "Location"
         << "| " << endl;
    for (auto i : Motorbike_list){
        cout << left 
             << "| " << setw(10) << i->brand
             << "| " << setw(10) << i->model
             << "| " << setw(10) << i->size
             << "| " << setw(10) << i->location;
    }
}

bool Admin::isStrongPassword(string password){
    if (password.length() < 8){
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    string specialChars = "!@#$%^&*()-_=+[]{}|;:',.<>?/";
    
    for (auto i : password) {
        if (isupper(i)){
            hasUpper = true;
        } else if (islower(i)){
            hasLower = true;
        } else if (isdigit(i)){
            hasDigit = true;
        } else if (specialChars.find(i) != string::npos){
            hasSpecial = true;
        }
    }
   
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

void Admin::regist(Member &newmember){
    cout << "Enter your username: ";
    cin >> newmember.username;
    do {
        cout << "Enter your password: ";
        cin >> newmember.password;
        if (!isStrongPassword(newmember.password)){
            cout << "Weak password! Must be at least 8 characters and include uppercase, lowercase, digit, and special character." << endl;
        }
    } while (!isStrongPassword(newmember.password));

    cout << "Enter your full name: ";
    cin.ignore(1, '\n');
    getline(cin, newmember.fullname);
    cout << "Enter your email: ";
    cin >> newmember.email;
    cout << "Enter your ID type (Citizen ID or Passport): ";
    cin.ignore(1, '\n');
    getline(cin, newmember.id_type);
    cout << "Enter your ID number: ";
    cin >> newmember.id;

    int choice;
    while (true){
        cout << "Do you have license number? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Your answer: ";
        cin >> choice;
        if(choice == 1){
            cout << "Enter your license number: ";
            cin >> newmember.licen_number;
            cout << "Enter your expiry date: ";
            cin >> newmember.expiry_date;
            break;
        } else if (choice ==2) {
            newmember.licen_number = 0;
            newmember.expiry_date = 0;
            break;
        } else {
            cout << "Invalid choice. Try again!";
        }
    }

    Member newmem()
}