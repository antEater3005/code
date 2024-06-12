#include "bits/stdc++.h"
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void Preorder(node *root) 
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(node *root) 
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
void Inorder(node *root) 
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void LevelOrder(node *root) // This a iterative method.
{
    if (root == NULL)
        return;
    queue<node *> qu;
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty())
    {
        node *n = qu.front();
        qu.pop();
        if (n != NULL)
        {
            cout << n->data << " ";
            if (n->left)
                qu.push(n->left);
            if (n->right)
                qu.push(n->right);
        }
        else if (!qu.empty())
            qu.push(NULL);
    }
}
// Time complexity of this function is order of N, where N is the total no of nodes in the tree;
void PreorderIterative1(node *root) // method 1
{
    if (root == NULL)
        return;
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *a = st.top();
        cout << a->data << " ";
        st.pop();
        if (a->right)
            st.push(a->right);
        if (a->left)
            st.push(a->left);
    }
}
// Iterative Preorder traversal.
void PreorderIterative2(node *root) // method 2.
{
    if (root == NULL)
        return;
    stack<node *> st;
    node *curr = root;
    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            if (curr->right)
                st.push(curr->right);
            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}
void InorderIterative(node *root)
{
    if (root == NULL)
        return;
    stack<node *> st;
    node *curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
void iterativePostorder(node *root)
{
    if (root == NULL)
        return;
    stack<node *> s1, s2;
    node *curr;
    s1.push(root);
    while (!s1.empty())
    {
        curr = s1.top();
        s2.push(curr);
        s1.pop();
        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }
    while (!s2.empty())
    {
        node *x = s2.top();
        cout << x->data << " ";
        s2.pop();
    }
}
int countNode(node *root) // number of nodes in the binary tree;
{
    if (root == NULL)
        return 0;

    return countNode(root->left) +
           countNode(root->right) + 1;
}
int nodeSum(node *root)
{
    if (root == NULL)
        return 0;
    return nodeSum(root->left) + nodeSum(root->right) + root->data;
}
// Height of binary tree; Time Complexity of below function is Order Of N "O(N)";
int calcHeight(node *root)
{
    if (root == NULL)
        return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    return max(lHeight, rHeight) + 1;
}
// Diameter of Binary tree; Below function has a time complexity of O(N^2) N-square;
int treeDiameter(node *root)
{
    if (root == NULL)
        return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;
    int lDiameter = calcHeight(root->left);
    int rDiameter = calcHeight(root->right);
    return max(max(currDiameter, lDiameter), rDiameter);
}
// Diameter calculation optimized; time complexity of below function is O(N);
int calcDiameter(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(root->left, &lh);
    int rDiameter = calcDiameter(root->right, &rh);
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDiameter, max(lDiameter, rDiameter));
}

