#include <iostream>
using namespace std;

// Queue class encapsulating all queue-related operations
class Queue {
private:
    int queue[10]; // Array to store queue elements
    int maxSize;   // Maximum size of the queue
    int front;     // Index of the front element
    int rear;      // Index of the rear element

public:
    // Constructor initializes the queue parameters
    Queue() : maxSize(10), front(0), rear(0) {}

    // Method to get the size of the queue
    int size() const {
        return rear - front;
    }

    // Method to check if the queue is empty
    bool isEmpty() const {
        return front == rear;
    }

    // Method to check if the queue is full
    bool isFull() const {
        return rear == maxSize;
    }

    // Method to add an element to the queue (enqueue)
    void enqueue(int element) {
        if (isFull()) { // Check for overflow
            cout << "Overflow!" << endl;
            return;
        }
        queue[rear++] = element; // Insert element and increment rear
    }

    // Method to remove an element from the queue (dequeue)
    void dequeue() {
        if (isEmpty()) { // Check for underflow
            cout << "Underflow!" << endl;
            return;
        }
        front++; // Increment front to remove the element
    }

    // Method to display the front element of the queue
    void displayFront() const {
        if (!isEmpty()) { // Check if queue is not empty
            cout << queue[front] << endl;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    // Method to display all elements of the queue
    void display() const {
        cout << "The queue is: ";
        for (int i = front; i < rear; i++) { // Iterate from front to rear
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q; // Create a Queue object
    int choice;

    cout << "1) Enqueue" << endl;
    cout << "2) Dequeue" << endl;
    cout << "3) Display" << endl;
    cout << "4) Front" << endl;
    cout << "5) Exit" << endl;

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Enqueue
                int x;
                cout << "Enter element to insert: ";
                cin >> x;
                q.enqueue(x);
                break;
            }
            case 2: // Dequeue
                q.dequeue();
                break;
            case 3: // Display queue elements
                q.display();
                break;
            case 4: // Display front element
                q.displayFront();
                break;
            case 5: // Exit the program
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}