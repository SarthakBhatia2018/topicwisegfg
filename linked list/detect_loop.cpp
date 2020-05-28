#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// int detectloop(node *head)
// {
//     if (!head || !head->next)
//         return 0;
//     unordered_set<node *> s;
//     while (head)
//     {
//         if (s.find(head) != s.end())
//             return 1;
//         s.insert(head);
//         head = head->next;
//     }
//     return 0;
// }
void print_ll(node *head)
{
    unordered_set<node *> s;
    while (head)
    {
        if (s.find(head) != s.end())
        {
            cout << head->data << " ";
            return;
        }
        s.insert(head);
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = head->next->next;
    // 1--2--3--4--5
    //        |     |
    //        - - - -
    print_ll(head);
    // if (detectloop(head))
    //     cout << "Loop";
    // else
    //     cout << "No Loop";
    return 0;
}