//
// Created by Szilikee on 2023. 11. 27..
//

#ifndef LAB10_PERSON_H
#define LAB10_PERSON_H
#include <string>
using namespace std;

class Person {
    string vezeteknev;
    string keresztnev;
    int szuletesiev;

public:
    Person(const string &vezeteknev, const string &keresztnev, int szuletesiev);
    virtual void print(ostream& os) const;
    friend ostream &operator<<(ostream &os, const Person &p);
};

#endif //LAB10_PERSON_H
