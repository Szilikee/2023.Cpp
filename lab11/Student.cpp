//
// Created by Szilikee on 2023. 12. 04..
//

#include "Student.h"
#include <iostream>

Student::Student(int id, const string &firstName, const string &lastName){
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    this->grades.insert(make_pair(subject, grade));
}

double Student::getGrade(const string &subject) const {
    if(subject != "math" && subject != "hungarian" && subject != "romanian"){
        throw out_of_range("Nonexistent subject");
    }
    return grades.at(subject);
}


const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    double sum = 0.0;
    for (auto grade : grades) {
        sum += grade.second;
    }
    average = sum / grades.size();
}

double Student::getAverage() const {
    return this->average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.getFirstName() << " " << student.getLastName() << "(ID: " << student.getId() << ")" << endl;
    os << "\tGrades: " << &student.getGrades() << ", Average: " << student.getAverage() << endl;
    return os;
}