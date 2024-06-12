// in DFS traversal we always go deep inside the graph that means, we always visit the next node of the curr_node if exist
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visited, vector<int> &ans, int node, vector<int> adj[])
{
    ans.push_back(node);
    visited[node] = 1;
    for (int a : adj[node])
        if (!visited[a])
            dfs(visited, ans, a, adj);
}
vector<int> dfs_undirected_graph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V, false);
    for (int i = 0; i <= V; i++)
    {
        if (!visited[i])
            dfs(visited, ans, i, adj);
    }
    return ans;
}
/** Cycle detection in undirected graph using DFS*/
bool cycleDFS_util(vector<int> adj[], vector<bool> &visited, int node, int previous)
{
    visited[node] = true;
    for (int a : adj[node])
    {
        if (!visited[a])
        {
            if (cycleDFS_util(adj, visited, a, node))
                return true;
        }
        else if (previous != a)
            return true;
    }
    return false;
}
bool cycleDFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            if (cycleDFS_util(adj, visited, i, -1))
                return true;
    }
    return false;
}
/**Cycle Detection using BFS*/
bool cycleBFS_util(vector<int> adj[], vector<bool> &visited, int node)
{
    queue<pair<int, int>> q;
    visited[node] = true;
    q.push({node, -1});
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        for (int a : adj[curr.first])
        {
            if (!visited[a])
            {
                visited[a] = true;
                q.push({a, curr.first});
            }
            else if (curr.second != a)
                return true;
        }
    }
    return false;
}
bool cycleBFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            if (cycleBFS_util(adj, visited, i))
                return true;
    }
    return false;
}
/**Bipartite Graph:: a bipartite graph is a undirected graph whose nodes can be divided into to sets such that no two nodes of
                     same set have edges between them. */
bool isBipartite_util_BFS(vector<vector<int>> adj, vector<bool> &visited, int node, vector<int> &color)
{
    queue<int> q;
    visited[node] = true;
    if (color[node] == -1)
        color[node] = 0;
    q.push(node);
    while (!q.empty())
    {
        int curr = q.front();
        int curr_node_color = color[curr];
        q.pop();
        for (int a : adj[curr])
        {
            if (!visited[a])
            {
                visited[a] = true;
                color[a] = !curr_node_color;
                q.push(a);
            }
            else if (color[a] == curr_node_color)
                return false;
        }
    }
    return true;
}
bool isBipartite_BFS(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n);
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            if (!isBipartite_util_BFS(graph, visited, i, color))
                return false;
    }
    return true;
}
/**Course Schedule::Leetcode 207 this question is based on cycle detection in directed graph*/
/*CYCLE DETECTION IN DIRECTED GRAPH USING DFS*/
bool isCycle_util_directed(vector<bool> &visited, vector<bool> &curr_streak, vector<int> adj[], int node)
{
    visited[node] = true;
    curr_streak[node] = true;
    for (int n : adj[node])
    {
        if (!visited[n])
        {
            if (isCycle_util_directed(visited, curr_streak, adj, n))
                return true;
        }
        else if (curr_streak[n])
            return true;
    }
    curr_streak[node] = 0;
    return false;
}
bool cycle_DFS_directed(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> adj[numCourses];
    for (auto a : prerequisites)
        adj[a[0]].push_back(a[1]);
    vector<bool> visited(numCourses, false);
    vector<bool> currStreak(numCourses, false);
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
            if (isCycle_util_directed(visited, currStreak, adj, i))
                return false;
    }
    return true;
}

/*Topological Sort::Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.*/
// DFS approach
void topologicalSort_DFS_util(vector<vector<int>> adj, stack<int> &topological_order, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (int a : adj[node])
    {
        if (!visited[a])
            topologicalSort_DFS_util(adj, topological_order, visited, a);
    }
    topological_order.push(node);
}
vector<int> topologicalSort_DFS(vector<vector<int>> adj, int n)
{
    vector<bool> visited(n, 0); // nodes in graph ranges from 0 to n-1;
    stack<int> topological_order;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topologicalSort_DFS_util(adj, topological_order, visited, i);
    }
    vector<int> ans;
    while (!topological_order.empty())
    {
        ans.push_back(topological_order.top());
        topological_order.pop();
    }
    return ans;
}
// BFS approach
void topologicalSort_BFS_util(vector<vector<int>> adj, vector<int> &ans, int node, vector<int> &in_degree)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (int a : adj[temp])
        {
            in_degree[a]--;
            if (in_degree[a] == 0)
                q.push(a);
        }
    }
}
vector<int> topologicalSort_BFS(vector<vector<int>> adj, int n)
{
    vector<int> in_degree(n, 0);
    vector<int> ans;
    for (auto a : adj)
        for (int s : a)
            in_degree[s]++;
    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            topologicalSort_BFS_util(adj, ans, i, in_degree);
    return ans;
}
/*  Cycle detection based on BFS topological sort */
bool isCyclic(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> in_degree(V, 0);
    for (int i = 0; i < V; i++)
        for (int a : adj[i])
            in_degree[a]++;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cnt++; // if the number of elements in the TopoSort is equal to V then there is no cycle else there is cycle in the graph.
        for (int a : adj[temp])
        {
            in_degree[a]--;
            if (in_degree[a] == 0)
                q.push(a);
        }
    }
    return cnt != V;
}

