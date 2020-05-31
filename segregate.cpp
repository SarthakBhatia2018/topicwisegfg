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

void push(node **head_ref, int data)
{
    node *head = new node(data);
    head->next = *head_ref;
    *head_ref = head;
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
node *segregate(node *head)
{
    node *prev = NULL, *cur = head, *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    while (cur)
    {
        if (cur->data == 0)
        {
            if (prev == NULL)
            {
                prev = cur;
                cur = cur->next;
            }
            else
            {
                prev->next = cur->next;
                    cur->next = head;
                head = cur;
                cur = prev->next;
            }
        }
        else if (cur->data == 2)
        {
            if (prev)
            {
                tail->next = cur;
                tail = cur;
                cur = cur->next;
                tail->next = NULL;
            }
            else
            {
                tail->next = cur;
                cur = cur->next;
                tail = tail->next;
                tail->next = NULL;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

int main()
{
    node *head = new node(0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);
    print_ll(head);
    head = segregate(head);
    print_ll(head);
    return 0;
}