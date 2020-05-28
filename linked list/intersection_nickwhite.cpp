#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
    bool flag;
    node(int data)
    {
        this->data = data;
        next = NULL;
        flag = false;
    }
};

int check_intersection(node *head1, node *head2)
{
    if (!head1 || !head2)
        return 0;
    node *ptr1 = head1, *ptr2 = head2;
    while (head1 != head2)
    {
        if (!head1->next && !head2->next)
            return 0;
        if (!head1->next)
        {
            head1 = ptr2;
        }
        else
            head1 = head1->next;
        if (!head2->next)
        {
            head2 = ptr1;
        }
        else
            head2 = head2->next;
    }
    return 1;
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
