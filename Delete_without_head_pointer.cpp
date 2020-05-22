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

void deleteNode(node *n)
{
    if (!n || !n->next)
        return;
    // while (true)
    // {
    //     if (!node->next->next)
    //     {
    //         node->data = node->next->data;
    //         free(node->next);
    //         node->next = NULL;
    //         return;
    //     }
    //     node->data = node->next->data;
    //     node = node->next;
    // } /*This works but can be improved*/
    n->data=n->next->data;
    node *temp=n->next;
    n->next=n->next->next;
    free(temp);
    // 1   2   4   4   5
}

void print_ll(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl
         << endl;
}

int main()
{
    node *head = new node(1);
    head->next = new node(2);
    // head->next->next = new node(3);
    // head->next->next->next = new node(4);
    // head->next->next->next->next = new node(5);
    print_ll(head);
    deleteNode(head->next->next);
    print_ll(head);
    return 0;
}
