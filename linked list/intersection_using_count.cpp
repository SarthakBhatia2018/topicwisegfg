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
    while (head1 && head2)
    {
        if(head1==head2)
            return 1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}

int count(node *head)
{
    int c = 0;
    while (head)
    {
        c += 1;
        head = head->next;
    }
    return c;
}
// void print_ll(node *head)
// {
//     while (head)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }

void update_ll(node **head, int c)
{
    while (c--)
        *head = (*head)->next;
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
    head2->next->next = head->next->next;
    int c1 = count(head);
    int c2 = count(head2);
    c1 > c2 ? update_ll(&head, c1 - c2) : update_ll(&head2, c2 - c1);
    if (check_intersection(head, head2))
        cout << "intersection\n";
    else
        cout << "No intersection\n";
    return 0;
}