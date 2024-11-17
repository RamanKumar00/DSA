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


int findMin(node* root) {
    if (root == nullptr) {
        cout << "The BST is empty!" << endl;
        return -1; 
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}


int findMax(node* root) {
    if (root == nullptr) {
        cout << "The BST is empty!" << endl;
        return -1;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

int main() {
    node* root = nullptr;
    cout << "Enter the data to create BST (-1 to stop): " << endl;
    takeInput(root);

    int minValue = findMin(root);
    int maxValue = findMax(root);

    cout << "Minimum value in the BST: " << minValue << endl;
    cout << "Maximum value in the BST: " << maxValue << endl;

    return 0;
}
