#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], int node, int previous, vector<bool> &visited)
{
    visited[node] = true;
    for (int a : adj[node])
    {
        if (!visited[a])
        {
            if (dfs(adj, a, node, visited))
                return true;
        }
        else if (previous != a)
            return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            if (dfs(adj, i, -1, visited))
                return true;
    }
    return false;
}
int main()
{

    return 0;
}