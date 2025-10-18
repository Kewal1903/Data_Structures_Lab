#include<iostream>
using namespace std;

struct Element {
    int coefficient;
    int exponent;
};

class Node {
public:
    Element data;
    Node* prev;
    Node* next;

    Node(Element data) : data(data), prev(nullptr), next(nullptr) {}
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = new Node({0, 0});  // Dummy head node for simplicity
        head->next = nullptr;
    }

    // Method to insert a new term in the polynomial
    void insertPoly(Element data) {
        Node* newNode = new Node(data);
        Node* temp = head;
        
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Method to display the polynomial
    void printPoly() {
        Node* temp = head->next;
        if (!temp) {
            cout << "0\n";
            return;
        }

        while (temp != nullptr) {
            if (temp->data.coefficient != 0) {
                if (temp->data.exponent == 0) {
                    cout << temp->data.coefficient;
                } else {
                    cout << temp->data.coefficient << "x^" << temp->data.exponent;
                }
                if (temp->next != nullptr && temp->next->data.coefficient > 0) {
                    cout << " + ";
                }
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // Method to read polynomial terms from user
    void readPoly() {
        int n;
        Element data;
        cout << "Enter the number of terms in the polynomial: ";
        cin >> n;
        cout << "Enter each term's coefficient and exponent in descending order of exponent:\n";
        for (int i = 0; i < n; i++) {
            cout << "Enter coefficient: ";
            cin >> data.coefficient;
            cout << "Enter exponent: ";
            cin >> data.exponent;
            insertPoly(data);
        }
    }

    // Static method to add two polynomials
    static Polynomial polyAdd(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        Node* temp1 = p1.head->next;
        Node* temp2 = p2.head->next;

        while (temp1 != nullptr && temp2 != nullptr) {
            Element data;
            if (temp1->data.exponent > temp2->data.exponent) {
                data = temp1->data;
                result.insertPoly(data);
                temp1 = temp1->next;
            }
            else if (temp2->data.exponent > temp1->data.exponent) {
                data = temp2->data;
                result.insertPoly(data);
                temp2 = temp2->next;
            }
            else {
                data.coefficient = temp1->data.coefficient + temp2->data.coefficient;
                data.exponent = temp1->data.exponent;
                result.insertPoly(data);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        // Append remaining terms from temp1 or temp2
        while (temp1 != nullptr) {
            result.insertPoly(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            result.insertPoly(temp2->data);
            temp2 = temp2->next;
        }

        return result;
    }
};

int main() {
    Polynomial poly1, poly2, poly3;
    
    cout << "Enter Polynomial 1:\n";
    poly1.readPoly();
    cout << "Polynomial 1: ";
    poly1.printPoly();
    
    cout << "Enter Polynomial 2:\n";
    poly2.readPoly();
    cout << "Polynomial 2: ";
    poly2.printPoly();
    
    poly3 = Polynomial::polyAdd(poly1, poly2);
    cout << "Sum of Polynomials: ";
    poly3.printPoly();

    return 0;
}
