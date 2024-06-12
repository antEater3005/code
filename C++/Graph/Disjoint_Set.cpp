#include <bits/stdc++.h>
using namespace std;

class disjoint_set
{
    vector<int> parent;
    vector<int> rank;

public:
    disjoint_set(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i, rank[i] = 0;
    }

    int find_parent(int n)
    {
        if (n == parent[n])
            return n;
        return parent[n] = find_parent(parent[n]); // Path compression
    }
    void union_nodes(int u, int v) // Union by rank
    {
        int parent_of_u = find_parent(u);
        int parent_of_v =find_parent(v);
        if (rank[parent_of_u] > rank[parent_of_v])
            parent[parent_of_v] = parent_of_u;
        else if (rank[parent_of_u] < rank[parent_of_v])
            parent[parent_of_u] = parent_of_v;
        else
        {
            parent[parent_of_u] = parent_of_v;
            rank[parent_of_v] += 1;
        }
    }
};
int main()
{
    disjoint_set set(8);
    cout << set.find_parent(5);

    set.union_nodes(1, 2);
    set.union_nodes(2, 3);
    set.union_nodes(4, 5);
    set.union_nodes(6, 7);
    set.union_nodes(5, 6);
    set.union_nodes(3, 7);
    cout << set.find_parent(5);
    return 0;
}