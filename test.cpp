#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;
};

int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 5;
    head->next = NULL;
    delete(head);
    return 0;
}