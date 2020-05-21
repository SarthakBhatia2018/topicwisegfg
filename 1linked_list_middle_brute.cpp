#include <iostream>

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

int count_nodes(node *head)
{
    if (!head)
        return 0;
    int c = 0;
    while (head)
    {
        c += 1;
        head = head->next;
    }
    return c;
}
node *find_middle(node *head)
{
    if (!head)
        return head;
    int c = count_nodes(head);
    c /= 2;
    while (c--)
    {
        head = head->next;
    }
    return head;
}

// void print_ll(node *head)
// {
//     while (head)
//     {
//         cout << head->data<<" ";
//         head = head->next;
//     }
// }
int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    // head->next->next->next->next->next->next = new node(7);
    node *mid = find_middle(head);
    cout << mid->data << endl;
    return 0;
}