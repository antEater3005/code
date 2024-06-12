// in this we see how can we represent a graph in cpp
// So there two ways to represent a graph in cpp
// 1. Adjacency matrix : it is matrix of size (number of node+1)*(number of node+1)  initialised with 0 and we take input as two numbers representing the nodes and make the matrix(u,v) =1;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 1 Adjacency matrix
    // int n, m; // n=number of nodes/Vertices,m=no of edges
    // cin >> n, m;
    // int matrix[n + 1][n + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v; // u and v are the nodes that an edge connects
    //     cin >> u >> v;
    //     // For an undirected graph we make both matrix(u,v) & matrix(v,u) to 1;
    //     matrix[u][v] = 1;
    //     matrix[v][u] = 1;
    //     // for a directed graph we only make matrix(u,v) to 1;
    //     matrix[u][v] = 1; // for directed graph
    // }

    // 2. Adjacency List
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> matrix[n + 1];
    for (int i = 0; i < m; i++)
    {
        cout << i;
        int u, v;
        cin >> u >> v;
        // For undirected graph
        matrix[u].push_back(v);
        matrix[v].push_back(u);
        // For directed graph
        // matrix[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        for (int a : matrix[i])
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int i, n = graph.size(), j, ans = 0;
        queue<vector<int>> q;
        set<pair<int, int>> s;
        for (i = 0; i < n; i++)
        {
            vector<int> v(3, 0);
            int mask = (1 << i);
            int node = i;
            int cost = 0;
            v[0] = cost;
            v[1] = node;
            v[2] = mask;
            q.push(v);
            s.insert({node, mask});
        }
        while (q.size() > 0)
        {
            auto z = q.front();
            q.pop();

            if (z[2] == (1 << n) - 1)
            {
                ans = z[0];
                break;
            }
            for (auto j : graph[z[1]])
            {
                int mask = z[2] | (1 << j);

                if (s.find({j, mask}) == s.end())
                {
                    s.insert({j, mask});
                    vector<int> v(3, 0);
                    v[0] = z[0] + 1;
                    v[1] = j;
                    v[2] = mask;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};