//
// Created by Szilikee on 2023. 11. 27..
//

#include "Employee.h"
#include <iostream>
using namespace std;

int Employee::idCounter = 0;

Employee::Employee( const string &vezeteknev, const string &keresztnev, int szuletesiev, const string &munkakor): Person(vezeteknev, keresztnev, szuletesiev){
    this->munkakor = munkakor;
    this->id = idCounter++;
}

void Employee::print(ostream &os) const{
    Person::print(os);
    os << "\t(" << this->munkakor << ")" << endl;
}

int Employee::getID(){
    return this->id;
}