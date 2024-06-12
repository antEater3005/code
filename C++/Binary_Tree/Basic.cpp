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
struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
info largestBSTinBT(node *root)
{
    if (!root)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (!root->left && !root->right)
        return {1, root->data, root->data, 0, true};
    info left = largestBSTinBT(root->left);
    info right = largestBSTinBT(root->right);
    info curr;
    curr.size = (1 + left.size + right.size);
    if (left.isBST && right.isBST && left.max < root->data && right.min > root->data)
    {
        curr.min = min(left.min, min(right.min, root->data));
        curr.max = max(left.max, max(right.max, root->data));
        curr.ans = curr.size;

        curr.isBST = true;
        return curr;
    }
    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;
    return curr;
}
// checks wheather two trees are same or not
bool IsSame(node *root1, node *root2)
{
    if (!root1 && !root2)
        return true;
    else if (!root1 || !root2)
        return false;
    else
    {
        bool a = root1->data == root2->data;
        bool b = IsSame(root1->left, root2->right);
        bool c = IsSame(root1->left, root2->left);
        return (a && b && c);
    }
}
vector<vector<int>> VerticalOrderTraversal(node *root)
{
    map<int,map<int,multiset<int>>>nodes;
        queue<pair<node*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            node*node=curr.first;
            int x=curr.second.first,y=curr.second.second;
            nodes[x][y].insert(node->data);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>res;
        for(auto a:nodes){
            vector<int>temp;
            for(auto s:a.second){
                temp.insert(temp.end(),s.second.begin(),s.second.end());
            }
            res.push_back(temp);
        }
        return res;
}
int main()
{
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(10);
    root->left->right = new node(25);
    root->left->right->left = new node(21);
    root->left->right->right = new node(28);

    // preOrder(root);
    // cout << endl;
    // info sol = largestBSTinBT(root);
    // cout << sol.ans;
     vector<vector<int>>ans=VerticalOrderTraversal(root);
   for(int i=0;i<ans.size();i++){
       for(int j=0;j<ans[i].size();j++){
           cout<<ans[i][j]<<" ";
       }
   }

    return 0;
}
