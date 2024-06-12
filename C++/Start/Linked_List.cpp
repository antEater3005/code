//  In a linked list one cannot access data randomly, we need to traverse to all the data members.
// The time complexity of the linked list is O(N) i.e., order of N,where N is the no of elements in linked list,And O(1)in worst case.
// Insertion and deletion in linked list is easy as compared to the array.[array has a time complexity of O(1).]
// Binary search is not possible,because we cannot directly access the middle element.
// Types of linked list 1>> Singly linked list 2>> Doubly linked list 3>> Circular linked list 4>> Doubly circular linked list.
//>> In a singly linked list we can only traverse in the forward direction.
//>> A doubly linked list contains two pointer and a data, we can traverse in both direction.
//>> A singlycircular linked list is same as the singly linked list except the last element has pointer pointing to the first element.
#include <iostream>
using namespace std;
// SINGLY LINKED LIST
class node
{
public:
    int a;
    class node *next;
};
//DOUBLY LINKED LIST
class node2{
public:
int data;
class node2 *next;
class node2 *prev;
};
//CIRCULAR LINKED LIST
int main()
{
    return 0;
}