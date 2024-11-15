#include <iostream>
#include <queue>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this-> left = nullptr;
        this->right = nullptr;
    }
};
node *buildTree(node *root)
{
    cout << "enter the data: ";
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return nullptr;
    }
    cout << "enter the data to inserting to the left " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data to inserting to the right " << data << endl;
    root->right = buildTree(root->right);
}

void levelorderTraversal(node *root)
{
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = nullptr;
    root = buildTree(root);
    levelorderTraversal(root);
    return 0;
}