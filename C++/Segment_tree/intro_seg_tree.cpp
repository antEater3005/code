#include <bits/stdc++.h>
using namespace std;
// a segment tree is represented by an array only, the conceptual binary tree is there, which is only for understanding of the working of segment tree;
void create_segment_tree(vector<int> &segment_array, vector<int> &input_array, int low, int high, int pos)
{
    if (low == high)
    {
        segment_array[pos] = input_array[low];
        return;
    }
    int mid = low + (high - low) / 2;
    // call to create left subtree
    create_segment_tree(segment_array, input_array, low, mid, 2 * pos + 1);           // call for left child at
    create_segment_tree(segment_array, input_array, mid + 1, high, 2 * pos + 2);      // right child
    segment_array[pos] = min(segment_array[2 * pos + 1], segment_array[2 * pos + 2]); // take parent as minimum of the left and right child
}
int min_in_range(vector<int> &segment_array, int low, int high, int q_low, int q_high, int pos)
{
    if (q_low <= low && q_high >= high) // total overlap
        return segment_array[pos];      // return element at pos in segment_array
    if (q_low > high || q_high < low)   // no overlap
        return INT_MAX;                 // since its for minimum range query we return maximum value which cannot be our answer
    int mid = low + (high - low) / 2;
    // if there is a partial overlap
    return min(min_in_range(segment_array, low, mid, q_low, q_high, pos * 2 + 1), min_in_range(segment_array, mid + 1, high, q_low, q_high, pos * 2 + 2));
}
int main()
{
    vector<int> input = {-1, 2, -5, 3, 1, 0, 5, -9, 3};
    int n = input.size();
    int size_seg_t = (((n - 1) & n) ? pow(2, (int)log2(n) + 1) : n) * 2 - 1;
    vector<int> segment_array(size_seg_t, INT_MAX);

    create_segment_tree(segment_array, input, 0, n, 0);
    // for (auto i : segment_array)
    //     cout << i << " ";
    // cout << "\n";
    cout << min_in_range(segment_array, 0, n, 8, 8, 0);
    return 0;
}

class NumArray
{
    vector<int> segment_tree;
    int n;
    void create(vector<int> &segment_tree, vector<int> &nums, int low, int high, int pos)
    {
        if (low == high)
        {
            segment_tree[pos] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        create(segment_tree, nums, low, mid, pos * 2 + 1);
        create(segment_tree, nums, mid + 1, high, pos * 2 + 2);
        segment_tree[pos] = segment_tree[pos * 2 + 1] + segment_tree[pos * 2 + 2];
    }
    void update_(vector<int> &segment_tree, int low, int high, int pos, int insert, int val)
    {
        if (low == high && high == insert)
        {
            segment_tree[pos] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (insert >= low && insert <= mid)
            update_(segment_tree, low, mid, pos * 2 + 1, insert, val);
        else
            update_(segment_tree, mid + 1, high, pos * 2 + 2, insert, val);
        segment_tree[pos] = segment_tree[pos * 2 + 1] + segment_tree[pos * 2 + 2];
    }
    int range_sum(vector<int> &segment_tree, int low, int high, int q_low, int q_high, int pos)
    {
        if (low >= q_low && high <= q_high)
            return segment_tree[pos];
        if (q_low > high || q_high < low)
            return 0;
        int mid = low + (high - low) / 2;
        return range_sum(segment_tree, low, mid, q_low, q_high, pos * 2 + 1) +
               range_sum(segment_tree, mid + 1, high, q_low, q_high, pos * 2 + 2);
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        int size = ((n & (n - 1)) ? pow(2, (int)log2(n) + 1) : n) * 2 - 1;
        segment_tree.resize(size, 0);
        create(segment_tree, nums, 0, n - 1, 0);
    }

    void update(int index, int val)
    {
        update_(segment_tree, 0, n - 1, 0, index, val);
    }

    int sumRange(int left, int right)
    {
        return range_sum(segment_tree, 0, n - 1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class maxRepeating
{
    // Finding the maximum and the number of times it appears
    vector<pair<int, int>> seg_tree;
    vector<int> nums;
    pair<int, int> combine(pair<int, int> a, pair<int, int> b) // combine two pairs
    {
        if (a.first > b.first)
            return a;
        else if (b.first > a.first)
            return b;
        else
            return {a.first, a.second + b.second};
    }
    // create the segment tree
    pair<int, int> create_seg_tree(int low, int high, int pos) // pos means the position of the vertex in the seg_tree array
    {
        if (low == high)
            return seg_tree[pos] = {nums[low], 1};
        int mid = low + (high - low) / 2;
        return seg_tree[pos] = (create_seg_tree(low, mid, pos * 2 + 1), create_seg_tree(mid + 1, high, pos * 2 + 2));
    }
    // get max Value
    pair<int, int> get_max_util(int q_low, int q_high, int low, int high, int pos = 0)
    {
        if (low <= q_low && high >= q_high)
            return seg_tree[pos];
        if (low > q_low || high < q_high)
            return {-1, 0};
        int mid = low + (high - low) / 2;
        return combine(get_max_util(q_low, q_high, low, mid, pos * 2 + 1), get_max_util(q_low, q_high, mid + 1, high, pos * 2 + 2));
    }

    // update value at a specific position
    pair<int, int> update_util(int low, int high, int val, int insert_pos, int pos = 0)
    {
        if (low == high && low == insert_pos)
            return seg_tree[pos] = {val, 1};
        int mid = low + (high - low) / 2;
        if (insert_pos >= low && insert_pos <= high)
            return seg_tree[pos] = combine(update_util(low, mid, val, insert_pos, pos * 2 + 1), seg_tree[pos * 2 + 2]);
        return seg_tree[pos] = combine(seg_tree[pos * 2 + 1], update_util(mid + 1, high, val, insert_pos, pos * 2 + 2));
    }

public:
    maxRepeating(vector<int> &arr)
    {
        int n = arr.size();
        nums = arr;
        seg_tree.resize(4 * n);
        create_seg_tree(0, n - 1, 0);
    }
    pair<int, int> get_max(int low, int high)
    {
        return get_max_util(low, high, 0, nums.size() - 1);
    }
    // update
    void update(int pos, int val)
    {
        update_util(0, nums.size() - 1, val, pos);
    }
};

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// Segment Tree with Lazy Propagation
/*
  We use two trees Lazy Tree to store the values to be updated
  Second is the original segment tree
*/
