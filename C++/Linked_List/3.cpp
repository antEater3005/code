#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *head = NULL;
//1.
void insertBeg(int val)
{
    node *ptr = new node();
    ptr->data = val;
    ptr->next = head;
    head = ptr;
}
//2.
void insertAtEnd(int val)
{
    node *ptr = new node();
    ptr->data = val;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
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
//3.
void deleteBeg()
{
    if (head == NULL)
    {
        cout << "List is empty.";
    }
    else
    {
        node *ptr = head;
        head = head->next;
        free(ptr); // free(ptr) its a built in function which deletes the ptr node.
    }
}
//4.
void DeleteEnd()
{
    node *ptr, *prev;
    if (head == NULL)
    {
        cout << "List is Empty.";
    }
    if (head->next == NULL)
    {
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else
    {

        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
    }
}
//5. Display middle element
void DisplayMid()
{
    node *slow = head, *fast = head;
    if (head == NULL)
    {
        cout << "List Empty.";
    }
    else
    {
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element is:" << slow->data;
    }
}
int main()
{
    node *ptr;
insertBeg(2);
    insertBeg(1);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtEnd(7);

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
    DisplayMid();
    return 0;
}