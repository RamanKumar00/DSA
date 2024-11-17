#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertIntoBST(Node* root, int d) {
    if (root == nullptr) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    cout << "Enter the data to create BST (-1 to stop): " << endl;
    takeInput(root);

    cout << "Printing the BST (In-order): " << endl;
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
