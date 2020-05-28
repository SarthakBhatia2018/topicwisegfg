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

node *find_middle(node *head)
{
    if (!head)
        return head;
    node *slow = head, *fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        // cout << slow->data << " " << fast->data << endl;
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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