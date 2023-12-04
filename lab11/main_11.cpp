#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
using namespace std;

int main() {

    Student student = Student(1, "Kiss", "Szilard");
    student.addGrade("math", 9.5);
    student.addGrade("hungarian", 8.0);
    student.addGrade("romanian", 10.0);
    std::cout << student << std::endl;
    cout << "------------------------------------------------------------------------" << endl;
    const std::string subjects[] = { "math", "romanian", "hungarian" };
    const int numSubjects = sizeof(subjects) / sizeof(subjects[0]);
    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
        dao.saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;

    return 0;
}