// Its a utility fxn for main LCA function
bool getpath(node *root, int key, vector<int> &path)
{
    if (!root)
        return false;
    path.push_back(root->data);
    if (root->data == key)
        return true;
    if (getpath(root->left, key, path) || getpath(root->right, key, path))
        return true;
    path.pop_back();
    return false;
}
// Below function finds the Lowest Common Ancestor in the binary tree
int LCA(node *root, int n1, int n2)
{
    if (n1 == n2)
        return n1;
    vector<int> path1, path2;
    if (!getpath(root, n1, path1) || !getpath(root, n2, path2))
        return -1;
    int pc; // pc means path change;
    for (int i = 0; i < path1.size() && path2.size(); i++)
        if (path1[i] != path2[i])
        {
            pc = path1[i - 1];
            break;
        }
    return pc;
}
// Second function to find the Lowest Common Ancestor of two nodes;
node *LCA2(node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    node *leftLCA = LCA2(root->left, n1, n2);
    node *rightLCA = LCA2(root->right, n1, n2);
    if (rightLCA && leftLCA)
        return root;
    if (leftLCA != NULL)
        return leftLCA;
    else
        return rightLCA;
}
// The  "Sum Replacement": it replaces the nodes data from the sum of nodes data of their subtree;
void sumReplace(node *root) // TC=O(N);
{
    if (root == NULL)
        return;
    sumReplace(root->left);
    sumReplace(root->right);
    if (root->left != NULL)
        root->data += root->left->data;
    if (root->right != NULL)
        root->data += root->right->data;
}
// Node to Root path;N2R means node to root; if you want the nodes of the paths then change the input vector type to(node*) and push the roots instead of the root->data;
bool N2R(node *root, int target, vector<int> &N2Rpath) // Target means the node from which the path to find
{
    if (!root)
        return false;
    if (root->data == target)
    {
        N2Rpath.push_back(root->data);
        return true;
    }
    if (N2R(root->left, target, N2Rpath))
    {
        N2Rpath.push_back(root->data);
        return true;
    }
    if (N2R(root->right, target, N2Rpath))
    {
        N2Rpath.push_back(root->data);
        return true;
    }
    return false;
}
// To find a targeted node pointer in a binary tree;
node *Tar(node *root, int target)
{
    if (!root)
        return NULL;
    if (root->data == target)
        return root;
    Tar(root->left, target);

    Tar(root->right, target);
}
// PKD means print k nodes downward of a targeted node;
void PKND(node *Node, int k)
{
    if (!Node || k < 0)
        return;
    if (k == 0)
    {
        cout << Node->data << " ";
    }
    PKND(Node->left, k - 1);
    PKND(Node->right, k - 1);
}
// This function that stores the path from root to leaf in a string whose sum of node data are b/w a given range;
void PrintRange(node *root, int sum, int low, int high, string path)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        sum += root->data;
        if (sum >= low && sum <= high)
        {
            cout << path + to_string(root->data) << endl;
        }
        return;
    }
    PrintRange(root->left, sum + root->data, low, high, path + to_string(root->data) + " ");
    PrintRange(root->right, sum + root->data, low, high, path + to_string(root->data) + " ");
}
//  Balanced Binary Tree : A binary tree is said to balanced if the difference of heights of its left and right subtree is less than or equal to one.
bool isBalanced(node *root)
{
    if (!root)
        return true;
    if (!isBalanced(root->left))
        return false;
    if (!isBalanced(root->right))
        return false;
    int rh = calcHeight(root->right); // from the above height function.
    int lh = calcHeight(root->left);
    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}
// Utility function
int findDist(node *root, int n, int d)
{
    if (!root)
        return -1;
    if (root->data == n)
    {
        return d;
    }
    int left = findDist(root->left, n, d + 1);
    if (left != -1)
    {
        return left;
    }
    int right = findDist(root->right, n, d + 1);
}
// the function distBtwNodes return the distance between two node .
int distBtwNodes(node *root, int n1, int n2)
{
    node *lca = LCA2(root, n1, n2);
    int d1 = findDist(lca, n1, 0); // utility function to find the distance between lca and the nodes.
    int d2 = findDist(lca, n2, 0);
    return d1 + d2;
}
// Flatten binary tree: it changes a binary tree in the form of linked list having the address of the next subtree in the right and left contains NULL ,the order of linked list is preorder.
void flatten(node *root) // Recursive Method
{
    if (!root || (!root->right && !root->left))
        return;
    if (root->left)
    {
        flatten(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        node *t = root->right;
        while (t->right)
            t = t->right;
        t->right = temp;
    }
    flatten(root->right);
}
// Flatten Function Iterative method;
void flattenIt(node *root)
{
    if (!root)
        return;
    while (root)
    {
        if (root->left)
        {
            node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            temp->right = root->right;
            root->right = root->left;
            int x = root->right->data;
            root->left = NULL;
        }
        root = root->right;
    }
}
// PrintK: this function prints the data of the of the nodes which are k distance from the target node in its subtree;
// the following function is a utility function for PrintK function;
// Case:1;
void printKsub(node *root, int k) // here the parameter root pointer is the target node.  UTILITY FUNCTION.
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printKsub(root->left, k - 1);
    printKsub(root->right, k - 1);
}
// Case:2;when the kth node present in the ancestor node;
int printKanc(node *root, int target, int k)

