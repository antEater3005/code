#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int v, Node *n = NULL)
    {
        val = v;
        next = n;
    }
};
class MyLinkedList
{
    Node *head, *tail;
    int len;

public:
    MyLinkedList()
    {
        head = tail = NULL;
        len = 0;
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    int get(int index)
    {
        if (index >= len)
            return -1;
        int idx = 0;
        Node *temp = head;
        while (idx < index)
            temp = temp->next, idx++;
        return temp->val;
    }

    void addAtHead(int val)
    {
        if (!head && !tail)
            head = tail = new Node(val);
        else
            head = new Node(val, head);
        ++len;
        // print();
    }

    void addAtTail(int val)
    {
        if (!head && !tail)
            head = tail = new Node(val);
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }

        ++len;
    }

    void addAtIndex(int index, int val)
    {
        if (index > len)
            return;
        if (index == 0)
        {
            addAtHead(val);
            ++len;
            return;
        }
        Node *temp = head;
        int idx = 0;
        while (idx < index - 1)
        {
            idx++;
            temp = temp->next;
        }
        if (temp == tail)
        {
            temp->next = new Node(val);
            tail = temp->next;
            ++len;
            return;
        }
        temp->next = new Node(val, temp->next);
        ++len;
    }

    void deleteAtIndex(int index)
    {
        if (index >= len)
            return;
        if (index == 0)
        {
            Node *temp = head;
            if (len == 1)
                head = tail = NULL;
            else
                head = head->next;
            delete (temp);
            --len;
            return;
        }
        Node *temp = head;
        int idx = 0;
        while (idx < index - 1)
        {
            idx++;
            temp = temp->next;
        }
        Node *t = temp->next;
        temp->next = t->next;
        if (t == tail)
            tail = temp;
        delete (t);
        --len;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{

    return 0;
}