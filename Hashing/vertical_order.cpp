#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void vhelper(Node *root, int vd, map<int, vector<int>> &m)
{
    if (!root)
        return;
    m[vd].push_back(root->data);
    vhelper(root->left, vd - 1, m);
    vhelper(root->right, vd + 1, m);
}

void printVerticalOrder(Node *root)
{
    map<int, vector<int>> m;
    vhelper(root, 0, m);
    for (auto x : m)
    {
        for (int i = 0; i < x.second.size(); ++i)
            cout << x.second[i] << " ";
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}