#include <iostream>
#include <queue>
#include <map>

using namespace std;

// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};

// A utility function to create a new node
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// The main function to print vertical oder of a
// binary tree with given root
void printVerticalOrder(Node *root)
{
    if (!root)
        return;
    map<int, vector<int>> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        m[p.second].push_back(p.first->key);
        if (p.first->left)
            q.push({p.first->left, p.second - 1});
        if (p.first->right)
            q.push({p.first->right, p.second + 1});
    }
    for (auto x : m)
    {
        for (int i = 0; i < x.second.size(); ++i)
            cout << x.second[i] << " ";
        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->right->right->left->right->right = newNode(12);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
