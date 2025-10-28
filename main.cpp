#include <iostream>
#include "Node.h"
using namespace std;

int main() {
    cout << "Testing Node class...\n";

    // Create some students
    Student* s1 = new Student("Alice", "Smith", 1001, 3.8);
    Student* s2 = new Student("Bob", "Johnson", 1002, 3.5);

    // Create nodes for them
    Node* n1 = new Node(s1);
    Node* n2 = new Node(s2);

    // Link the nodes
    n1->setNext(n2);

    // Test all functions
    cout << "First node student: ";
    n1->getStudent()->print();

    cout << "Second node student (through getNext): ";
    n1->getNext()->getStudent()->print();

    cout << "\nNow deleting nodes...\n";
    delete n1; // Automatically deletes s1
    delete n2; // Automatically deletes s2

    cout << "All tests complete.\n";
    return 0;
}
