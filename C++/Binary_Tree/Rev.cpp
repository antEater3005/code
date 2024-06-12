#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data)
    {
        data = data;
        right = NULL;
        left = NULL;
    }
    Node *build_tree(Node *root)
    {
        int data;
        cin >> data;
        if (data == -1)
            return NULL;
        root = new Node(data);
        root->left = build_tree(root->left);
        root->right = build_tree(root->right);
    }
};
void level_order(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}
int main()
{

    return 0;
}