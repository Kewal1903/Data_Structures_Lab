#include <iostream>
using namespace std;

// Node structure for binary tree
struct Node {
    int info;          // Data of the node
    Node* left;        // Pointer to left child
    Node* right;       // Pointer to right child

    // Constructor to initialize a new node
    Node(int val) : info(val), left(nullptr), right(nullptr) {}
};

// Binary Tree class to manage tree operations
class BinaryTree {
private:
    Node* root;  // Root node of the tree

public:
    // Constructor to initialize the tree
    BinaryTree() : root(nullptr) {}

    // Public method to insert a new node
    void insert(int ele, int after, char r_l) {
        if (root == nullptr) {
            // If tree is empty, create root node
            root = new Node(ele);
        } else {
            // Otherwise, insert in the correct position
            insertHelper(root, ele, after, r_l);
        }
    }

    // Public method to display inorder traversal
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    // Public method to display postorder traversal
    void postorder() {
        postorderHelper(root);
        cout << endl;
    }

    // Public method to display preorder traversal
    void preorder() {
        preorderHelper(root);
        cout << endl;
    }

    // Public method to count leaf nodes
    int leafNodes() {
        return leafNodesHelper(root);
    }

private:
    // Recursive helper function for inserting a node
    bool insertHelper(Node* node, int ele, int after, char r_l) {
        if (node == nullptr) return false;

        // If the current node matches the 'after' value
        if (node->info == after) {
            Node* newNode = new Node(ele);
            if (r_l == 'r' && node->right == nullptr) {
                node->right = newNode;
                return true;
            } else if (r_l == 'l' && node->left == nullptr) {
                node->left = newNode;
                return true;
            } else {
                cout << "Insertion failed: Desired position already occupied.\n";
                delete newNode;
                return false;
            }
        }

        // Recursively search in left and right subtrees
        return insertHelper(node->left, ele, after, r_l) || insertHelper(node->right, ele, after, r_l);
    }

    // Recursive helper function for inorder traversal
    void inorderHelper(Node* node) {
        if (node != nullptr) {
            inorderHelper(node->left);      // Visit left subtree
            cout << node->info << " ";      // Display node data
            inorderHelper(node->right);     // Visit right subtree
        }
    }

    // Recursive helper function for postorder traversal
    void postorderHelper(Node* node) {
        if (node != nullptr) {
            postorderHelper(node->left);    // Visit left subtree
            postorderHelper(node->right);   // Visit right subtree
            cout << node->info << " ";      // Display node data
        }
    }

    // Recursive helper function for preorder traversal
    void preorderHelper(Node* node) {
        if (node != nullptr) {
            cout << node->info << " ";      // Display node data
            preorderHelper(node->left);     // Visit left subtree
            preorderHelper(node->right);    // Visit right subtree
        }
    }

    // Recursive helper function to count leaf nodes
    int leafNodesHelper(Node* node) {
        if (node == nullptr) return 0;

        // Check if node is a leaf node
        if (node->left == nullptr && node->right == nullptr)
            return 1;

        // Sum of leaf nodes in left and right subtree
        return leafNodesHelper(node->left) + leafNodesHelper(node->right);
    }
};

int main() {
    BinaryTree tree;  // Create a binary tree object
    int choice;

    do {
        cout << "1. Insert 2. Inorder 3. Postorder 4. Preorder 5. Leaf Nodes 6. Exit: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int ele, after;
                char c;
                cout << "Enter element to insert: ";
                cin >> ele;
                cout << "Enter element after which to insert and r or l (0 if first node): ";
                cin >> after >> c;
                tree.insert(ele, after, c);
                break;
            }
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 3:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 4:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 5:
                cout << "Number of Leaf Nodes: " << tree.leafNodes() << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

