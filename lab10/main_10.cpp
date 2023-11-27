#include <iostream>
#include "Person.h"
#include "Company.h"
#include "Manager.h"
#include "Employee.h"

int main() {
//    Hozzon létre egy céget
//    ○ Alkalmazzon 10 személyt, ebből 3 legyen manager típusú
//    ○ Listázza az alkalmazottakat
//    ○ A 7 nem Manager típusú alkalmazott mindenikét rendelje hozzá
//    tetszőlegesen valamely managerhez
//    ○ Listázza csak a manager típusú alkalmazottakat
//    ○ Helyezze át az egyik alkalmazottat egyik managertől a másikhoz
//    ○ Listázza csak a manager típusú alkalmazottakat

    Company company1("BMW");
    Employee employee("Geza", "Kovacs", 1980, "Manager");
    return 0;
}
