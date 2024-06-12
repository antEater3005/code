#include <bits/stdc++.h>
using namespace std;

// For minimum in interval

class Segment_Tree
{
    vector<int> seg_tree, lazy_tree, nums;
    int createTree(int low, int high, int pos)
    {
        if (low == high)
            return seg_tree[pos] = nums[low];
        int mid = low + (high - low) / 2;
        return seg_tree[pos] = min(createTree(low, mid, pos * 2 + 1), createTree(mid + 1, high, pos * 2 + 2));
    }

public:
    Segment_Tree(vector<int> &arr)
    {
        int n = arr.size();
        seg_tree.resize(n * 4, 0);
        lazy_tree.resize(n * 4, 0);
        nums = arr;
        createTree(0, n - 1, 0);
    }
    // increment value by delta from start_idx to end_idx
    void update_range(int low, int high, int start_idx, int end_idx, int delta, int pos)
    {
        if (low > high)
            return;
        // make the propagation to the left and right child nodes
        if (lazy_tree[pos] != 0)
        {
            seg_tree[pos] += lazy_tree[pos];
            if (low != high)
            {
                lazy_tree[pos * 2 + 1] += delta;
                lazy_tree[pos * 2 + 2] += delta;
            }
            lazy_tree[pos] = 0;
        }

        // no overLap
        if (start_idx > high || end_idx < low)
            return;
        // Total overlap
        if (start_idx >= low && end_idx <= high)
        {
            seg_tree[pos] += delta;
            if (low != high)
            {
                lazy_tree[pos * 2 + 1] += delta;
                lazy_tree[pos * 2 + 2] += delta;
            }
            return;
        }
        // partial Overlap
        int mid = low + (high - low) / 2;
        update_range(low, mid, start_idx, end_idx, delta, pos * 2 + 1);
        update_range(mid + 1, high, start_idx, end_idx, delta, pos * 2 + 2);
        seg_tree[pos] = min(seg_tree[pos * 2 + 1], seg_tree[pos * 2 + 2]);
    }

    // get min in range
    int get_min_in_range(int low, int high, int query_low, int query_high, int pos)
    {
        if (low > high)
            return INT_MAX;
        // propagate the pending updates
        if (lazy_tree[pos] != 0)
        {
            seg_tree[pos] += lazy_tree[pos];
            if (low != high)
            {
                lazy_tree[pos * 2 + 1] += lazy_tree[pos];
                lazy_tree[pos * 2 + 2] += lazy_tree[pos];
            }
            lazy_tree[pos] = 0;
        }

        // no overlap
        if (query_low > high || query_high < low)
            return INT_MAX;

        // Total overlap
        if (query_low >= low && query_high <= high)
            return seg_tree[pos];

        // Partial overlap
        int mid = low + (high - low) / 2;
        return min(get_min_in_range(low, mid, query_low, query_high, pos * 2 + 1), get_min_in_range(mid + 1, high, query_low, query_high, pos * 2 + 2));
    }
};

int main()
{

    return 0;
}