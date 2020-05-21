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

node *reverse(node *head)
{
    if (!head || !head->next)
        return head;
    node *prev = NULL, *cur = head, *cur_next = head->next;
    while (cur)
    {
        cur->next = prev;
        prev = cur;
        cur = cur_next;
        if(!cur)
            break;
        cur_next = cur_next->next;
    }
    return prev;
}

void print_ll(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    node *head = new node(1);
    // head->next = new node(2);
    // head->next->next = new node(3);
    // head->next->next->next = new node(4);
    // head->next->next->next->next = new node(5);
    // head->next->next->next->next->next = new node(6);
    // head->next->next->next->next->next->next = new node(7);
    cout << "Before reverse! :";
    print_ll(head);
    head = reverse(head);
    cout << "After reverse! :";
    print_ll(head);
    return 0;
}