/* Shortest Path in a weighted Directed Acyclic Graph from a source to all the nodes*/
void topoSort(vector<vector<pair<int, int>>> adj, vector<bool> &visited, int node, stack<int> &topSort)
{
    visited[node] = true;
    for (auto a : adj[node])
    {
        if (!visited[a.first])
            topoSort(adj, visited, a.first, topSort);
    }
    topSort.push(node);
}

vector<int> shortestDistace_DAG(vector<vector<pair<int, int>>> adj, int n, int source)
{
    stack<int> topSort;
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            topoSort(adj, visited, i, topSort);
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;
    while (!topSort.empty())
    {
        int a = topSort.top();
        topSort.pop();
        if (a == INT_MAX)
            continue;
        for (auto s : adj[a])
        {
            distance[s.first] = min(distance[s.first], distance[a] + s.second);
        }
    }
    return distance;
}

/** Shortest path from a source node to all the node in a unweighted undirected cyclic/acyclic graph  */
vector<int> shortestDistace_Undirected_cyclic(vector<vector<int>> adj, int n, int source)
{
    vector<int> distances(n, INFINITY);
    distances[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int it : adj[temp])
        {
            if (distances[temp] + 1 < distances[it])
            {
                q.push(it);
                distances[it] = distances[temp] + 1;
            }
        }
    }
    return distances;
}
// Shortest path to all the nodes in a undirected weighted graph
vector<int> shortestPaths(int V, vector<vector<int>> adj[], int S)
{
    vector<int> ans(V, INFINITY);
    queue<int> q;
    ans[S] = 0;
    q.push(S);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto a : adj[temp])
        {
            if (ans[temp] + a[1] < ans[a[0]])
            {
                q.push(a[0]);
                ans[a[0]] = ans[temp] + a[1];
            }
        }
    }
    return ans;
}

/** Shortest path to all nodes from a source node in undirected/directed weighted graph using Dijkstra's Algorithm */
vector<int> dijkstra(vector<vector<pair<int, int>>> adj, int source, int n)
{
    vector<int> distance(n, INFINITY);
    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair stores the distance from source and the node;
    pq.push({0, source});
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        for (auto a : adj[temp.second])
        {
            if (temp.first + a.second < distance[a.first])
            {
                distance[a.first] = temp.first + a.second;
                pq.push({distance[a.first], a.first});
            }
        }
    }
    return distance;
}

/**Bellman Ford: same as Dijkstra's Algo only difference is that it is used for DAG with negative weighted cycle;
 * When the DAG has negative edge cycles it will not be possible to find shortest paths. So,we return -1 int that case;
 * Will find shortest path weight from source node to all the nodes;
 */

vector<int> Bellman_ford_shortest_path(int n, vector<vector<int>> &edges, int src)
{
    vector<int> dist(n, INFINITY);
    dist[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto it : edges)
        {
            int from = it[0], to = it[1], weight = it[2];
            if (dist[from] != INFINITY && dist[from] + weight < dist[to])
                dist[to] = dist[from] + weight;
        }
    }
    for (auto it : edges)
    {
        int from = it[0], to = it[1], weight = it[2];
        if (dist[from] != INFINITY && dist[from] + weight < dist[to])
            return {-1};
    }
    return dist;
}

/** 743. Network Delay Time LeetCode question based on Dijkstra's Algo. */

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1, {{}});
    for (auto a : times)
        adj[a[0]].push_back({a[2], a[1]});

    vector<int> distance(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[k] = 0;
    pq.push({0, k});
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        for (auto a : adj[temp.second])
        {
            if (temp.first + a.first < distance[a.second])
            {
                distance[a.second] = temp.first + a.first;
                pq.push({distance[a.second], a.second});
            }
        }
    }
    int ans = -1;
    for (auto a : distance)
    {
        if (a == INT_MAX)
            return -1;
        ans = max(ans, a);
    }
    return ans;
}

