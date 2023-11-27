//
// Created by Szilikee on 2023. 11. 27..
//

#include "Person.h"
#include <iostream>
#include <ostream>
using namespace std;

Person::Person(const string &vezeteknev, const string &keresztnev, int szuletesiev) {
    this->vezeteknev = vezeteknev;
    this->keresztnev = keresztnev;
    this->szuletesiev = szuletesiev;
}

void Person::print(std::ostream &os) const {
    os << this->vezeteknev << " " << this->keresztnev << " (" << this->szuletesiev << ")"  << endl;
}

ostream &operator<<(ostream &os, const Person &p) {
    p.print(os);
    return os;
}