#include <iostream>
using namespace std;

// Node structure representing each element in the doubly linked list
class Node {
public:
    int data;      // Data held by the node
    Node* prev;    // Pointer to the previous node
    Node* next;    // Pointer to the next node

    // Constructor to initialize a new node with given data
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList class to manage linked list operations
class DoublyLinkedList {
private:
    Node* head;    // Head pointer of the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr) {}

    // Method to insert a new element at the end of the list
    void insertRear(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }

    // Method to insert a new element after a specific element
    void insertAfter(int element, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->data != element) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "The given element is not present in the list\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    // Method to insert a new element before a specific element
    void insertBefore(int element, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->data != element) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "The given element is not present in the list\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != nullptr) {
            temp->prev->next = newNode;
        } else {
            head = newNode;
        }
        temp->prev = newNode;
    }

    // Method to print the list in both forward and reverse directions
    void printList() const {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Traversing forward:\n";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;

        // Traversing backwards from the end
        cout << "Traversing backward:\n";
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Method to delete the last element from the list
    void deleteRear() {
        if (head == nullptr) {
            cout << "The list is empty\n";
            return;
        }

        Node* temp = head;
        if (temp->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    // Method to delete an element after a specific element
    void deleteAfter(int element) {
        Node* temp = head;
        while (temp != nullptr && temp->data != element) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Element is not present in the list or no element exists after it\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != nullptr) {
            toDelete->next->prev = temp;
        }
        delete toDelete;
    }

    // Method to delete an element before a specific element
    void deleteBefore(int element) {
        Node* temp = head;
        while (temp != nullptr && temp->data != element) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->prev == nullptr) {
            cout << "The element is not in the list or no element exists before it\n";
            return;
        }

        Node* toDelete = temp->prev;
        if (toDelete->prev != nullptr) {
            toDelete->prev->next = temp;
            temp->prev = toDelete->prev;
        } else {
            head = temp;
            temp->prev = nullptr;
        }
        delete toDelete;
    }
};

// Main function to test the DoublyLinkedList class
int main() {
    DoublyLinkedList list;
    int choice, data, element;

    cout << "1. Insert Rear\n";
    cout << "2. Delete Rear\n";
    cout << "3. Insert After\n";
    cout << "4. Delete After\n";
    cout << "5. Insert Before\n";
    cout << "6. Delete Before\n";
    cout << "7. Display list\n";
    cout << "8. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insertRear(data);
                break;
            case 2:
                list.deleteRear();
                cout << "Deleted rear element\n";
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter the element after which the data is to be inserted: ";
                cin >> element;
                list.insertAfter(element, data);
                break;
            case 4:
                cout << "Enter the element after which the data is to be deleted: ";
                cin >> element;
                list.deleteAfter(element);
                cout << "Deleted element after " << element << "\n";
                break;
            case 5:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter the element before which the data is to be inserted: ";
                cin >> element;
                list.insertBefore(element, data);
                break;
            case 6:
                cout << "Enter the element before which the data is to be deleted: ";
                cin >> element;
                list.deleteBefore(element);
                cout << "Deleted element before " << element << "\n";
                break;
            case 7:
                list.printList();
                break;
            case 8:
                break;
            default:
                cout << "Wrong choice!\n";
                break;
        }
    } while (choice != 8);

    return 0;
}
