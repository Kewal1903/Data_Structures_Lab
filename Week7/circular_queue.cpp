#include <iostream>
using namespace std;

// CircularQueue class encapsulates all operations for a circular queue of char pointers
class CircularQueue {
private:
    char* queue[5]; // Array to store elements of the queue
    int max_size;   // Maximum size of the queue
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int count;      // Current number of elements in the queue

public:
    // Constructor initializes the queue with size, front, rear, and count
    CircularQueue() : max_size(5), front(0), rear(0), count(0) {}

    // Method to get the current size of the queue
    int size() const {
        return count;
    }

    // Method to check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Method to check if the queue is full
    bool isFull() const {
        return count == max_size;
    }

    // Method to add an element to the queue (enqueue)
    void enqueue(char* element) {
        if (isFull()) { // Check for overflow
            cout << "Overflow!" << endl;
            return;
        }

        queue[rear] = element;              // Add element to the rear
        rear = (rear + 1) % max_size;       // Circularly increment rear index
        count++;                            // Increment element count
    }

    // Method to remove an element from the queue (dequeue)
    void dequeue() {
        if (isEmpty()) { // Check for underflow
            cout << "Underflow!" << endl;
            return;
        }

        front = (front + 1) % max_size; // Circularly increment front index
        count--;                        // Decrement element count
    }

    // Method to display the front element of the queue
    void displayFront() const {
        if (!isEmpty()) { // Check if queue is not empty
            cout << queue[front] << endl;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    // Method to display all elements in the queue
    void display() const {
        cout << "The queue is: ";
        if (rear >= front) { // Case when rear is ahead of or equal to front
            for (int i = front; i < rear; i++) {
                cout << queue[i] << " ";
            }
        } else { // Case when queue wraps around circularly
            for (int i = front; i < max_size; i++) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i < rear; i++) {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq; // Create an instance of CircularQueue
    int choice;

    cout << "1) Enqueue\n";
    cout << "2) Dequeue\n";
    cout << "3) Display\n";
    cout << "4) Front\n";
    cout << "5) Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Enqueue
                char* x = new char[50]; // Allocate memory for input element
                cout << "Enter element to insert: ";
                cin >> x;
                cq.enqueue(x);
                break;
            }
            case 2: // Dequeue
                cq.dequeue();
                break;
            case 3: // Display queue elements
                cq.display();
                break;
            case 4: // Display front element
                cq.displayFront();
                break;
            case 5: // Exit the program
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
