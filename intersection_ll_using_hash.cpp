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

int check_intersection(node *head1, node *head2)
{
    if (!head1 || !head2)
        return 0;
    unordered_set<node *> s;
    while (head1)
    {
        s.insert(head1);
        head1 = head1->next;
    }
    while (head2)
    {
        if (s.find(head2) != s.end())
            return 1;
        head2 = head2->next;
    }
    return 0;
}

void print_ll(node *head)
{
    while (head)
    {
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
    node *head2 = new node(7);
    head2->next = new node(24);
    // head2->next->next = head->next->next;
    if (check_intersection(head, head2))
        cout << "intersection\n";
    else
        cout << "No intersection\n";
    return 0;
}