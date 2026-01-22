#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Represents a single student record
class Student {
private:
    char firstName[50];
    char lastName[50];
    int id;
    float gpa;

public:
    Student(const char* first, const char* last, int idNum, float g) {
        strcpy(firstName, first);
        strcpy(lastName, last);
        id = idNum;
        gpa = g;
    }

    void print() const {
        cout << firstName << " " << lastName << ", " << id << ", "
             << fixed << setprecision(2) << gpa << endl;
    }

    int getID() const { return id; }
    float getGPA() const { return gpa; }
};

#endif
