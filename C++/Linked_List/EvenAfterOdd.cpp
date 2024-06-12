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
    node *ptr = new node(val);
    ptr->data = val;
    ptr->link = head;
    head = ptr;
}
void insertAtEnd(node *&head, int val)
{
    node *ptr = new node(val);
    node *temp = head;
    ptr->data = val;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = ptr;
}
void EvenAfterOdd(node *&head)
{
    node *odd = head;
    node *even = head->link;
    node *evenstart = even;
    while (even->link != NULL && odd->link != NULL)
    {
        odd->link = even->link;
        odd = odd->link;
        even->link = odd->link;
        even = even->link;
    }
    odd->link = evenstart;
    if (odd->link != NULL)
    {
        even->link = NULL;
    }
}
void display(node *&head)
{
    node *n = head;
    while (n != NULL)
    {
        cout << n->data << "->";
        n = n->link;
    }
    cout << "NULL\n";
}
//delete kth node of a linked list from last in a single pass (:
node *dele_kth(node *head, int n)
{
    node*dummy =new node();
    dummy->link=head;
    node*fast=dummy,*slow=dummy;

    for(int i=0;i<n;i++)
       fast=fast->link;
    while(fast->link!=NULL){
        fast=fast->link;
        slow=slow->link;
    }
    slow->link=slow->link->link;
    return dummy;
}
int main()
{
    node *head = NULL;
    int arr[] = {7, 5, 9, 6, 2, 4};
    for (int i = 0; i < 6; i++)
    {
        insertAtEnd(head, arr[i]);
    }
    display(head);
    EvenAfterOdd(head);
    display(head);
    return 0;
}