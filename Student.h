#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;

// simple Student class used for testing the Node class
class Student {
private:
    char firstName[50];
    char lastName[50];
    int id;
    float gpa;

public:
    Student(const char* first, const char* last, int idNum, float g)
    {
        strcpy(firstName, first);
        strcpy(lastName, last);
        id = idNum;
        gpa = g;
    }

    void print() const {
        cout << firstName << " " << lastName
             << " (ID: " << id << ", GPA: " << gpa << ")" << endl;
    }

    int getID() const { return id; }
    float getGPA() const { return gpa; }
};

#endif