/** MINIMUM SPANNING TREE (MST):: a spanning tree is a graph having exactly same number nodes(N) as in the original given graph and have exactly N-1 edges, such that each and every node is reachable from each and every node in the spanning tree;
 * There are multiple numbers of spanning trees in a graph;
 * The spanning tree with minimim sum of edge weights is the minimum spanning tree of the given graph;
 * There are two algoriths to find MST in a graph
 * 1::Prims Algorithm
 * 2::Kruskal's Algorithm
 * Conditions::We can only find a MST in a given graph if all the nodes are connected:
 *           ::Applicable for both directed and undirected graph:
 */
// 1::Prim's Algorithm
// For undirected graph
vector<vector<pair<int, int>>> prim_s_algorithm(vector<vector<pair<int, int>>> adj, int n)
{
    vector<vector<pair<int, int>>> ans(n, {{}});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // it stores the pair of weight and node;
    vector<bool> included(n, 0);
    vector<int> parent(n, -1);
    for (auto it : adj[0])
        pq.push({it.second, it.first}), parent[it.first] = 0;
    included[0] = 1;
    int v = 1; // v represents the number of nodes included into the MST
    while (v < n)
    {
        auto temp = pq.top();
        if (!included[temp.second])
        {
            ans[parent[temp.second]].push_back({temp.second, temp.first});
            ans[temp.second].push_back({parent[temp.second], temp.first});
            v++;
        }
        for (auto it : adj[temp.second])
            if (!included[it.first])
                pq.push({it.second, it.first});
    }
    return ans;
}
// This function returns the minimum weight of the MST of a given graph;
int spanningTree(int n, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // it stores the pair of weight and node;
    int weight = 0;
    vector<bool> visited(n, 0);
    for (auto a : adj[0])
        pq.push({a[1], a[0]});
    visited[0] = true;
    int v = 1;
    while (v < n)
    {
        auto temp = pq.top();
        pq.pop();
        if (!visited[temp.second])
        {
            visited[temp.second] = true;
            weight += temp.first;
            v++;
        }
        for (auto a : adj[temp.second])
            if (!visited[a[0]])
                pq.push({a[1], a[0]});
    }
    return weight;
}

/* Kruskal's Algorithm ::Before learning the Kruskal's algo. we need to learn a new data structure known a "Disjoint Set", it stores data into two sets and provides, union(u,v) (joining two componets) and findParent(n) (find the parent or representative of the component to which the node n belongs) is performed in constant time;
 >>> for code refer to Disjoint_set.cpp <<<
 *In Kruskal's algorithm the edges are listed in non-decreasing order in triplets of {weight,parent,child};
 * The listed edges are traversed and checked if the parent and child have same parent in our disjoint set if they have then the edge is not included but if its not in our disjoint set its added into the MST;
 */

static bool check(vector<int> a, vector<int> b)
{
    return b[0] > a[0];
}
int findParent(vector<int> &parent, int n)
{
    if (parent[n] == n)
        return n;
    return parent[n] = findParent(parent, parent[n]);
}
void _union(vector<int> &parent, vector<int> &rank, int u, int v)
{
    int u = findParent(parent, u);
    int v = findParent(parent, v);
    if (rank[u] > rank[v])
        parent[v] = u;
    else if (rank[v] > rank[u])
        parent[u] = v;
    else
    {
        parent[u] = v;
        rank[v] += 1;
    }
}
vector<vector<pair<int, int>>> kruskal_s_algorithm(vector<vector<pair<int, int>>> adj, int n)
{
    vector<vector<pair<int, int>>> ans(n, {{}}); //  stores node as pair of next_node and weight;
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < adj[i].size(); j++)
            edges.push_back({adj[i][j].second, i, adj[i][j].first});
    sort(edges.begin(), edges.end(), check);
    vector<int> parent(n, 0);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (auto a : edges)
    {
        if (findParent(parent, a[1]) == findParent(parent, a[2]))
            continue;
        else
        {
            ans[a[1]].push_back({a[2], a[0]});
            _union(parent, rank, a[1], a[2]);
        }
    }
    return ans;
}

/**Bridge in Graph:: bridges in  a graph are the edges the removal of which increases the total number of components in the given graph; */

void dfs_bridge(vector<vector<int>> &adj, int node, vector<pair<int, int>> &ans, int parent, vector<pair<int, int>> &tm, int time)
{
    tm[node].first = time;
    tm[node].second = time;
    for (int it : adj[node])
    {
        if (it == parent)
            continue;
        if (tm[it].first == -1)
        {
            dfs_bridge(adj, it, ans, node, tm, time + 1);
            tm[node].second = min(tm[it].second, tm[node].second);
            if (tm[it].second > tm[node].first)
                ans.push_back({node, it});
        }
        else
        {
            tm[node].second = min(tm[node].second, tm[it].first);
        }
    }
}

