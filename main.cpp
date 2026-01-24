#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Student.h"
using namespace std;

void addStudent(Node*& head);
void addRecursive(Node*& current, Node* newNode);
void printList(Node* current);
void deleteRecursive(Node*& current, int id);
float averageGPA(Node* current, int count, float total);
void clearList(Node*& current);

int main() {
    Node* head = nullptr;
    bool running = true;
    string command;

    cout << "Linked List Student Manager\n";
    cout << "Commands: ADD, PRINT, DELETE, AVERAGE, QUIT\n";

    while (running) {
        cout << "\nEnter command: ";
        cin >> command;

        for (char& c : command) c = toupper(c);

        if (command == "ADD") {
            addStudent(head);
        }
        else if (command == "PRINT") {
            if (head == nullptr)
                cout << "List is empty.\n";
            else
                printList(head);
        }
        else if (command == "DELETE") {
            int id;
            cout << "Enter student ID to delete: ";
            cin >> id;
            deleteRecursive(head, id);
        }
        else if (command == "AVERAGE") {
            if (head == nullptr)
                cout << "List is empty.\n";
            else
                cout << "Average GPA: "
                     << fixed << setprecision(2)
                     << averageGPA(head, 0, 0) << endl;
        }
        else if (command == "QUIT") {
            running = false;
        }
        else {
            cout << "Unknown command.\n";
        }
    }

    clearList(head);
    return 0;
}

void addStudent(Node*& head) {
    char first[50], last[50];
    int id;
    float gpa;

    cout << "Enter first name: ";
    cin >> first;
    cout << "Enter last name: ";
    cin >> last;
    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter GPA: ";
    cin >> gpa;

    Student* s = new Student(first, last, id, gpa);
    Node* newNode = new Node(s);

    addRecursive(head, newNode);
}

void addRecursive(Node*& current, Node* newNode) {
    if (current == nullptr ||
        newNode->getStudent()->getID() < current->getStudent()->getID()) {
        newNode->setNext(current);
        current = newNode;
        return;
    }
    addRecursive(current->getNextRef(), newNode);
}

void printList(Node* current) {
    if (current == nullptr) return;
    current->getStudent()->print();
    printList(current->getNext());
}

void deleteRecursive(Node*& current, int id) {
    if (current == nullptr) {
        cout << "Student not found.\n";
        return;
    }

    if (current->getStudent()->getID() == id) {
        Node* temp = current;
        current = current->getNext();
        delete temp;
        cout << "Student deleted.\n";
        return;
    }

    deleteRecursive(current->getNextRef(), id);
}

float averageGPA(Node* current, int count, float total) {
    if (current == nullptr) {
        if (count == 0) return 0;
        return total / count;
    }
    return averageGPA(current->getNext(), count + 1,
                      total + current->getStudent()->getGPA());
}

void clearList(Node*& current) {
    if (current == nullptr) return;
    clearList(current->getNextRef());
    delete current;
    current = nullptr;
}
