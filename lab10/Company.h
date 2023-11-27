//
// Created by Szilikee on 2023. 11. 27..
//

#ifndef LAB10_COMPANY_H
#define LAB10_COMPANY_H
#include <vector>
#include "Employee.h"
#include "Manager.h"

class Company {
private:
protected:
    vector <Employee*> employees;
string name;
public:
    Company(const string &name) : name(name) {}
    void print(ostream& os) const;
    void addPerson(Employee* employee);
    void firePerson(Employee* employee, int id);
    void assignPersonToManager(Employee* employee, Manager* manager);
    void deleteFromManager(Employee* employee, Manager* manager);
    void PrintEmployees();
    void printManagers();
};


#endif //LAB10_COMPANY_H
