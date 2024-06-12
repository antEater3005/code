#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
    node(int val)
    {
        data = val;
        link = NULL;
    }
};

void insertBeg(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->link = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }
    temp->link = n;
    n->link = head;
    head = n;
}
void insertEnd(node *&head, int val)
{
    if (head == NULL)
    {
        insertBeg(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }
    temp->link = n;
    n->link = head;
}
void deleteBeg(node *&head)
{
    node *temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }
    node *toDelete = head;
    temp->link = head->link;
    head = head->link;
    delete toDelete;
}
// Deletion at specific position
void deletion(node *&head, int pos)
{
    node *temp = head;
    if (pos == 1)
    {
        deleteBeg(head);
        return;
    }
    int counter = 1;
    while (counter != pos - 1)
    {
        temp = temp->link;
        counter++;
    }
    node *tdelete = temp->link;
    temp->link = temp->link->link;
    delete tdelete;
}

void display(node *&head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->link;

    } while (temp != head);
    cout << "NULL\n";
}
int main()
{

    node *head = NULL;
    insertBeg(head, 9);
    insertBeg(head, 8);
    insertBeg(head, 7);
    insertEnd(head, 10);
    insertEnd(head, 11);
    display(head);
    deleteBeg(head);
    deletion(head, 2);
    display(head);
    cout << "ok";
    return 0;
}