#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next, *bottom;
    node(int data)
    {
        this->data = data;
        next = NULL;
        bottom = NULL;
    }
};

node *merge_ll(node *head1, node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    node *head;
    if (head1->data < head2->data)
    {
        head = head1;
        head1 = head1->bottom;
    }
    else
    {
        head = head2;
        head2 = head2->bottom;
    }
    node *head_ref = head;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            head->bottom = head1;
            head1 = head1->bottom;
            head = head->bottom;
        }
        else
        {
            head->bottom = head2;
            head2 = head2->bottom;
            head = head->bottom;
        }
    }
    if (head1)
        head->bottom = head1;
    if (head2)
        head->bottom = head2;
    return head_ref;
}

node *merge_ll_util(node *head)
{
    if (!head || !head->next)
        return head;
    if (!head->next->next)
    {
        head = merge_ll(head, head->next);
        return head;
    }
    node *ptr = merge_ll_util(head->next);
    head = merge_ll(head, ptr);
    return head;
}

void print_ll(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->bottom;
    }
}

int main()
{
    node *head = new node(5);
    head->bottom = new node(7);
    head->bottom->bottom = new node(8);
    head->bottom->bottom->bottom = new node(30);
    head->next = new node(10);
    head->next->bottom = new node(20);
    head->next->next = new node(19);
    head->next->next->bottom = new node(22);
    head->next->next->bottom->bottom = new node(50);
    head->next->next->next = new node(28);
    head->next->next->next->bottom = new node(35);
    head->next->next->next->bottom->bottom = new node(40);
    head->next->next->next->bottom->bottom->bottom = new node(45);
    head = merge_ll_util(head);
    print_ll(head);
    return 0;
}
