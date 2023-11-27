//
// Created by Szilikee on 2023. 11. 27..
//

#ifndef LAB10_MANAGER_H
#define LAB10_MANAGER_H
#include "Employee.h"
#include <vector>


class Manager  : Employee{
protected:
    vector <Employee*> employees;
    const static string MANAGER_MUNKAKOR;
public:
    Manager(const string &vezeteknev1, const string &keresztnev1, int szuletesiev1, const string &munkakor1);
    void print(ostream& os) const override;
    void addEmployee(Employee* employees);
    void deleteEmployee(Employee* employees, int id);
};

#endif //LAB10_MANAGER_H
