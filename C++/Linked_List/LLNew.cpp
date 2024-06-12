#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
node *head = NULL;
void insertAtHead(int val)
{
    node *ptr = new node(val);
    ptr->next = head;
    head = ptr;
}
void insertAtEnd(int val)
{ node *ptr = new node(val);
    if (head == NULL)
        insertAtHead(val);
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
       
        temp->next = ptr;
    }
}
void DelAtBeg()
{
    if (head == NULL)
    {
        cout << "List is Empty";
    }
    node *ptr = head;
    head = head->next;
    free(ptr);
}
void DelAtEnd()
{
    if (head == NULL)
    {
        cout << "List is Empty";
        return;
    }
    node *temp = head;
    if (head->next == NULL)
    {
        temp = head;
        head == NULL;
        free(temp);
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next == NULL;
}
void DisplayMid()
{node *slow = head, *fast = head;
    if (head == NULL)
    {
        cout << "List is empty.";
    }

    else
    {
        while (fast->next != NULL && fast != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << slow->data;
    }
}
void printEnd()
{
    node *temp = head;
    if (head == NULL)
        cout << "List is empty.";
    while (temp->next != NULL)
        temp = temp->next;
    cout << temp->data;
}
void printReverse(node *head)
{
    if (head == NULL)
        return;
    printReverse(head->next);
    cout << head->data << " ";
}
void print()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *head;
    insertAtHead(3);
    insertAtHead(2);
    insertAtHead(1);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
     print(  );
     printEnd();
     DisplayMid();
     
}