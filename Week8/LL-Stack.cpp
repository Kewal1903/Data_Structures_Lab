#include <iostream>
using namespace std;

// Node class represents an element in the stack
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node with given data
    Node(int val) : data(val), next(nullptr) {}
};

// Stack class encapsulates the stack operations
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor to initialize the stack with top as NULL
    Stack() : top(nullptr) {}

    // Method to add an element to the stack
    void push(int val) {
        Node* newNode = new Node(val);  // Create a new node with given value
        newNode->next = top;            // Link the new node to the current top
        top = newNode;                  // Update the top to the new node
    }

    // Method to remove the top element from the stack
    void pop() {
        if (top == nullptr) {           // Check if the stack is empty
            cout << "Stack Underflow" << endl;
        } else {
            cout << "The popped element is " << top->data << endl;
            Node* temp = top;           // Temporary pointer to store the current top
            top = top->next;            // Move the top to the next node
            delete temp;                // Delete the old top node
        }
    }

    // Method to display all elements in the stack from top to bottom
    void display() {
        if (top == nullptr) {           // Check if the stack is empty
            cout << "Stack is empty" << endl;
        } else {
            Node* ptr = top;
            cout << "Stack elements from top to bottom are: ";
            while (ptr != nullptr) {    // Traverse the stack until reaching the end
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;        // Create a Stack object
    int choice, val;

    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;

    do {
        cout << "Enter choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter value to be pushed:" << endl;
                cin >> val;
                stack.push(val);        // Push the value onto the stack
                break;
            }
            case 2: {
                stack.pop();            // Pop the top value from the stack
                break;
            }
            case 3: {
                stack.display();         // Display all elements in the stack
                break;
            }
            case 4: {
                cout << "Exit" << endl;
                break;
            }
            default: {
                cout << "Invalid Choice" << endl;
            }
        }
    } while (choice != 4);

    return 0;
}
