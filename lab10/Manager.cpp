//
// Created by Szilikee on 2023. 11. 27..
//

#include "Manager.h"
#include <iostream>
using namespace std;

const string Manager::MANAGER_MUNKAKOR = "Manager";

Manager::Manager(const string &vezeteknev1, const string &keresztnev1, int szuletesiev1, const string &munkakor1) : Employee(vezeteknev1, keresztnev1, szuletesiev1, munkakor1) {
    this->munkakor = MANAGER_MUNKAKOR;
}

void Manager::addEmployee(Employee* employees) {
    this->employees.push_back(employees);
}

void Manager::deleteEmployee(Employee* employees, int id) {
    for (int i = 0; i < this->employees.size(); ++i) {
        if(this->employees[i]->getID() == id){
            this->employees.erase(this->employees.begin() + i);
        }
    }
}

void Manager::print(std::ostream &os) const {
    Employee::print(os);
    os << "Managed Employees:" << endl;
    for (const Employee* employee : employees) {
        os << "  - ";
        employee->print(os);
    }
}