vector<pair<int, int>> bridges_(vector<vector<int>> adj, int n)
{
    vector<pair<int, int>> ans;
    vector<pair<int, int>> tm(n, {-1, -1}); // stores the first time when we reach at a node;stores the least first time of its adjacent nodes

    vector<int> parent(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (tm[i].first == -1)
            dfs_bridge(adj, i, ans, -1, tm, 0);
    }
}

/* The below function checks wether an edge is bridge or not */
class isBridge_
{
    void _dfs(vector<int> adj[], int src, vector<bool> &visited)
    {
        visited[src] = true;
        for (int it : adj[src])
            if (!visited[it])
                _dfs(adj, it, visited);
    }
    int indexOf(vector<int> adj[], int c, int d)
    {
        for (int i = 0; i < adj[d].size(); i++)
            if (adj[d][i] == c)
                return i;
    }

public:
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        int initial = 0; // initially we find the number of components in the graph;
        vector<bool> visited(V, 0);
        for (int i = 0; i < V; i++)
            if (!visited[i])
            {
                initial++;
                _dfs(adj, i, visited);
            }
        // here we delete the given edge to be checked
        adj[d].erase(adj[d].begin() + indexOf(adj, c, d));
        adj[c].erase(adj[c].begin() + indexOf(adj, d, c));
        int final = 0; // now calculate the number of components in the new graph after deleting
        for (int i = 0; i < V; i++)
            visited[i] = 0;
        for (int i = 0; i < V; i++)
            if (!visited[i])
            {
                final++;
                _dfs(adj, i, visited);
            }
        return initial != final; // here if the number of components are unequal formally, if number of components increased after removing the edge then the given edge is bridge else not;
    }
};

/* This gives the list of bridges in the graph*/
class Solution
{
    vector<vector<int>> adj, ans;
    vector<int> f;
    vector<int> s;
    vector<bool> visited;
    void _dfs(int node, int parent, int time)
    {
        f[node] = s[node] = time++;
        visited[node] = true;
        for (int it : adj[node])
        {
            if (parent == it)
                continue;
            if (!visited[it])
            {
                _dfs(it, node, time);
                s[node] = min(s[node], s[it]);
                if (s[it] > f[node])
                    ans.push_back({node, it});
            }
            else
            {
                s[node] = min(s[node], f[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        adj.resize(n, vector<int>());
        visited.resize(n, false);
        f.resize(n, -1);
        s.resize(n, -1);
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                _dfs(i, -1, 0);
        }
        return ans;
    }
};

/**Articulation Point:: These are nodes in a graph, the removal of which increase the total number of components of a graph
 * It can be found by using the Tarjan's Algorithm :: a node can be articulation point if it satisfies one of the following case
 * CASE 1::if the node is a root node of the DFS call i.e., parent==-1, then the node should have more than one subgraph, to be an Articulation Point:
 * CASE 2::if a node 'U' is not a root node then atleast one of the subgraphs of U should not have a backedge to any of the ancestors of node U:
 */

void dfs_articulation(int node, int parent, int time, vector<int> &discovery_time, vector<int> &lowest_time, vector<int> &articulationPoints, vector<vector<int>> &adj)
{
    discovery_time[node] = lowest_time[node] = time;
    time++;
    int children = 0;
    for (int it : adj[node])
    {
        if (parent == node) // here we have to skip the parent edge
            continue;
        else if (discovery_time[it] == -1) // if the node is not visited
        {
            children++;
            dfs_articulation(it, node, time, discovery_time, lowest_time, articulationPoints, adj);
            lowest_time[node] = min(lowest_time[it], lowest_time[node]);
            if (parent == -1 and children > 1) // case 1
                articulationPoints.push_back(node);
            // if lowest_time[it] < discovery_time[node] then there is a backedge, i.e., if  lowest_time[it] => discovery_time[node] then there is no backedge so it satisfies our 2nd case to be a AP;
            else if (parent != -1 && lowest_time[it] >= discovery_time[node])
                articulationPoints.push_back(node);
        }
        else

            lowest_time[node] = min(lowest_time[node], discovery_time[it]);
    }
}
vector<int> articulation_points(vector<vector<int>> adj, int V)
{
    vector<int> articulationPoints;
    vector<int> discovery_time(V, -1);
    vector<int> lowest_time(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (discovery_time[i] == -1)
            dfs_articulation(i, -1, 0, discovery_time, lowest_time, articulationPoints, adj);
    }
    return articulationPoints;
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
    vector<int> ans = dfs_undirected_graph(10, Adj_list);
    for (int a : ans)
        cout << a << " ";
    return 0;
}
