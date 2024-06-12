// A Binary tree is a tree in which each node has utmost 2 child
#include "bits/stdc++.h"
using namespace std;
class BSTnode
{
public:
    int data;
    BSTnode *left;
    BSTnode *right;
    BSTnode(int val)
    {
        data = val;
        right = left = NULL;
    }
};
BSTnode *insert(BSTnode *root, int data)
{
    if (root == NULL)
        root = new BSTnode(data);
    else if (root->data >= data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
bool Bsearch(BSTnode *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (root->data >= data)
        return Bsearch(root->left, data);
    else
        return Bsearch(root->right, data);
}
int searchMin(BSTnode *root) // Iterative method
{
    if (root == NULL)
    {
        cout << "ERROR\n";
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int findMin(BSTnode *root) // Recursive method
{
    if (root == NULL)
    {
        cout << "ERROR\n";
        return -1;
    }
    else if (root->left == NULL)
        return root->data;
    return findMin(root->left);
}
int searchMax(BSTnode *root) //Iterative method
{
    if (root == NULL)
    {
        cout << "Error\n";
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
int findMax(BSTnode *root)
{
    if (root == NULL)
    {
        cout << "ERROR\n";
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return findMax(root->right);
}
// Height of a Binary Tree;
int Height(BSTnode *root)
{
    if (root == NULL)
        return -1;
    return 1 + max(Height(root->left), Height(root->right));
}
// Level Order Traversal
vector<int> LevelOrder(BSTnode *root) // space complexity in best case is O(1) and in worst case O(N);
{
    vector<int> res = {};
    if (root == NULL)
        return res;
    queue<BSTnode *> q;
    q.push(root);
    while (!q.empty())
    {
        BSTnode *a = q.front();
        q.pop();

        if (a != NULL)
        {
            res.push_back(a->data);
            if (a->left)
                q.push(a->left);
            if (a->right)
                q.push(a->right);
        }
    }
    return res;
}
// Preorder Traversal;
void Preorder(BSTnode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
// Inorder Traversal
// The Inorder Traversal of a Binary Search Tree gives the elements in sorted order.
void Inorder(BSTnode *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
// Postorder Traversal
void Postorder(BSTnode *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
bool isSubtreeLesser(BSTnode *root, int val)
{
    if (root == NULL)
        return true;
    if (root->data <= val && isSubtreeLesser(root->left, val) && isSubtreeLesser(root->right, val))
        return true;
    return false;
}
bool isSubtreeGreater(BSTnode *root, int val)
{
    if (root == NULL)
        return true;
    if (root->data > val && isSubtreeGreater(root->left, val) && isSubtreeGreater(root->right, val))
        return true;
    return false;
}
bool isBinarySearchTree(BSTnode *root) // Time complexity is O(N^2);N=number of Nodes;
{
    if (root == NULL)
        return true;
    if (isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data) && isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
        return true;
    else
        return false;
}
bool isBSTUtility(BSTnode *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true;
    if (root->data < maxVal && root->data > minVal && isBSTUtility(root->left, minVal, root->data) && isBSTUtility(root->right, root->data, maxVal))
        return true;
    return false;
}
bool isBSTmain(BSTnode *root) // Time complexity is O(N); N=Number of nodes;
{
    return isBSTUtility(root, INT_MIN, INT_MAX);
}
BSTnode *FindMinRoot(BSTnode *root) // Iterative method
{
    if (root == NULL)
    {
        return root;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
// Delete a Node;
BSTnode *Delete(BSTnode *root, int toDel)
{
    if (root == NULL)
        return root;
    else if (root->data > toDel)
        root->left = Delete(root->left, toDel);
    else if (root->data < toDel)
        root->right = Delete(root->right, toDel);
    else
    {
        if (root->right == NULL && root->left == NULL)
        {
            delete (root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            BSTnode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            BSTnode *temp = root;
            root = root->left;
            delete temp;
        }
        // Case:3: when the node to be deleted have two child;
        else
        {
            BSTnode *min = FindMinRoot(root->right);
            root->data = min->data;
            root->right = Delete(root->right, min->data);
        }
    }
    return root;
}
BSTnode *BSTsearch(BSTnode *root, int data) // TC=O(H);
{
    if (root == NULL)
        return root;
    else if (root->data == data)
        return root;
    else if (root->data >= data)
        return BSTsearch(root->left, data);
    else
        return BSTsearch(root->right, data);
}
BSTnode *GetSuccessor(BSTnode *root, int n) // TC=O(H);
{
    // search the node containing the data n
    BSTnode *curr = BSTsearch(root, n); // TC=O(H);
    if (curr == NULL)
        return NULL;
    // Case 1:Node has right subtree;
    if (curr->right != NULL)
    {
        return FindMinRoot(curr->right);
    }
    // Case 2: If there is no right subtree;  // TC=O(H);
    else
    {
        BSTnode *ancestor = root;
        BSTnode *successor = NULL;
        while (ancestor != curr)
        {
            if (curr->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {

                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
// Construct BST from preorder traversal of the tree to be constructed;
BSTnode *consBSTpre(int preorder[], int *preorderidx, int key, int min, int max, int n)
{
    if (*preorderidx >= n)
        return NULL;
    BSTnode *root = NULL;
    if (key > min && key < max)
    {
        root = new BSTnode(key);
        *preorderidx += 1;
        if (*preorderidx < n)
        {
            root->left = consBSTpre(preorder, preorderidx, preorder[*preorderidx], min, key, n);
        }
        if (*preorderidx < n)
        {
            root->right = consBSTpre(preorder, preorderidx, preorder[*preorderidx], key, max, n);
        }
    }
    return root;
}
// Construct balanced BST from a sorted array; a sorted array is same as the inorder traversal of a BST;
BSTnode *ConsBstInorder(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (end + start) / 2;
    BSTnode *root = new BSTnode(arr[mid]);
    root->left = ConsBstInorder(arr, start, mid - 1);
    root->right = ConsBstInorder(arr, mid + 1, end);
    return root;
}
vector<BSTnode *> constructTrees(int start, int end)
{
    vector<BSTnode *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<BSTnode *> left = constructTrees(start, i - 1);
        vector<BSTnode *> right = constructTrees(i + 1, end);
        for (int j = 0; j < left.size(); j++)
        {
            BSTnode *tleft = left[j];
            for (int k = 0; k < right.size(); k++)
            {
                BSTnode *tright = right[k];
                BSTnode *node = new BSTnode(i);
                node->left = tleft;
                node->right = tright;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
int main()
{
    BSTnode *root = NULL;
    int data[] = {10, 20, 30, 40, 50};
    // int preorderidx=0;
    // root = consBSTpre(data, &preorderidx, data[preorderidx], INT_MIN, INT_MAX, 5);
    // vector<int> data = {15, 10, 20, 25, 8, 12, 1};
    // for (auto i : data)
    //     root = insert(root, i);

    // root = insert(root, 15);
    // root = insert(root, 10);
    // root = insert(root, 20);
    // root = insert(root, 25);
    // root = insert(root, 8);
    // root = insert(root, 12);
    // root = insert(root, 1);
    // Delete(root, 20);
    // int num;
    // cout << "Enter a number to search\n";
    // cin >> num;
    // if (Bsearch(root, num) == true)
    // {
    //     cout << "Found\n";
    // }
    // else
    //     cout << "Not found\n";
    // cout << searchMin(root);
    // cout << "  " << findMin(root);
    // cout << endl;
    // cout << searchMax(root);
    // cout << "  " << findMax(root) << "\n";
    // cout << Height(root) << "\n";
    // for (auto i : LevelOrder(root))
    //     cout << i << " ";
    // cout << "\n";
    // Preorder(root);
    // cout << endl;
    // Inorder(root);
    // cout << endl;
    // Postorder(root);
    // if (isBinarySearchTree(root))
    // {
    //     cout << "Yes";
    // }
    // else
    //     cout << "No";

    // if (isBSTmain(root))
    // {
    //     cout << "Yes";
    // }
    // else
    //     cout << "No";
    // return 0;
    // cout << GetSuccessor(root, 8)->data;
    // int s = 0, e = 4;
    // root = ConsBstInorder(data, s, e);
    vector<BSTnode *> ToT = constructTrees(1, 3);
    for (auto a : ToT)
    {
        cout << a << " ";
        Preorder(a);
        cout << endl;
    }
    return 0;
}