//doubly linked  list
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};
node *head; // global variable-pointer to head node.
void insertAtHead(int val)
{
    node *ptr = new node(val);
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    head->prev = ptr;
    ptr->next = head;
    head = ptr;
}
void print()
{
    node *temp = head;
    cout<<"Forward:";
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
void reversePrint()
{
    node *temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
        temp = temp->next;
        cout<<"Reverse:";
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << endl;
}
void insertAtTail(int val)
{
    node *ptr = new node(val);
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
}
int main()
{
    head = NULL;
    insertAtHead(23);
    insertAtHead(32);
    insertAtTail(71);
    insertAtTail(75);
    insertAtHead(43);
    insertAtHead(56);
    print();
    reversePrint();
    return 0;
}