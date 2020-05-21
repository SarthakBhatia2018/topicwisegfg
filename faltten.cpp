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

node* flatten(node *head)
{
    if (!head || !head->next)
        return head;
    node *ptr=flatten(head->next);    
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
    head = flatten(head);
    print_ll(head);
    return 0;
}
