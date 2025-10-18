#include <iostream>
using namespace std;

// Node class represents an element in the queue
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with data
    Node(int val) : data(val), next(nullptr) {}
};

// Queue class that encapsulates queue operations
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor initializes an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Method to insert an element into the queue
    void insert() {
        int val;
        cout << "Insert the element in queue: ";
        cin >> val;

        Node* newNode = new Node(val); // Create a new node with given value

        if (rear == nullptr) {         // If queue is empty
            front = rear = newNode;     // Set both front and rear to the new node
        } else {
            rear->next = newNode;       // Link the current rear to the new node
            rear = newNode;             // Update rear to the new node
        }
    }

    // Method to delete an element from the queue
    void deleteElement() {
        if (front == nullptr) {         // Check if the queue is empty
            cout << "Underflow" << endl;
            return;
        }

        Node* temp = front;             // Temporary pointer to hold front node
        cout << "Element deleted from queue is: " << front->data << endl;

        front = front->next;            // Move front to the next node
        delete temp;                    // Delete the old front node

        if (front == nullptr) {         // If the queue is now empty
            rear = nullptr;             // Set rear to nullptr as well
        }
    }

    // Method to display all elements in the queue
    void display() const {
        if (front == nullptr) {         // Check if the queue is empty
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements are: ";
        while (temp != nullptr) {       // Traverse from front to rear
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;        // Create a Queue object
    int choice;

    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all the elements of queue" << endl;
    cout << "4) Exit" << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                queue.insert();         // Call insert method to add an element
                break;
            case 2:
                queue.deleteElement();  // Call deleteElement method to remove an element
                break;
            case 3:
                queue.display();        // Call display method to show all elements
                break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}