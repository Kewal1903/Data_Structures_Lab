#include <iostream>
using namespace std;

// Node structure representing each element in the Binary Search Tree
struct Node {
    int info;          // Data held by the node
    Node* left;        // Pointer to the left child
    Node* right;       // Pointer to the right child

    // Constructor to initialize a new node with the given data
    Node(int val) : info(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class to manage the BST operations
class BinarySearchTree {
private:
    Node* root;  // Root node of the BST

public:
    // Constructor to initialize an empty BST
    BinarySearchTree() : root(nullptr) {}

    // Method to insert a new element into the BST
    int insert(int ele) {
        return insertHelper(root, ele);
    }

    // Method to search for an element in the BST
    int search(int ele) {
        return searchHelper(root, ele);
    }

private:
    // Recursive helper function for inserting a node
    int insertHelper(Node*& node, int ele) {
        if (node == nullptr) {
            // If the current position is empty, create a new node here
            node = new Node(ele);
            return node->info;  // Return the info of the newly created node
        }
        
        // Recursive case: insert in the left or right subtree
        if (ele < node->info) {
            return insertHelper(node->left, ele);   // Insert into left subtree
        } else {
            return insertHelper(node->right, ele);  // Insert into right subtree
        }
    }

    // Recursive helper function for searching a node
    int searchHelper(Node* node, int ele) {
        if (node == nullptr) {
            // If node is nullptr, element is not found
            cout << "Element not found.\n";
            return 0;
        }

        // Recursive case: search in the left or right subtree
        if (ele < node->info) {
            return searchHelper(node->left, ele);   // Search in left subtree
        } else if (ele > node->info) {
            return searchHelper(node->right, ele);  // Search in right subtree
        } else {
            // Element found
            cout << "Element found: ";
            return node->info;  // Return the found element's info
        }
    }
};

int main() {
    BinarySearchTree bst;  // Create an instance of BinarySearchTree
    int choice;

    do {
        cout << "1. Insert Element  2. Search Element  3. Exit\n";
        cin >> choice;

        if (choice == 1) {
            // Insert a new element into the BST
            cout << "Enter element to insert: ";
            int ele;
            cin >> ele;
            cout << "Inserted: " << bst.insert(ele) << endl;
        } else if (choice == 2) {
            // Search for an element in the BST
            cout << "Enter element to search: ";
            int ele;
            cin >> ele;
            cout << bst.search(ele) << endl;
        }
    } while (choice != 3);  // Continue until the user chooses to exit

    return 0;
}
