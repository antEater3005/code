 #include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
};
node *head = NULL;
void InsertBeg(int val)
{
    node *ptr = new node();

    ptr->data = val;
    ptr->link = head;
    head = ptr;
}
void InsertEnd(int val)
{
    node *ptr = new node();
    node *temp = head;
    ptr->data = val;
    ptr->link = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = ptr;
    }
}
void DeleteBeg()
{
    if (head == NULL)
    {
        cout << "Empty List.";
    }
    else
    {
        node *ptr = head;
        head = head->link;
        free(ptr);
    }
}
void DeleteEnd()
{
    node *ptr, *prev;
    if (head == NULL)
    {
        cout << "Empty List.";
    }
    else if (head->link == NULL)
    {
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else
    {

        while (ptr->link != NULL)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = NULL;
        free(ptr);
    }
}

void FindLoop()
{
    cout << "here\n";
    node *fast = head, *slow = head;
    while (fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        slow = slow->link;
        if (slow == fast)
        {
            cout << "LOOP PRESENT"; // loop present.
        }
        else
        {
            cout << "NO LOOP";
        }
    }
}
void ReverseList()
{
    node *p = NULL, *c = head, *n  ;
    while (c != NULL)
    {
        n = c->link;

        c->link = p;
        p = c;
        c = n;
    }
    head = p;
}
// Not Working.
node *reverseByRecursion(node *head)
{
    if (head == NULL || head->link == NULL)
    {
        return head;
    }
    node *newhead = reverseByRecursion(head->link);
    head->link->link = head;
    head->link = NULL;
    return newhead;
}
int length(node *&head)
{
    node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->link;
        count++;
    }
    return count;
}
// Append k nodes to the start of the linked list.
node *Kappend(node *&head, int k)
{
    node *newHead;
    node *newTail;
    node *tail = head;
    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->link != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->link;
        count++;
    }
    newTail->link = NULL;
    tail->link = head;
    return newHead;
}
//Find the intersection point of two linked list;
int intersection(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->link;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }
}
void deleteNode(node *ptr)
{
    node *temp;
    temp = ptr->link;
    ptr->data = temp->data;
    ptr->link = temp->link;
    free(temp);
}
void intersect(node *& head1 ,node *&head2,int pos){
    node *temp1=head1;
    pos--;
    while(pos--){
        temp1 = temp1->link;
    }
    node *temp2=head2;
    while(temp2->link!=NULL){
        temp2=temp2->link;
    }temp2->link=temp1;
}
void PrintMid()
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        slow = slow->link;
    }
    cout << "The middle element is:" << slow->data << endl;
}
void display()
{
    node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->link;
    }
    cout << "NULL\n";
}
void display2(node *&head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->link;
    }
    cout << "NULL";
}
void EvenAfterOdd(node *head){
    
}
int main()
{
    node *ptr = NULL;
    InsertBeg(4);
    InsertBeg(2);
    InsertBeg(1);
    InsertEnd(3);
    InsertEnd(7);
     

    display();
    ReverseList( );
    display2( head);
    cout << "\nOK";
    return 0;
}