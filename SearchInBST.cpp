#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* insertIntoBST(node* root, int d) {
    if (root == nullptr) {
        root = new node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inOrderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

bool searchInBST(node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key > root->data) {
        return searchInBST(root->right, key);
    } else {
        return searchInBST(root->left, key);
    }
}

int main() {
    node* root = nullptr;
    cout << "Enter the data to create BST (-1 to stop): " << endl;
    takeInput(root);

    cout << "Printing the BST (In-order): " << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "Enter the value to search in BST: ";
    int key;
    cin >> key;

    if (searchInBST(root, key)) {
        cout << "Value " << key << " found in BST." << endl;
    } else {
        cout << "Value " << key << " not found in BST." << endl;
    }

    return 0;
}
