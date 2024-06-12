#include <bits/stdc++.h>
using namespace std;
// for undirected graph
// V is the number of nodes in the graph
vector<int> bfs_undirected_graph(int V, vector<int> adj[])
{
    vector<int> ans;
    bool vis[V] = {false};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty())
            {
                int temp = q.front();
                ans.push_back(temp);
                q.pop();
                for (int a : adj[temp])
                    if (!vis[a])
                    {
                        q.push(a);
                        vis[a] = true;
                    }
            }
        }
    }
    return ans;
}

//BFS traversal of a directed
vector<int> bfs_directed_graph(int n, vector<int> adj[])
{
    vector<int> ans;
    bool visited[n] = {false};

    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (int a : adj[temp])
            if (!visited[a])
            {
                visited[a] = true;
                q.push(a);
            }
    }

    return ans;
}
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> Adj_list[n + 1];
    for (int i = 0; i < t; i++)
    {

        int u, v;
        cin >> u >> v;
        // For undirected graph
        Adj_list[u].push_back(v);
        Adj_list[v].push_back(u);
    }
    bool visited[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                cout << temp << "->";
                for (int i = 0; i < Adj_list[temp].size(); i++)
                {
                    if (!visited[Adj_list[temp][i]])
                    {
                        q.push(Adj_list[temp][i]);
                        visited[Adj_list[temp][i]] = true;
                    }
                }
            }
        }
    }

    return 0;
}
// 9 9 0 2 0 5 1 5 1 6 1 8 3 4 3 5 4 7 5 7