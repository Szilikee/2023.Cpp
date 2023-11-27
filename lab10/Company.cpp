//
// Created by Szilikee on 2023. 11. 27..
//

#include "Company.h"
#include "Manager.h"
#include <algorithm>
#include <iostream>

void Company::addPerson(Employee* employee) {
    //if(find(this->employees.begin(), this->employees.end(), employee) == this->employees.end()){
        this->employees.push_back(employee);
    //}
}

void Company::firePerson(Employee* employee, int id) {
    for (int i = 0; i < this->employees.size(); ++i) {
        if(this->employees[i]->getID() == id){
            this->employees.erase(this->employees.begin() + i);
        }
    }
}

void Company::assignPersonToManager(Employee* employee, Manager* manager) {
    manager->addEmployee(employee);
}

void Company::deleteFromManager(Employee* employee, Manager* manager) {
    manager->deleteEmployee(employee, employee->getID());
}

void Company::PrintEmployees(){
    for(int i=0; i<this->employees.size(); i++){
        cout << employees[i] << endl;
    }
}

void Company::printManagers(){
    for(int i=0; i<this->employees.size(); i++){
        if(typeid(*employees[i]) == typeid(Manager)){
            cout << employees[i] << endl;
        }
    }
}
