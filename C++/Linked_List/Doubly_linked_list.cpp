#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev = NULL;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}
void insertEnd(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void Display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}
void DeleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    free(todelete);
}
void deletion(node *&head, int pos)
{
    node *temp = head;
    int count = 1;
    if (pos == 1)
    {
        DeleteAtHead(head);
        return;
    }
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

int main()
{
    node *head = NULL;
    insertEnd(head, 8);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);
    insertAtHead(head, 7);
    insertAtHead(head, 2);
    Display(head);
    deletion(head, 1);

    deletion(head, 5);
    Display(head);
    return 0;
}