#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "member.h"
#include "motorbike.h"
using namespace std;

class Admin{
    private:
    vector<Member*> Member_list;
    vector<Motorbike*> Motorbike_list;
    public:
    Admin(){}
    Admin(vector<Member*> Member_list, vector<Motorbike*> Motorbike_list);
    bool isStrongPassword(string password){
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
    void regist(Member &newmember);
    void showGeneralMotorbike_list();
    void showMember_List();
    void showMotorbike_List();
    bool reloadMotorbike_List();
};

#endif