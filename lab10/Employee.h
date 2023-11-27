//
// Created by Szilikee on 2023. 11. 27..
//

#ifndef LAB10_EMPLOYEE_H
#define LAB10_EMPLOYEE_H

#include <string>
#include "Person.h"
using namespace std;

class Employee : Person {
protected:
    static int idCounter;
    int id;
    string munkakor;
public:
    Employee(const string &vezeteknev, const string &keresztnev, int szuletesiev, const string &munkakor);
    void print(ostream& os) const override;
    int getID();
};


#endif //LAB10_EMPLOYEE_H
