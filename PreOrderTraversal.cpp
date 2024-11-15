#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor
    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to build the tree
node* buildTree() {
    int data;
    cout << "Enter the data (-1 for NULL): ";
    cin >> data;

    // Base case: return nullptr for -1
    if (data == -1) {
        return nullptr;
    }

    // Create the node
    node* root = new node(data);

    // Build left and right subtrees
    cout << "Enter the data to insert to the left of " << data << endl;
    root->left = buildTree();

    cout << "Enter the data to insert to the right of " << data << endl;
    root->right = buildTree();

    return root;
}

// PreOrder Traversal
void PreOrder(node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " "; // Print node data with a space
    PreOrder(root->left);
    PreOrder(root->right);
}

int main() {
    cout << "Building the binary tree...\n";
    node* root = buildTree(); // Build the tree

    // Display the PreOrder traversal
    cout << "\nPreOrder Traversal: ";
    PreOrder(root);
    cout << endl;

    return 0;
}
