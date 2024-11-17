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

node* findMin(node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

node* deleteFromBST(node* root, int val) {
    if (root == nullptr) {
        return root;
    }

    if (val < root->data) {
        root->left = deleteFromBST(root->left, val);
    } else if (val > root->data) {
        root->right = deleteFromBST(root->right, val);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        
        node* temp = findMin(root->right); 
        root->data = temp->data;          
        root->right = deleteFromBST(root->right, temp->data); 
    }
    return root;
}

void inOrderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    node* root = nullptr;

    cout << "Enter the data to create BST (-1 to stop): " << endl;
    takeInput(root);

    cout << "Printing the BST (In-order): " << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "Enter the value to delete from BST: ";
    int val;
    cin >> val;

    root = deleteFromBST(root, val);

    cout << "Printing the BST after deletion (In-order): " << endl;
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
