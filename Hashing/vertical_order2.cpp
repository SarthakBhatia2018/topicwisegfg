#include <iostream>
#include <unordered_map>
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

void vhelper(Node *root, int vd, unordered_map<int, vector<int>> &m, int &max, int &min)
{
    if (!root)
        return;
    if (max < vd)
        max = vd;
    if (min > vd)
        min = vd;
    m[vd].push_back(root->data);
    vhelper(root->left, vd - 1, m, max, min);
    vhelper(root->right, vd + 1, m, max, min);
}

void printVerticalOrder(Node *root)
{
    unordered_map<int, vector<int>> m;
    int min = 0, max = 0;
    vhelper(root, 0, m, max, min);
    for (int j = min; j <= max; ++j)
    {
        for (int i = 0; i < m[j].size(); ++i)
            cout << m[j][i]<< " ";
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