{
    if (root == NULL)
        return -1;
    if (root->data == target)
    {
        printKsub(root, k);
        return 0;
    }
    int dl = printKanc(root->left, target, k);
    if (dl != -1)
    {
        if ((dl + 1) == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKsub(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printKanc(root->right, target, k);
    if (dr != -1)
    {
        if ((dr + 1) == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKsub(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}
// Maximum path sum : its the path which gives the maximum sum of nodes;
int maxPathSumUtil(node *root, int &ans)
{
    if (!root)
        return 0;
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);
    int nodMax = max(max(root->data, root->data + left + right),
                     max(root->data + left, root->data + right));
    ans = max(ans, nodMax);
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}
int maxPathSum(node *root)
{
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}
// This function is a special type of level order traversal in which consecutive levels are printed in left to right & right to left fashion.
void ZigzagTrav(node *root)
{
    if (!root)
        return;
    stack<node *> curr, next;
    bool l2r = true;
    curr.push(root);
    while (!curr.empty())
    {
        node *temp = curr.top();
        curr.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (l2r)
            {
                if (temp->left)
                    next.push(temp->left);
                if (temp->right)
                    next.push(temp->right);
            }
            else
            {
                if (temp->right)
                    next.push(temp->right);
                if (temp->left)
                    next.push(temp->left);
            }
        }
        if (curr.empty())
        {
            swap(curr, next);
            l2r = !l2r;
        }
    }
}
vector<int> zigZagTraversal(node *root)
{
    vector<int> v;
    if (!root)
        return v;
    stack<node *> curr, next;
    bool l2r = true;
    curr.push(root);
    while (!curr.empty())
    {
        node *temp = curr.top();
        curr.pop();
        if (temp)
        {
            v.push_back(temp->data);

            if (l2r)
            {
                if (temp->left)
                    next.push(temp->left);
                if (temp->right)
                    next.push(temp->right);
            }
            else
            {
                if (temp->right)
                    next.push(temp->right);
                if (temp->left)
                    next.push(temp->left);
            }
        }
        if (curr.empty())
        {
            swap(curr, next);
            l2r = !l2r;
        }
    }
    return v;
}
// This function checks whether two trees are identical or not.
bool isIdentical(node *root1, node *root2)
{
    if (!root1 && !root2)
        return true;
    else if (!root2 || !root2)
        return false;
    else
    {
        bool a = root1->data == root2->data;
        bool b = isIdentical(root1->left, root2->left);
        bool c = isIdentical(root1->right, root2->right);
        if (a && b && c)
            return true;
        return false;
    }
}
int getLevelDiff(node *root)
{
    if (!root)
        return 0;
    int eSum = 0;
    int Osum = 0;
    bool flag = true;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            node *temp = q.front();
            q.pop();
            if (flag)
                eSum += temp->data;
            else
                Osum += temp->data;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        flag = !flag;
    }
    return eSum - Osum;
}
// GFG Question link:"https://practice.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1/?company[]=Amazon&company[]=Amazon&problemStatus=unsolved&page=1&query=company[]AmazonproblemStatusunsolvedpage1company[]Amazon#"
void M16(node *root, long long int &ans, int a)
{
    if (!root)
        return;
    else if (!root->left && !root->right)
    {
        ans += a * 10 + root->data;
    }
    a = a * 10 + root->data;
    M16(root->left, ans, a);

    M16(root->right, ans, a);
}

long long treePathsSum(node *root)
{
    int long long ans = 0;
    int a = 0;
    M16(root, ans, a);
    return ans;
}

// Vertical Order Traversal:LeetCode Problem: link:https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
vector<vector<int>> VerticalOrderTraversal(node *root)
{
    if (!root)
        return {};
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr.second.first, y = curr.second.second;
        nodes[x][y].insert(curr.first->data);
        if (curr.first->left)
            q.push({curr.first->left, {x - 1, y + 1}});
        if (curr.first->right)
            q.push({curr.first->right, {x + 1, y + 1}});
    }
    vector<vector<int>> result;
    for (auto a : nodes)
    {
        vector<int> temp;
        for (auto s : a.second)
        {
            temp.insert(temp.end(), s.second.begin(), s.second.end());
        }
        result.push_back(temp);
    }
    return result;
}

/* ================== VIEWS OF BINARY TREE ======================*/
// 1. Top View of Binary Tree;
vector<int> topView(node *root)
{
    if (!root)
        return {};
    map<int, int> nodes;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        node *currNode = curr.first;
        int x = curr.second;
        if (nodes.find(x) == nodes.end())
            nodes[x] = currNode->data;
        if (currNode->left)
            q.push({currNode->left, x - 1});
        if (currNode->right)
            q.push({currNode->right, x + 1});
    }
    vector<int> ans;
    for (auto a : nodes)
    {
        ans.push_back(a.second);
    }
    return ans;
}
// 2. Left view of binary tree->we pass level which always starts with 0;
// method 2
void leftView(node *root, vector<int> &LeftView, int level = 0)
{
    if (!root)
        return;
    if (LeftView.size() == level)
        LeftView.push_back(root->data);
    leftView(root->left, LeftView, level + 1);
    leftView(root->right, LeftView, level + 1);
}
// method 2
vector<int> leftView2(node *root)
{
    if (!root)
        return {};
    queue<node *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        int n = q.size();
        ans.push_back(q.front()->data);
        while (n--)
        {
            node *curr = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            q.pop();
        }
    }
    return ans;
}
// 3. RIGHT VIEW OF BT
// method 1;
void rightView(node *root, vector<int> &RightView, int level)
{
    if (!root)
        return;
    if (RightView.size() == level)
        RightView.push_back(root->data);
    rightView(root->right, RightView, level + 1);
    rightView(root->left, RightView, level + 1);
}
// method 2;
vector<int> rightView2(node *root)
{
    if (!root)
        return {};
    queue<node *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            node *curr = q.front();
            if (n == 0)
            {
                ans.push_back(curr->data);
            }
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            q.pop();
        }
    }
    return ans;
}

