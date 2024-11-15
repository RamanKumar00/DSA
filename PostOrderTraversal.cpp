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

    if (data == -1) {
        return nullptr;
    }

    node* root = new node(data);

    cout << "Enter the data to insert to the left of " << data << endl;
    root->left = buildTree();

    cout << "Enter the data to insert to the right of " << data << endl;
    root->right = buildTree();

    return root;
}

// PostOrder Traversal Function
void PostOrder(node* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    PostOrder(root->left);

    // Traverse the right subtree
    PostOrder(root->right);

    // Visit the current node
    cout << root->data << " ";
}

int main() {
    cout << "Building the binary tree...\n";
    node* root = buildTree();

    cout << "\nPostOrder Traversal: ";
    PostOrder(root);
    cout << endl;

    return 0;
}
