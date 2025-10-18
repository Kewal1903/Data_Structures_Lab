#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Method to display the list
    void display() {
        cout << "The list is:\n";
        Node* node = head;
        while (node != nullptr) {
            cout << node->data << " --> ";
            node = node->next;
        }
        cout << "null\n";
    }

    // Insert a new node at the beginning of the list
    void insertBegin(int node_data) {
        Node* newNode = new Node(node_data);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertEnd(int node_data) {
        Node* newNode = new Node(node_data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    // Insert a new node after a given element
    void insertAfter(int data, int element) {
        Node* temp = head;
        while (temp != nullptr && temp->data != data) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Given data not in the list\n";
            return;
        }
        Node* newNode = new Node(element);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Insert a new node before a given element
    void insertBefore(int data, int element) {
        if (head == nullptr) {
            cout << "The list is empty\n";
            return;
        }
        if (head->data == data) {  // Inserting before head
            insertBegin(element);
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != data) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Given data not in the list\n";
            return;
        }
        Node* newNode = new Node(element);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node with the given data
    void deleteNode(int data) {
        if (head == nullptr) {
            cout << "The list is empty\n";
            return;
        }
        if (head->data == data) {  // If the head is the node to be deleted
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Element not found!\n";
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
};

int main() {
    LinkedList list;
    int choice, element, data;

    cout << "1) Insert at the beginning\n";
    cout << "2) Insert at the end\n";
    cout << "3) Insert after a given element\n";
    cout << "4) Insert before a given element\n";
    cout << "5) Delete a given element\n";
    cout << "6) Display the list\n";
    cout << "7) Exit\n";

    do {
        cout << "Enter choice:\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the element to insert:\n";
            cin >> element;
            list.insertBegin(element);
            break;
        case 2:
            cout << "Enter the element to insert:\n";
            cin >> element;
            list.insertEnd(element);
            break;
        case 3:
            cout << "Enter the element to insert:\n";
            cin >> element;
            cout << "Enter the data after which insertion is to be done:\n";
            cin >> data;
            list.insertAfter(data, element);
            break;
        case 4:
            cout << "Enter the element to insert:\n";
            cin >> element;
            cout << "Enter the data before which insertion is to be done:\n";
            cin >> data;
            list.insertBefore(data, element);
            break;
        case 5:
            cout << "Enter the element to be deleted:\n";
            cin >> element;
            list.deleteNode(element);
            break;
        case 6:
            list.display();
            break;
        case 7:
            break;
        default:
            cout << "Enter a valid option:\n";
            break;
        }
    } while (choice != 7);

    return 0;
}