// Given the root of a binary tree, return the bottommost & leftmost value in the last row of the tree
int leftMostNode(node *root)
{
    if (!root)
        return -1;
    queue<node *> q;
    q.push(root);
    int ans;
    while (!q.empty())
    {
        int n = q.size();
        ans = q.front()->data;
        while (n--)
        {
            node *curr = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            q.pop();
        }
    }
    return ans;
}

int main()
{
    node *root = new node(2);
    root->left = new node(4);
    root->left->left = new node(9);
    root->left->right = new node(3);
    root->right = new node(6);
    root->right->left = new node(8);
    root->right->right = new node(7);
    root->right->left->right = new node(1);

    // cout << "Preorder:";
    // Preorder(root);
    // cout << endl;
    // cout << "Postorder:";
    // Postorder(root);
    // cout << endl;
    // cout << "Inorder:";
    // Inorder(root);
    // cout << "\nIterativeInorder";
    // InorderIterative(root);
    // cout << endl;
    // cout << "LevelOrder:";
    // LevelOrder(root);
    // cout << endl;
    // cout << "PreorderIterative1:";
    // PreorderIterative1(root);
    // cout << "\nPreorderIterative2:";
    // PreorderIterative2(root);
    // cout << "\nThe no of Nodes in the tree is:" << countNode(root) << endl;
    // cout << "Sum of all the nodes in the binary tree:" << nodeSum(root) << endl;
    // cout << "Height of Binary Tree:" << calcHeight(root) << endl;
    // iterativePostorder(root);
    // cout << endl;
    // cout << treeDiameter(root) << endl;
    // int height = 0;
    // cout << calcDiameter(root, &height);
    // cout << endl
    //      << "The LCA is: " << LCA2(root, 1, 7)->data;
    // sumReplace(root);
    // cout << "\n";
    // Preorder(root);
    // if (isBalanced(root))
    //     cout << "YES";
    // else
    //     cout << "NO";
    // cout << distBtwNodes(root, 2, 1);

    // flattenIt(root);

    // while (root)
    // {
    //     cout << root->data << " ";
    //     root = root->right;
    // }
    // node*tar=root->right;
    //  printKanc(root, 6,1);

    // vector<int> ans;
    // if (N2R(root, 1, ans))
    // {
    //     cout << "True\n";
    //     for (auto a : ans)
    //     {
    //         cout << a << " ";
    //     }
    // }
    // else
    //     cout << "False";

    // node*target=Tar(root,2);
    // PKND(target,2);

    // PrintRange(root, 0, 10, 20, "");
    //  cout << maxPathSum(root);

    // VerticalOrderTraversal check
    // vector<vector<int>> ans = VerticalOrderTraversal(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    // }

    // TOP VIEW
    // vector<int> TopView = topView(root);
    // for (auto a : TopView)
    //     cout << a << " ";

    // LEFT VIEW
    // vector<int> LeftView;
    // leftView(root, LeftView, 0);
    // for (auto a : LeftView)
    //     cout << a << " ";

    // LEFT VIEW
    // vector<int> RightView = leftView2(root);
    // for (auto a : RightView)
    //     cout << a << " ";
    cout << leftMostNode(root);
    return 0;
}