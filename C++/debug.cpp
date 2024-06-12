#include <bits/stdc++.h>
using namespace std;
class Solution2
{
    void get_path(vector<vector<int>> &adj, vector<int> &path, vector<bool> &visited, vector<int> &res, int node)
    {
        if (node == 0)
        {
            res = path;
            return;
        }
        visited[node] = 1;
        for (auto it : adj[node])
            if (!visited[it])
            {
                path.push_back(it);
                get_path(adj, path, visited, res, it);
                path.pop_back();
            }
    }
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &path, int node, int j, int sum, int &res, vector<int> &amount)
    {
        visited[node] = true;
        if (adj[node].size() == 1 && node != 0)
        {
            res = max(sum, res);
            return;
        }
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                int a, newSum = sum;
                if (j < path.size() - 1)
                {
                    a = amount[path[j + 1]];
                    amount[path[j + 1]] = 0;
                    if (path[j + 1] == it)
                        newSum += a / 2;
                    else
                        newSum += amount[it];
                    cout << "s";
                }
                else
                    newSum += amount[it];
                dfs(adj, visited, path, it, j + 1, newSum, res, amount);
                if (j < path.size() - 1)
                    amount[path[j + 1]] = a;
            }
        }
    }

public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = amount.size();
        vector<vector<int>> adj(n, vector<int>());
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> path, temp{bob};
        vector<bool> visited(n, 0);
        get_path(adj, temp, visited, path, bob);
        vector<bool> visited1(n, 0);
        int ans = INT_MIN;
        amount[bob] = 0;
        dfs(adj, visited1, path, 0, 0, amount[0], ans, amount);
        return ans;
    }
};

class Solution
{
    int arr[5] = {0, 9, 99, 999, 9999};
    bool can_divide(int n, int parts, int limit)
    {
        int size = limit - 4 - to_string(parts).size();
        int i = 1;
        while (n > 0 && parts > 0)
        {
            int diff = (arr[i] - arr[i - 1]);
            int rem_parts = min(parts, diff);
            n -= size * rem_parts;
            parts -= rem_parts;
            if (size > 0)
                size--;
        }
        return n <= 0;
    }
    int binary_search(int n, int limit)
    {
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (can_divide(n, mid, limit))
                r = mid;
            else
                l = mid + 1;
            // cout << mid << " ";
        }
        return l;
    }
    vector<string> build_string(string s, int limit)
    {
        int parts = binary_search(s.size(), limit);
        vector<string> ans;
        int idx = 0, size = limit - 4 - to_string(parts).size(), prev = 1;
        for (int i = 1; i <= parts; i++)
        {
            if (prev != to_string(i).size())
            {
                size--;
                prev = to_string(i).size();
            }
            string temp = s.substr(idx, size);
            temp = temp + "<" + to_string(i) + "/" + to_string(parts) + ">";
            ans.push_back(temp);
            idx += size;
        }
        return ans;
    }

public:
    vector<string> splitMessage(string message, int limit)
    {
        return build_string(message, limit);
    }
};

int main()
{
    Solution d;
    vector<vector<int>> e = {{0, 1}, {1, 2}, {2, 3}};
    int a = 3;
    vector<int> am = {-5644, -6018, 1188, -8502};
    string s = "this is really a very awesome message";

    return 0;
}

class Solution
{
    // it check whether three points forms a convex hull or not
    // we should not use the normal slope formula to compare thw slopes of two line because it can give division by zero error
    // instead we should use a modified form of that formula
    /*

    take three  points a(x1,y1),b(x2,y2) and c(x3,y3);
    m(a,b)-m(b,c)<0

    */
    int check(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        return (b[1] - a[1]) * (c[0] - b[0]) - (c[1] - b[1]) * (b[0] - a[0]);
    }

public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        vector<vector<int>> lower, upper;
        sort(trees.begin(), trees.end(), comp);
        for (auto it : trees)
        {
            while (lower.size() >= 2 && check(lower[lower.size() - 2], lower.back(), it) > 0)
                lower.pop_back();
            lower.push_back(it);
        }
        for (auto it : trees)
        {
            while (upper.size() >= 2 && check(upper[upper.size() - 2], upper.back(), it) < 0)
                upper.pop_back();
            upper.push_back(it);
        }
        set<vector<int>> ans;
        for (auto it : lower)
            ans.insert(it);
        for (auto it : upper)
            ans.insert(it);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        int ans = 0, sign = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                int val = 0;
                while (i < s.size() && isdigit(s[i]))
                    val = val * 10 + s[i] - '0';
                val *= sign;
                ans += val;
                sign = 1;
            }
            else if (s[i] == '(')
            {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                ans = st.top();
                st.pop();
                ans *= st.top();
                st.pop();
            }
            else if (s[i] = '-')
                sign = -1;
        }
        return ans;
    }
};
class Solution
{
public:
    int unequalTriplets(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                for (int k = j + 1; k < nums.size(); k++)
                    if (nums[j] != nums[i] && nums[k] != nums[i] && nums[k] != nums[j])
                        ans++;
        return ans;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    void inor(TreeNode *root, vector<int> &nums)
    {
        if (!root)
            return;
        inor(root->left, nums);
        nums.push_back(root->val);
        inor(root->right, nums);
    }

public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &q)
    {
        vector<int> nums;
        inor(root, nums);
        vector<vector<int>> ans;
        for (auto it : q)
        {
            vector<int> t = {-1, -1};
            auto l = lower_bound(nums.begin(), nums.end(), it);
            auto u = upper_bound(nums.begin(), nums.end(), it);
            if (l != nums.end() && *l == it)
            {
                ans.push_back({it, it});
                continue;
            }
            if (l == nums.end() && l != nums.begin())
                t[0] = *prev(l);
            if (u != nums.end())
                t[1] = *u;
            ans.push_back(t);
        }
        return ans;
    }
};

class Solution
{
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        if (roads.empty())
            return 0;
        vector<vector<int>> adj(roads.size() + 1, vector<int>());
        for (auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int n = roads.size() + 1;
        long long ans = 0;
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
            if (adj[i].size() == 1)
                q.push({i, 0, seats - 1, 1, -1});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            for (auto i : adj[it[0]])
                if (i != it[4])
                {
                    if (i == 0)
                    {
                        ans += it[1] + it[3];
                        continue;
                    }
                    if (it[2] == 0)
                        q.push({i, it[1] + it[3], seats - 1, it[3] + 1, it[0]});
                    else
                        q.push({i, it[1] + it[3], it[2] - 1, it[3], it[0]});
                }
        }
        return ans;
    }
};
class Solution
{
    int seat;
    long long dfs(vector<vector<int>> &adj, int node, int p, long long &ans)
    {
        int cnt = 1;
        for (auto it : adj[node])
            if (it != p)
                cnt += dfs(adj, it, node, ans);
        ans += cnt / seat + (cnt % seat != 0);
        return cnt;
    }

public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        seat = seats;
        vector<vector<int>> adj(roads.size() + 1, vector<int>());
        for (auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans = 0;
        for (auto it : adj[0])
            dfs(adj, it, 0, ans);
        return ans;
    }
};
//  0 1
//  1 2
//  1 3
//  4 2
//  5 3
//  6 3
//  6 7
//  8 6
//  9 0
//  5 10
//  11 9
//  12 5
//  5 13
//  8 14
//  11 15
//  8 16
//  17 0
//  18 7
void login(int n, string user, string pass)
{

    int pal = pow(10, n - 1) + 1;
    if (user.substr(4) != pass.substr(4) || user.substr(0, 4) != "user" || pass.substr(0, 4) != "pass")
    {
        cout << "UserId or password is not valid, pls try again.";
    }
    else
    {
        cout << "Welcome " << user << pass.substr(4) << " and the generated token is:token-" << pal;
    }
}
int main()
{
    return 0;
}

int calculateTotalPrice(vector<int> prices, int discount)
{
    int sum = accumulate(prices.begin(), prices.end(), 0), exp = *max_element(prices.begin(), prices.end());
    return (sum - exp) + (100 - discount) * exp;
}

vector<int> countFrequencies(vector<string> &words)
{
    vector<int> ans;
    sort(words.begin(), words.end());
    int cnt = 1;
    for (int i = 1; i < words.size(); i++)
    {
        if (words[i] != words[i - 1])
        {
            ans.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    ans.push_back(cnt);
    return ans;
}
class solution
{
    // Assuming size of nums be 100 in worst case for memoization
    int dp[101][101];
    int sa(vector<int> &nums, int i, int j)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int k = i; k < j; k++)
            mini = min(mini, nums[i - 1] * nums[k] * nums[j] + sa(nums, i, k) + sa(nums, k + 1, j));
        return dp[i][j] = mini;
    }

    // TC of memoized solution is O(N^3) || SC=O(N^2){memoization array} +O(N){stack space}

public:
    int matrixMultiplication(vector<int> &nums, int n)
    {
        // memset(dp, -1, sizeof dp);
        // return sa(nums, 1, n - 1);

        // Top-Down
        int dp[n][n];
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;
        for (int i = n - 1; i >= 1; i--)
            for (int j = i + 1; j < n; j++)
            {
                int mini = INT_MAX;
                for (int k = i; k < j; k++)
                    mini = min(mini, nums[i - 1] * nums[k] * nums[j] + dp[i][k] + dp[k + 1][j]);
                dp[i][j] = mini;
            }
        return dp[1][n - 1];
    }
};
int main()
{
    solution d;
    vector<int> nums = {10, 20, 30, 40, 50};
    cout << d.matrixMultiplication(nums, 5);
    return 0;
}

class Solution
{
    vector<int> connected_nodes;
    int N;
    int get_dis(vector<vector<int>> &adj, int node, int &score, int parent = -1)
    {
        int sum = 0;
        for (auto it : adj[node])
            if (it != parent)
                sum += get_dis(adj, it, score, node);
        score += sum;
        return connected_nodes[node] = sum + 1;
    }
    void sa(vector<vector<int>> &adj, int node, vector<int> &res, int parent = -1)
    {
        if (parent != -1)
            res[node] = res[parent] - 2 * connected_nodes[node] + N;
        for (auto it : adj[node])
            if (it != parent)
                sa(adj, it, res, node);
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        N = n;
        vector<vector<int>> adj(n, vector<int>());
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int score = 0, leaf_node = -1;
        for (int i = 0; i < n && leaf_node == -1; i++)
            if (adj[i].size() == 1)
                leaf_node = i;
        connected_nodes.resize(n, 0);
        vector<int> res(n, 0);
        if (leaf_node == -1)
            return res;
        get_dis(adj, leaf_node, score);
        res[leaf_node] = score;
        sa(adj, leaf_node, res);
        return res;
    }
};

void concatenatedCount(string strs)
{

    int arr[26];
    memset(arr, 0, sizeof arr);
    string ans = "";
    int temp = 0;
    for (auto it : strs)
    {
        if (it == ' ')
        {
            memset(arr, 0, sizeof arr);
            ans += to_string(temp);
            temp = 0;
        }
        else
        {
            for (int i = 0; i < it - 'a' - 1; i++)
                temp += arr[i];
            arr[it - 'a']++;
        }
    }
    ans += to_string(temp);
}
class Solution
{
    int sa(vector<int> &arr, int n)
    {
        vector<bool> visited(n * n + 1, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = 1;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            if (it.first == n * n - 1)
                return it.second;

            for (int i = 1 + it.first; i <= min(n * n - 1, it.first + 6); i++)
            {
                int dest = arr[i] != -1 ? arr[i] - 1 : i;
                if (!visited[dest])
                {
                    visited[dest] = true;
                    q.push({dest, it.second + 1});
                }
            }
        }
        return -1;
    }

public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        for (int i = 0; i < n / 2; i++)
            swap(board[i], board[n - i - 1]);
        for (int i = 0; i < n; i++)
            if (i % 2)
                reverse(board[i].begin(), board[i].end());
        vector<int> arr(n * n + 1);
        for (int i = 0; i < n * n; i++)
            arr[i] = board[i / n][i % n];
        return sa(arr, n);
    }
};
class Solution
{
    void dfs(vector<int> &edges, int node, vector<int> &dist)
    {
        int dis = 0;
        while (node != -1 && dist[node] == INT_MAX)
        {
            dist[node] = dis++;
            node = edges[node];
        }
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        vector<int> dist1(edges.size(), INT_MAX), dist2(edges.size(), INT_MAX);
        dfs(edges, node1, dist1);
        dfs(edges, node2, dist2);
        int ans = -1, dist = INT_MAX;
        for (int i = 0; i < edges.size(); i++)
        {
            if (max(dist1[i], dist2[i]) != INT_MAX && max(dist1[i], dist2[i]) < dist)
                ans = i, dist = max(dist1[i], dist2[i]);
        }
        return ans;
    }
};

int dijkstra_Algo(vector<vector<pair<int, int>>> &adj, int src, int dest, int k)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    queue<vector<int>> pq;
    pq.push({0, src, k});
    dist[src] = 0;
    while (!pq.empty())
    {
        auto top = pq.front();
        pq.pop();
        if (top[2] <= -1)
            continue;
        for (auto it : adj[top[1]])
        {
            if (top[0] + it.second < dist[it.first])
            {
                dist[it.first] = top[0] + it.second;
                pq.push({dist[it.first], it.first, top[2] - 1});
            }
        }
    }
    return dist[dest] == INT_MAX ? -1 : dist[dest];
}

struct node
{
    vector<node *> links;
    bool is_complete;
    node()
    {
        links.resize(26, NULL);
        is_complete = false;
    }
};
class Trie
{
    node *root = new node();

public:
    Trie()
    {
    }
    void insert(string &s)
    {
        node *temp = root;
        for (auto it : s)
        {
            int i = it - 'a';
            if (temp->links[i] == NULL)
                temp->links[i] = new node();
            temp = temp->links[i];
        }
        temp->is_complete = true;
    }
    bool get_words(node *t_root, int cnt, int idx, string &s)
    {
        if (!t_root)
            return false;
        if (idx == s.size() - 1)
            return t_root->is_complete && cnt >= 1;
        if (t_root->is_complete && get_words(root, cnt + 1, idx, s))
            return true;
        return get_words(t_root->links[s[idx] - 'a'], cnt, idx + 1, s);
    }

    vector<string> sa(vector<string> &s)
    {
        vector<string> ans;
        for (auto it : s)
            if (get_words(root, 0, 0, it))
                ans.push_back(it);
        return ans;
    }
};

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        Trie *t = new Trie();
        for (auto it : words)
            t->insert(it);
        return t->sa(words);
    }
};

class SummaryRanges
{
    set<vector<int>> intervals;
    map<int, int> start, end;
    bool isAdded[10001];

public:
    SummaryRanges()
    {
        start.clear();
        end.clear();
        intervals.clear();
        memset(isAdded, 0, sizeof isAdded);
    }

    void addNum(int value)
    {
        if (isAdded[value])
            return;
        if (start.find(value + 1) != start.end() && end.find(value - 1) != end.end())
        {
            int s1 = end[value - 1], e1 = value - 1, s2 = value + 1, e2 = start[value + 1];

            start[s1] = e2;
            end[e2] = s1;
            end.erase(e1);
            start.erase(s2);
            intervals.erase({s1, e1});
            intervals.erase({s2, e2});
            intervals.insert({s1, e2});
        }
        else if (start.find(value + 1) != start.end())
        {
            int s2 = value + 1, e2 = start[value + 1];
            start[value] = e2;
            end[e2] = value;
            intervals.erase({s2, e2});
            start.erase(s2);
            intervals.insert({value, e2});
        }
        else if (end.find(value - 1) != end.end())
        {
            int s1 = end[value - 1], e1 = value - 1;
            end[value] = s1;
            start[s1] = value;
            intervals.erase({s1, e1});
            end.erase(e1);
            intervals.insert({s1, value});
        }
        else
        {
            intervals.insert({value, value});
            start[value] = value;
            end[value] = value;
        }
        isAdded[value] = 1;
    }

    vector<vector<int>> getIntervals()
    {
        return {intervals.begin(), intervals.end()};
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

class Solution
{
public:
    int alternateDigitSum(int n)
    {
        int m = 0, s1 = 0, s2 = 0;
        while (n)
        {
            if (m % 2 == 0)
                s1 += n % 10;
            else
                s2 += n % 10;
            m++;
            n /= 10;
        }
        if (m % 2 == 0)
            return s2 - s1;
        else
            return s1 - s2;
    }
};
class Solution
{

public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int n)
    {
        vector<pair<int, vector<int>>> temp;
        for (auto it : score)
            temp.push_back({it[n], it});
        sort(temp.begin(), temp.end(), greater<pair<int, vector<int>>>());
        vector<vector<int>> res;
        for (auto it : temp)
            res.push_back(it.second);
        return res;
    }
};
class Solution
{
public:
    bool makeStringsEqual(string s, string target)
    {
        string t = string(s.size(), '0');
        if (t == target)
            return s == target;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                return 1;
        return 0;
    }
};

class Solution
{
    int freq[1001] = {0};
    void sa(vector<int> &nums, int idx, int k, int &res, int temp)
    {
    }

public:
    int minCost(vector<int> &nums, int k)
    {
        int res = INT_MAX;

        int freq[1001] = {0};
        vector<int> front(nums.size()), end(nums.size());
        for (int i = 0, sum = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            if (freq[nums[i]] >= 2)
                sum += freq[nums[i]] == 2 ? 2 : 1;
            front[i] = sum;
        }
        memset(freq, 0, sizeof freq);
        for (int i = nums.size() - 1, sum = 0; i >= 0; i--)
        {
            freq[nums[i]]++;
            if (freq[nums[i]] >= 2)
                sum += freq[nums[i]] == 2 ? 2 : 1;
            front[i] = sum;
        }
    }
};

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        if (k == weights.size())
            return 0;
        priority_queue<int> high;
        priority_queue<int, vector<int>, greater<int>> low;
        for (int i = 0; i < weights.size() - 1; i++)
        {
            int it = weights[i] + weights[i + 1];
            low.push(it);
            high.push(it);
            if (low.size() > k - 1)
            {
                low.pop();
                high.pop();
            }
        }
        long long res = 0;
        while (!low.empty())
        {
            res += low.top() - high.top();
            low.pop();
            high.pop();
        }
        return abs(res);
    }
};
class Solution
{
    long long sA(vector<int> &nums, int idx = 0, int cnt = 0, int prev = INT_MAX, bool f = 0, int maxi = -1)
    {
        if (cnt == 4)
            return 1;
        if (idx == nums.size())
            return 0;
        long long ans = 0;
        if ((f && nums[idx] > prev) || (!f && nums[idx] < prev))
            ans += sA(nums, idx + 1, cnt + 1, nums[idx], !f, max(maxi, nums[idx]));

        ans += sA(nums, idx + 1, cnt, prev, f, maxi);
        return ans;
    }

public:
    long long countQuadruplets(vector<int> &nums)
    {
        return sA(nums);
    }
};

class Solution
{

public:
    long long countQuadruplets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> left(n + 1, vector<int>(n + 1, 0)), right(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int no = 1; no <= n; no++)
            {
                if (nums[i] < no)
                    left[i][no]++;
                if (i > 0)
                    left[i][no] += left[i - 1][no];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int no = 1; no <= n; no++)
            {
                if (nums[i] > no)
                    right[i][no]++;
                if (i < n - 1)
                    right[i][no] += right[i + 1][no];
            }
        }
        long long ans = 0;
        for (int j = 1; j < n - 1; j++)
            for (int k = j + 1; k < n - 1; k++)
                if (nums[j] > nums[k])
                    ans += left[j][nums[k]] * right[k][nums[j]];
        return ans;
    }
};

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        key = k, val = v;
        prev = next = NULL;
    }
};
class LFUCache
{
    unordered_map<int, int> count; // key-> count
    map<int, pair<Node *, Node *>> lru;
    unordered_map<int, Node *> keys;
    int cap;

    pair<Node *, Node *> get_new_node()
    {
        Node *head = new Node(0, 0), *tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        return {head, tail};
    }

    Node *add_node(Node *head, Node *tail, int key, int value)
    {
        Node *temp = new Node(key, value);
        temp->next = head->next;
        temp->prev = head;
        temp->next->prev = temp;
        head->next = temp;
        return temp;
    }

    void delete_node(Node *temp)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    Node *change_position(Node *temp, int value = -1)
    {
        int k = temp->key;
        int cnt = count[k];
        delete_node(temp);
        if (lru[cnt].first->next == lru[cnt].second)
            lru.erase(cnt);
        if (lru.find(cnt + 1) == lru.end())
            lru[cnt + 1] = get_new_node();
        auto it = lru[cnt + 1];
        int val = (value == -1) ? temp->val : value;
        count[k]++;
        return add_node(it.first, it.second, k, val);
    }

    Node *get_least_used(pair<Node *, Node *> dll)
    {
        return dll.second->prev;
    }

public:
    LFUCache(int capacity)
    {
        cap = capacity;
        lru.clear();
        count.clear();
        keys.clear();
    }

    int get(int key)
    {
        if (keys.find(key) == keys.end())
            return -1;
        auto it = lru[key];
        keys[key] = change_position(keys[key]);
        cout << key << endl;
        return keys[key]->val;
    }

    void put(int key, int value)
    {
        if (keys.size() == cap && keys.find(key) == keys.end())
        {
            auto it = lru.begin()->second;
            auto least = get_least_used(it);
            delete_node(least);
            if (it.first->next == it.second)
                lru.erase(lru.begin());
            count.erase(least->key);
            keys.erase(least->key);
        }
        if (keys.find(key) == keys.end())
        {
            count[key]++;
            if (lru.find(count[key]) == lru.end())
                lru[count[key]] = get_new_node();
            auto it = lru[count[key]];
            keys[key] = add_node(it.first, it.second, key, value);
        }
        else
        {
            auto it = lru[count[key]];
            keys[key] = change_position(keys[key], value);
        }
        cout << key << " " << value << endl;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        key = k, val = v;
        prev = next = NULL;
    }
};
class LRUCache
{
    Node *head, *tail;
    int cap;
    unordered_map<int, Node *> used_keys;

public:
    LRUCache(int capacity)
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
        used_keys.clear();
    }
    Node *change_position(Node *&temp, int value = -1)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = head->next;
        temp->next->prev = temp;
        temp->prev = head;
        head->next = temp;
        if (value != -1)
            temp->val = value;
        return temp;
    }
    Node *add_Node(int key, int val)
    {
        Node *temp = new Node(key, val);
        temp->next = head->next;
        temp->prev = head;
        temp->next->prev = temp;
        head->next = temp;
        return temp;
    }
    int get(int key)
    {
        if (used_keys.find(key) == used_keys.end())
            return -1;
        used_keys[key] = change_position(used_keys[key]);
        return used_keys[key]->val;
    }

    void put(int key, int value)
    {
        if (used_keys.size() == cap && used_keys.find(key) == used_keys.end())
        {
            Node *lru = tail->prev;
            used_keys.erase(lru->key);
            lru->prev->next = tail;
            tail->prev = lru->prev;

            delete (lru);
        }
        if (used_keys.find(key) == used_keys.end())
            used_keys[key] = add_Node(key, value);
        else
            used_keys[key] = change_position(used_keys[key], value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct Node
{
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int key, int value)
    {
        this->key = key;
        this->val = value;
        next = prev = NULL;
    }
};

class LFUCache
{
    map<int, pair<Node *, Node *>> lru;
    unordered_map<int, Node *> used_keys;
    unordered_map<int, int> count;
    int cap;

    // get a new pair of head and tail nodes
    pair<Node *, Node *> get_node()
    {
        Node *head = new Node(0, 0), *tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        return {head, tail};
    }

    // check if DLL has node or not
    bool is_empty(int cnt)
    {
        Node *head = lru[cnt].first, *tail = lru[cnt].second;
        return head->next == tail;
    }

    // delete a node from DLL
    void delete_node(Node *temp)
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        used_keys.erase(temp->key);
        count.erase(temp->key);
        delete (temp);
    }

    // add Node in DLL
    Node *add_node(Node *head, int key, int value)
    {
        Node *temp = new Node(key, value);
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next->prev = temp;
        return temp;
    }

    // Reposition the Node in DLL
    int reposition_node(Node *node, int val = -1)
    {
        int key = node->key, value = ((val == -1) ? node->val : val), cnt = count[key];
        delete_node(node);
        if (is_empty(cnt))
            lru.erase(cnt);
        if (lru.find(cnt + 1) == lru.end())
            lru[cnt + 1] = get_node();
        count[key] = cnt + 1;
        used_keys[key] = add_node(lru[cnt + 1].first, key, value);
        return value;
    }

public:
    LFUCache(int capacity)
    {
        cap = capacity;
        count.clear();
        lru.clear();
        used_keys.clear();
    }

    int get(int key)
    {
        if (cap == 0 || used_keys.find(key) == used_keys.end())
            return -1;
        // cout << "get : " << key << endl;
        return reposition_node(used_keys[key]);
    }

    void put(int key, int value)
    {
        if (cap == 0)
            return;
        if (cap == used_keys.size() && used_keys.find(key) == used_keys.end())
        {
            Node *LRU_key_node = lru.begin()->second.second->prev;
            int cnt = lru.begin()->first;
            delete_node(LRU_key_node);
            if (is_empty(cnt))
                lru.erase(cnt);
        }
        if (used_keys.find(key) == used_keys.end())
        {
            if (lru.find(1) == lru.end())
                lru[1] = get_node();
            used_keys[key] = add_node(lru[1].first, key, value);
            count[key] = 1;
        }
        else
            reposition_node(used_keys[key], value);
        // cout << "put : " << key << endl;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
#include <bits/stdc++.h>
using namespace std;
int get(vector<vector<int>> &adj, vector<bool> &visited, int n)
{
    visited[n] = true;
    int cnt = 0;
    for (auto it : adj[n])
    {
        if (!visited[it])
            cnt += get(adj, visited, it);
    }
    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = INT_MAX;
    vector<bool> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            ans = min(ans, get(adj, visited, i));
    cout << ans;
    return 0;
}

class Solution
{
    vector<pair<int, int>> cor = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int n = queries.size();
        vector<pair<int, int>> qu;
        for (int i = 0; i < n; i++)
            qu.push_back({queries[i], i});
        sort(qu.begin(), qu.end());
        vector<int> ans(n, 0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        visited[0][0] = 1;
        pq.push({grid[0][0], 0, 0});
        int idx = 0;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int val = top[0], i = top[1], j = top[2];
            while (idx < n && val >= qu[idx].first)
                idx++;
            if (idx == n)
                break;
            ans[idx]++;
            for (auto it : cor)
            {
                int x = it.first + i, y = it.second + j;
                if (x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || visited[x][y])
                    continue;
                visited[x][y] = 1;
                pq.push({grid[x][y], x, y});
            }
        }
        for (int i = 1; i < n; i++)
            ans[i] += ans[i - 1];
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[qu[i].second] = ans[i];
        return res;
    }
};
class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        unordered_map<int, int> map;
        for (int it : basket1)
            ++map[it];
        for (int it : basket2)
            --map[it];
        vector<int> ps;
        int mini = INT_MAX;
        for (auto it : map)
        {
            mini = min(mini, it.first);
            if (it.second % 2)
                return -1;
            for (int i = 0; i < abs(it.second) / 2; ++i)
                ps.push_back(it.first);
        }
        sort(ps.begin(), ps.end());
        long long ans = 0;
        for (int i = 0; i < ps.size() / 2; ++i)
            ans += min(mini * 2, ps[i]);
        return ans;
    }
};

class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        int ans = INT_MIN;
        unordered_set<int> st;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});
        while (k)
        {
            auto it = pq.top();
            pq.pop();
            if ((it.second == 0 || st.find(it.second - 1) == st.end()) && (it.second == nums.size() - 1 || st.find(it.second + 1) == st.end()))
            {
                ans = max(ans, it.first);
                st.insert(it.second);
                k--;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        long long ans = 0;
        unordered_map<char, unordered_set<string>> char_suffixes_group;
        for (auto it : ideas)
            char_suffixes_group[it[0]].insert(it.substr(1));
        for (char i = 'a'; i <= 'z'; i++)
        {
            for (char j = i + 1; j <= 'z'; j++)
            {
                int n = 0;
                for (auto it : char_suffixes_group[j])
                    if (char_suffixes_group[i].find(it) != char_suffixes_group[i].end())
                        n++;
                ans += 2 * (char_suffixes_group[i].size() - n) * (char_suffixes_group[j].size() - n);
            }
        }
        return ans;
    }
};

class Solution
{

    void topoSort_util(vector<vector<int>> &adj, int node, vector<int> &inDegree, vector<int> &ans)
    {
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for (int i : adj[node])
            {
                --inDegree[i];
                if (inDegree[i] == 0)
                    q.push(i);
            }
        }
    }
    vector<int> topoSort(vector<vector<int>> &adj, int n)
    {
        vector<int> inDegree(n + 1, 0);
        vector<int> ans;
        for (auto it : adj)
            for (int i : it)
                inDegree[i]++;
        for (int i = 1; i <= n; i++)
            if (inDegree[i] == 0)
                topoSort_util(adj, i, inDegree, ans);
        return ans;
    }

    void maxbeauty(vector<vector<int>> &adj, int node, int prev, string &s, vector<int> &freq, vector<bool> &visited, int &maxBeauty)
    {
        ++freq[s[node] - 'a'];
        maxBeauty = max(maxBeauty, freq[s[node] - 'a']);
        for (auto it : adj[node])
        {
            if (prev != it)
                maxbeauty(adj, it, node, s, freq, visited, maxBeauty);
        }
        --freq[s[node] - 'a'];
    }

public:
    int max_beauty(int n, int m, string &s, int x[], int y[])
    {
        vector<vector<int>> adj(n + 1, vector<int>());
        for (int i = 0; i < m; i++)
            adj[x[i]].push_back(y[i]);
        vector<bool> visited(n + 1, 0);
        int maxBeauty = -1;
        vector<int> topo = topoSort(adj, n);
        if (topo.size() != n)
            return -1;
        vector<bool> visited(n + 1, 0);
        vector<int> freq(26, 0);
        for (auto it : topo)
        {
            if (!visited[it])
            {
                visited[it] = 1;
                maxbeauty(adj, it, -1, s, freq, visited, maxBeauty);
            }
        }
        return maxBeauty;
    }
};

#include <bits/stdc++.h>
using namespace std;
int get(vector<vector<int>> &adj, vector<bool> &visited, int n)
{
    if (visited[n])
        return 0;
    visited[n] = true;
    int cnt = 1;
    for (auto it : adj[n])
        cnt += get(adj, visited, it);
    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = INT_MAX;
    vector<bool> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            ans = min(ans, get(adj, visited, i));
    cout << ans;
    return 0;
}

class Solution
{
    bool isVowel(string &s)
    {
        char ch = s[0], c = s.back();
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') && (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> pre(words.size() + 1);
        pre[0] = 0;
        pre[1] = isVowel(words[0]);
        for (int i = 1; i < words.size(); i++)
            pre[i + 1] = pre[i] + isVowel(words[i]);
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            auto it = queries[i];
            ans[i] = pre[it[1] + 1] - pre[it[0]];
        }
        return ans;
    }
};

class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        int ans = INT_MIN;
        unordered_set<int> st;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});
        while (k)
        {
            auto it = pq.top();
            pq.pop();
            if ((it.second == 0 || st.find(it.second - 1) == st.end()) && (it.second == nums.size() - 1 || st.find(it.second + 1) == st.end()))
            {
                ans = max(ans, it.first);
                st.insert(it.second);
                k--;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        unordered_map<int, int> map;
        for (int it : basket1)
            ++map[it];
        for (int it : basket2)
            --map[it];
        vector<int> ps;
        int mini = INT_MAX;
        for (auto it : map)
        {
            mini = min(mini, it.first);
            if (it.second % 2)
                return -1;
            for (int i = 0; i < abs(it.second) / 2; ++i)
                ps.push_back(it.first);
        }
        sort(ps.begin(), ps.end());
        long long ans = 0;
        for (int i = 0; i < ps.size() / 2; ++i)
            ans += min(mini * 2, ps[i]);
        return ans;
    }
};

class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long ans = 0;
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            if (i == j)
                ans += stoi(to_string(nums[i]));
            else
                ans += stoi(to_string(nums[i]) + to_string(nums[j]));
            i++, j--;
        }
        return ans;
    }
};

class Solution
{

public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        for (auto it : nums)
        {
            auto x = lower_bound(temp.begin(), temp.end(), lower - it);
            auto y = upper_bound(temp.begin(), temp.end(), upper - it);
            ans += distance(x, y);
            temp.push_back(it);
        }
        return ans;
    }
};
class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int i = nums.size() - 1, j = nums.size() - 1;
        for (int k = 0; k < nums.size(); k++)
        {
            while (0 <= i && nums[k] + nums[i] >= lower)
                --i;
            while (0 <= j && nums[k] + nums[j] > upper)
                --j;
            ans += j - i;
            if (k > i && k <= j)
                --ans;
        }
        return ans;
    }
};

class Solution
{
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
    {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                if (map.find(0) == map.end())
                    map[0] = {i, i};
                continue;
            }
            int num = 0;
            for (int j = 0; j < 31 && j + i < s.size(); j++)
            {
                num = (num << 1) | (s[i + j] - '0');
                if (map.find(num) == map.end())
                    map[num] = {i, i + j};
            }
        }
        vector<vector<int>> ans;
        for (auto it : queries)
        {
            if (map.find(it[0] ^ it[1]) == map.end())
                ans.push_back({-1, -1});
            else
                ans.push_back(map[it[0] ^ it[1]]);
        }
        return ans;
    }
};
class Solution
{
    unordered_map<char, vector<int>> indices;
    string t;
    int dp[32768][51] = {};
    int get_NewMask(string &s, int mask, int n)
    {
        int newMask = mask;
        for (int i = 0; i < s.size(); i++)
            for (auto j : indices[s[i]])
                if (!(newMask & (1 << (n - j - 1))))
                {
                    newMask = newMask | (1 << (n - j - 1));
                    break;
                }

        return newMask;
    }
    int sa(vector<string> &words, int mask, int k, int n)
    {
        if (k == words.size())
        {
            if (mask == ((1 << n) - 1))
                return 1;
            return 40;
        }
        if (dp[mask][k] != -1)
            return dp[mask][k];
        int mini = 20;
        int newMask = get_NewMask(words[k], mask, n);
        if (newMask > mask)
            mini = min(mini, 1 + sa(words, newMask, k, n));
        mini = min(mini, sa(words, mask, k + 1, n));
        return dp[mask][k] = mini;
    }

public:
    int minStickers(vector<string> &stickers, string target)
    {
        indices.clear();
        for (int i = 0; i < target.size(); i++)
            indices[target[i]].push_back(i);
        t = target;
        memset(dp, -1, sizeof dp);
        int res = sa(stickers, 0, 0, target.size());
        if (res == 20)
            return -1;
        return res;
    }
};

class Solution
{
    int sa(vector<int> &cookies, int mask, int preSum)
    {

        int ans = INT_MAX;
        for (int i = 0; i < cookies.size(); i++)
        {
            if (!(mask & (1 << i)))
            {
                if (preSum != 0)
                    ans = min(ans, preSum);
                ans = min(ans, sa(cookies, mask | (1 << i), preSum + cookies[i]));
                ans = min(ans, sa(cookies, mask | (1 << i), cookies[i]));
            }
        }
        return ans;
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        return sa(cookies, 0, 0);
    }
};
class Solution
{
    int n;
    int sa(vector<int> &cookies, vector<int> &dist, int maxi, int k, int idx, int mask)
    {
        if (mask == ((1 << k) - 1) && idx == n)
            return maxi;
        if (idx == n)
            return INT_MAX;

        int mini = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            dist[i] += cookies[idx];
            int newMask = (mask | (1 << i)), newMaxi = max(maxi, dist[i]);
            mini = min(mini, sa(cookies, dist, newMaxi, k, idx + 1, newMask));
            dist[i] -= cookies[idx];
            if (dist[i] == 0)
                break;
        }
        return mini;
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        n = cookies.size();
        vector<int> dist(k, 0);
        return sa(cookies, dist, 0, k, 0, 0);
    }
};

class Solution
{
    int get_score(vector<int> &a, vector<int> &b)
    {
        int score = 0;
        for (int i = 0; i < a.size(); i++)
            score += (a[i] == b[i]);
        return score;
    }
    int n;
    int sa(vector<vector<int>> &students, vector<vector<int>> &mentors, int idx = 0, int mask = 0)
    {
        if (idx == n && mask == ((1 << n) - 1))
            return 0;
        if (idx == n)
            return -1000;
        int res = -1;
        for (int i = 0; i < n; i++)
            if (!(mask & (1 << i)))
                res = max(res, get_score(mentors[idx], students[i]) + sa(students, mentors, idx + 1, mask | (1 << i)));
        return res;
    }

public:
    int
    maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        n = students.size();
        return sa(students, mentors);
    }
};

class Solution
{
    bool isPalindrome(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }

    int sa(string &s, string a, string b, int idx = 0, int maskA = 0, int maskB = 0)
    {
        if (idx == s.size() && !(maskA & maskB) && isPalindrome(a) && isPalindrome(b))
            return a.size() * b.size();
        if (idx == s.size())
            return 0;
        int add_in_a = sa(s, a + s[idx], b, idx + 1, maskA | (1 << idx), maskB);
        int add_in_b = sa(s, a, b + s[idx], idx + 1, maskA, maskB | (1 << idx));
        int leave = sa(s, a, b, idx + 1, maskA, maskB);
        return max(add_in_a, max(add_in_b, leave));
    }

public:
    int maxProduct(string s)
    {
        string a = "", b = "";
        return sa(s, a, b);
    }
};
class Solution
{
    int x, y;
    int count_less_than(int num)
    {
        int count = 0;
        for (int i = 1; i <= x; i++)
            count += min(num / i, y);
        return count;
    }

public:
    int findKthNumber(int m, int n, int k)
    {
        x = n, y = m;
        int left = 1, right = m * n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (count_less_than(mid) > k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

class Solution
{
    bool count_diff_less_than(int diff, vector<int> &nums, int k)
    {
        int a = 0, count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            while (nums[i] - nums[a] > diff)
                a++;
            count += (i - a);
        }
        return count >= k;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (count_diff_less_than(mid, nums, k))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

class Solution
{
    // get count ugly numbers less than num
    int count_ugly(int a, int b, int c, int num)
    {
        long long ab = (1LL * a * b) / __gcd(a, b),
                  bc = (1LL * b * c) / __gcd(b, c),
                  ac = (1LL * a * c) / __gcd(a, c),
                  abc = (1LL * a * bc) / __gcd(1LL * a, bc);

        return num / a + num / b + num / c - num / ab - num / ac - num / bc + num / abc;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        int left = min(a, min(b, c)), right = 2 * 1e9;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (count_ugly(a, b, c, mid) >= n)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
class Solution
{
    int score(int n, vector<int> &nums)
    {
        int score = 0;
        for (auto it : nums)
            score += (it + n - 1) / n;
        return score;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int left = 0, right = 1e6;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (score(mid, nums) > threshold)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

class Solution
{
    bool can_divide(vector<int> &nums, int sum, int k)
    {
        int temp = 0;
        for (int num : nums)
            if (num + temp > sum)
                temp = num, --k;
            else
                temp += num;
        if (temp)
            --k;
        return k >= 0;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0);
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (can_divide(nums, mid, k))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
class Solution
{
    vector<int> scores;
    vector<int> get_newFreq(vector<int> &freq, string &word)
    {
        vector<int> newFreq = freq;
        int score = 0;
        for (auto it : word)
            if (newFreq[it - 'a'] == 0)
                return {};
            else
            {
                --newFreq[it - 'a'];
                score += scores[it - 'a'];
            }
        newFreq.push_back(score);
        return newFreq;
    }
    int sa(vector<string> &words, vector<int> &freq, int idx = 0)
    {
        if (idx == words.size())
            return 0;
        int max_score = -1;
        vector<int> newFreq = get_newFreq(freq, words[idx]);
        if (!newFreq.empty())
        {
            int score = newFreq.back();
            newFreq.pop_back();
            max_score = max(max_score, score + sa(words, newFreq, idx + 1));
        }
        max_score = max(max_score, sa(words, freq, idx + 1));
        return max_score;
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        scores = score;
        vector<int> freq(26, 0);
        for (auto it : letters)
            freq[it - 'a']++;
        return sa(words, freq);
    }
};

class Solution
{
    void dfs(vector<vector<int>> &adj, int node, int &mask, int nodes, int prev = -1)
    {
        mask = mask | (1 << (node - 1));
        for (auto it : adj[node])
            if (it != prev && (nodes & (1 << (it - 1))))
                dfs(adj, it, mask, nodes, node);
    }
    bool isValid(int nodes, vector<vector<int>> &adj)
    {
        int mask = 0, count = 0;
        for (int i = 0; i < 15; i++)
            if (nodes & (1 << i))
            {
                if (count == 0)
                    dfs(adj, i + 1, mask, nodes);
                count++;
            }
        return count > 1 && ((mask ^ nodes) == 0);
    }

    int diameter(vector<vector<int>> &adj, int node, int &maxDiameter, int nodes, int prev = -1)
    {
        int m1 = 0, m2 = 0;
        for (auto it : adj[node])
            if (prev != it && (nodes & (1 << (it - 1))))
            {
                int x = diameter(adj, it, maxDiameter, nodes, node);
                if (x > m1)
                    m2 = m1, m1 = x;
                else if (x > m2)
                    m2 = x;
            }
        maxDiameter = max(maxDiameter, m1 + m2 + 1);
        return m1 + 1;
    }
    int getDiameter(vector<vector<int>> &adj, int nodes)
    {
        int maxDiameter = 0;
        for (int i = 0; i < 15; i++)
            if (nodes & (1 << i))
            {
                diameter(adj, i + 1, maxDiameter, nodes);
                break;
            }
        return maxDiameter;
    }

public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1, vector<int>());
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ans(n - 1, 0);
        for (int i = 1; i <= (1 << 16) - 1; i++)
        {
            if (isValid(i, adj))
                ans[getDiameter(adj, i) - 2]++;
        }
        return ans;
    }
};

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> projects(capital.size());
        for (int i = 0; i < profits.size(); i++)
            projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end(), [&](pair<int, int> &a, pair<int, int> &b)
             { return a.first < b.first || (a.first == b.first && a.second > b.second); });
        // for (auto it : projects)
        //     cout
        //         << it.first << " " << it.second << endl;
        priority_queue<int> pq;
        int i = 0;
        while (k--)
        {
            while (i < projects.size() && projects[i].first <= w)
                pq.push(projects[i++].second);
            if (!pq.empty())
            {
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};

class Solution
{
    bool isPerfectSquare(int num)
    {
        int _sqrt = sqrt(num);
        return _sqrt * _sqrt == num;
    }
    int sa(vector<int> &nums, int n, int mask = 0, int prev = -1)
    {
        if (mask == (1 << n) - 1)
            return 1;
        int count = 0;
        unordered_set<int> set;
        for (int i = 0; i < n; i++)
            if (!(mask & (1 << i)) && set.insert(nums[i]).second && (prev == -1 || isPerfectSquare(prev + nums[i])))
                count += sa(nums, n, mask | (1 << i), nums[i]);
        return count;
    }

public:
    int numSquarefulPerms(vector<int> &nums)
    {
        return sa(nums, nums.size());
    }
};

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int smallest_num = INT_MAX, deviation = INT_MAX;
        priority_queue<int> pq;
        for (auto it : nums)
        {
            it = (it & 1) ? it * 2 : it;
            smallest_num = min(smallest_num, it);
            pq.push(it);
        }
        while (pq.top() % 2 == 0)
        {
            deviation = min(deviation, pq.top() - smallest_num);
            smallest_num = min(smallest_num, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        return min(deviation, pq.top() - smallest_num);
    }
};

class Solution
{
    vector<pair<int, int>> cord = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    // this one is my solution
    int minimumTime(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        // pq.push({0, 0, 0});
        if (grid[0][1] <= 1)
            pq.push({1, 0, 1});
        if (grid[1][0] <= 1)
            pq.push({1, 1, 0});
        vector<vector<int>> visit_time(n, vector<int>(m, INT_MAX));
        visit_time[0][0] = 0;
        visit_time[0][1] = visit_time[1][0] = 1;
        while (!pq.empty())
        {
            auto [t, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1)
                return t;
            for (auto cor : cord)
            {
                int x = i + cor.first, y = j + cor.second;
                if (x < 0 || y < 0 || x == n || y == m)
                    continue;
                int time = INT_MAX;
                if (t + 1 >= grid[x][y])
                    time = t + 1;
                else
                    time = grid[x][y] + (grid[x][y] - t - 1) % 2;
                if (time < visit_time[x][y])
                {
                    // cout << x << " " << y << " " << time << endl;
                    visit_time[x][y] = time;
                    pq.push({time, x, y});
                }
            }
        }
        return -1;
    }
    // https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/discuss/3230800/C%2B%2B-Java-Python-Ping-Pong-Dijkstra
    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        int n = grid.size(), m = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        visited[0][0] = 0;
        while (!pq.empty())
        {
            auto [t, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1)
                return t;
            for (auto cor : cord)
            {
                int x = i + cor.first, y = j + cor.second;
                if (x < 0 || y < 0 || x == n || y == m || visited[x][y])
                    continue;
                int wait_time = (grid[x][y] - t) % 2 == 1; // this part is cool
                visited[x][y] = 1;
                pq.push({max(wait_time + grid[x][y], t + 1), x, y});
            }
        }
        return -1;
    }
};

// class Solution
// {
//     bool is_all_same(vector<vector<int>> &grid, int top, int right, int left, int bottom)
//     {
//         int cnt_1 = 0, cnt_0 = 0;
//         for (int i = top; i <= bottom; i++)
//             for (int j = left; j <= right; j++)
//                 grid[i][j] == 0 ? cnt_0++ : cnt_1++;
//         return cnt_0 == 0 || cnt_1 == 0;
//     }
//     Node *sa(vector<vector<int>> &grid, int left, int right, int top, int bottom)
//     {
//         if (is_all_same(grid, top, right, left, bottom))
//             return new Node(grid[top][left], 1);
//         Node *root = new Node(1, 0);
//         int vertical_mid = (left + right) / 2, horiz_mid = (top + bottom) / 2;
//         root->topLeft = sa(grid, left, vertical_mid, top, horiz_mid);
//         root->topRight = sa(grid, vertical_mid + 1, right, top, horiz_mid);
//         root->bottomLeft = sa(grid, left, vertical_mid, horiz_mid + 1, bottom);
//         root->bottomRight = sa(grid, vertical_mid + 1, right, horiz_mid + 1, bottom);
//         return root;
//     }

// public:
//     Node *construct(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         return sa(grid, 0, n - 1, 0, n - 1);
//     }
// };

class Solution
{
    void conquer(vector<int> &nums, int left, int mid, int right, vector<int> &temp)
    {
        int m = mid + 1, idx = 0, l = left;
        while (l <= mid && m <= right)
            if (nums[l] < nums[m])
                temp[idx++] = nums[l++];
            else
                temp[idx++] = nums[m++];
        while (l <= mid)
            temp[idx++] = nums[l++];
        while (m <= right)
            temp[idx++] = nums[m++];
        for (int i = left, idx = 0; i <= right; i++, idx++)
            nums[i] = temp[idx];
    }
    void divide(vector<int> &nums, int left, int right, vector<int> &temp)
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        divide(nums, left, mid, temp);
        divide(nums, mid + 1, right, temp);
        conquer(nums, left, mid, right, temp);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> temp(nums.size());
        divide(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};

class QuickSort
{
    void sort_util(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return;
        swap(nums[low + rand() % (high - low + 1)], nums[low]);
        int pivot = low;
        int left = low + 1, right = high;
        while (left <= right)
        {
            if (nums[left] < nums[pivot])
                left++;
            else if (nums[right] >= nums[pivot])
                right--;
            else
                swap(nums[left], nums[right]);
        }
        swap(nums[right], nums[pivot]);
        sort_util(nums, low, right - 1);
        sort_util(nums, right + 1, high);
    }

public:
    void sort_array(vector<int> &nums)
    {
        sort_util(nums, 0, nums.size() - 1);
    }
};

class Solution
{
    int getNum(int n)
    {
        if (n == 0)
            return 0;
        return 1 + getNum(n / 10);
    }
    void modifyArray(vector<char> &chars, int &i, string &s)
    {
        for (int j = 0; j < s.size(); j++)
            chars[i++] = s[j];
    }

public:
    int compress(vector<char> &chars)
    {
        int ans = 0, streak = 0, j = 0;
        char ch = chars[0];
        for (int i = 0; i < chars.size(); i++)
        {
            if (chars[i] == ch)
                streak++;
            else
            {
                string s = string(1, ch);
                ans += 1;
                if (streak > 1)
                {
                    s = s + to_string(streak);
                    ans += getNum(streak);
                }
                modifyArray(chars, j, s);
                ch = chars[i];
                streak = 1;
            }
        }
        string s = string(1, ch);
        ans += 1;
        if (streak > 1)
        {
            s = s + to_string(streak);
            ans += getNum(streak);
        }
        modifyArray(chars, j, s);
        return ans;
    }
};

class Solution
{
    int skills;
    void sa(vector<int> &people_skill_bits, int acquired_skills, int idx, long long &ans, long long temp)
    {
        if (idx == people_skill_bits.size() || acquired_skills == skills)
        {
            if (acquired_skills == skills && (__builtin_popcount(ans) > __builtin_popcount(temp) || ans == 0))
                ans = temp;
            return;
        }
        if (ans != 0 && __builtin_popcount(ans) <= __builtin_popcount(temp))
            return;
        sa(people_skill_bits, acquired_skills, idx + 1, ans, temp);
        if (acquired_skills < (acquired_skills | people_skill_bits[idx]))
            sa(people_skill_bits, acquired_skills | people_skill_bits[idx], idx + 1, ans, temp | (1LL << idx));
    }

public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        unordered_map<string, int> skill_idx;
        int n = req_skills.size();
        skills = (1 << n) - 1;
        for (int i = 0; i < n; i++)
            skill_idx[req_skills[i]] = i;
        vector<int> people_skill_bits(people.size());
        for (int i = 0; i < people.size(); i++)
        {
            int people_skill = 0;
            for (auto it : people[i])
                people_skill |= (1 << skill_idx[it]);
            people_skill_bits[i] = people_skill;
        }

        long long ans_bit = 0;
        sa(people_skill_bits, 0, 0, ans_bit, 0LL);
        vector<int> ans;
        int i = 0;
        while (ans_bit)
        {
            if (ans_bit & 1)
                ans.push_back(i);
            i++;
            ans_bit /= 2;
        }
        return ans;
    }
};

class Solution
{
    int skills;
    int dp[61][1 << 16] = {0};
    vector<int> ans = {};
    void sa(vector<int> &people_skill_bits, int acquired_skills, int idx, vector<int> &temp)
    {
        if (idx == people_skill_bits.size())
        {
            if (acquired_skills == skills && (ans.size() > temp.size() || ans.empty()))
                ans = temp;
            // cout << acquired_skills << " ";
            return;
        }
        if (dp[idx][acquired_skills] != -1 && dp[idx][acquired_skills] <= temp.size())
            return;

        sa(people_skill_bits, acquired_skills, idx + 1, temp);
        temp.push_back(idx);
        sa(people_skill_bits, acquired_skills | people_skill_bits[idx], idx + 1, temp);
        temp.pop_back();
        if (temp.size() > 0)
            dp[idx][acquired_skills] = temp.size();
    }

public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        unordered_map<string, int> skill_idx;
        int n = req_skills.size();
        memset(dp, -1, sizeof dp);
        skills = (1 << n) - 1;
        // cout << skills;
        for (int i = 0; i < n; i++)
            skill_idx[req_skills[i]] = (1 << i);
        vector<int> people_skill_bits(people.size());
        for (int i = 0; i < people.size(); i++)
        {
            int people_skill = 0;
            for (auto it : people[i])
                if (skill_idx.count(it))
                    people_skill |= skill_idx[it];
            people_skill_bits[i] = people_skill;
        }
        vector<int> temp;
        sa(people_skill_bits, 0, 0, temp);
        return ans;
    }
};

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int latest_out_range = -1, latest_mink = -1, latest_maxK = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
                latest_out_range = i;
            if (nums[i] == minK)
                latest_mink = i;
            if (nums[i] == maxK)
                latest_maxK = i;
            ans += min(0, min(latest_maxK, latest_mink) - latest_out_range);
        }
        return ans;
    }
};

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
    ListNode *get_mid(ListNode *head)
    {
        ListNode *t1 = NULL, *t2 = head;
        while (t2 && t2->next)
        {
            t1 = !t1 ? head : t1->next;
            t2 = t2->next->next;
        }
        return t1;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        if (!head->next)
            return new TreeNode(head->val);
        ListNode *end_of_1st_part = get_mid(head), *start_second_part = end_of_1st_part->next->next;
        cout << end_of_1st_part->val << " ";
        TreeNode *root = new TreeNode(end_of_1st_part->next->val);
        end_of_1st_part->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(start_second_part);
        return root;
    }
};

#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}
class Solution
{
    bool isvowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    int vowelStrings(vector<string> &words, int left, int right)
    {
        int ans = 0;
        for (; left <= right; left++)
            if (isvowel(words[left][0]) && isvowel(words[left].back()))
                ans++;
        return ans;
    }
};
class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater());
        int ans = 0;
        long sum = 0;
        for (auto it : nums)
        {
            sum += it;
            if (sum > 0)
                ans++;
        }
        return ans;
    }
};
class Solution
{
public:
    long long beautifulSubarrays(vector<int> &nums)
    {
        int x = 0;
        long long ans = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            x = x ^ nums[i];
            ans += map[x]++;
        }
        return ans;
    }
};

class Solution
{
public:
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), [](const auto &a, const auto &b)
             { return a[1] < b[1]; });
        bool line[2001] = {0};
        for (auto it : tasks)
        {
            int s = it[0], e = it[1], d = it[2];
            int duration = it[2];
            for (; s <= e && d; s++)
                d -= line[s];
            for (; e >= it[0] && d; e--)
                if (!line[e])
                    line[e] = true, d--;
        }
        return count(begin(line), end(line), true);
    }
};
// [[2,3,1],[4,5,1],[1,5,2]]
// [[1,3,2],[2,5,3],[5,6,2]]
// [[2,13,2],[6,18,5],[2,13,3]]

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
    ListNode *mergeTwo(ListNode *a, ListNode *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        ListNode *head = a->val < b->val ? a : b;
        head->next = a->val < b->val ? mergeTwo(a->next, b) : mergeTwo(a, b->next);
        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = NULL;
        for (ListNode *it : lists)
            head = mergeTwo(it, head);
        return head;
    }
};
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        if (time < n)
            return time + 1;
        int x = time / (n - 1), y = time % (n - 1);
        if (x % 2 == 0)
            return y + 1;
        else
            return n - y;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    void getSum(TreeNode *root, vector<long> &sums, int depth = 0)
    {
        if (!root)
            return;
        if (depth == sums.size())
            sums.push_back(0);
        sums[depth] += root->val;
        getSum(root->left, sums, depth + 1);
        getSum(root->right, sums, depth + 1);
    }

public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<long> sums;
        getSum(root, sums);
        if (sums.size() < k)
            return -1;
        sort(sums.begin(), sums.end(), greater());
        return sums[k - 1];
    }
};

class Solution
{
    vector<int> get_p_factors(int n)
    {
        vector<int> pf;
        for (int i = 2; n > 1 && i < 1000; i += 1 + (i % 2))
            if (n % i == 0)
            {
                pf.push_back(i);
                while (n % i == 0)
                    n /= i;
            }
        if (n > 1)
            pf.push_back(n);
        return pf;
    }

public:
    int findValidSplit(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> left, right;
        for (auto num : nums)
            for (int it : get_p_factors(num))
                right[it]++;

        for (int i = 0, common = 0; i < n - 1; i++)
        {
            for (auto it : get_p_factors(nums[i]))
                common += (left[it]++ == 0) - (left[it] == right[it]);
            if (common == 0)
                return i;
        }

        return -1;
    }
};

class Solution
{
    int mod = 1e9 + 7;
    // int dp[51][1001] = {};
    // int sa(vector<vector<int>> &types, int idx, int target)
    // {
    //     if (target <= 0 || idx == types.size())
    //         return target == 0;
    //     if (dp[idx][target] != -1)
    //         return dp[idx][target];
    //     int temp = 0;
    //     for (int i = 0; i <= types[idx][0]; i++)
    //         temp = (temp + sa(types, idx + 1, target - types[idx][1] * i)) % mod;
    //     return dp[idx][target] = temp % mod;
    // }

public:
    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        // memset(dp, -1, sizeof dp);

        vector<int> dp(target + 1, 0);
        dp[target] = 1;

        for (int i = 0; i < types.size(); i++)
            for (int t = target; t > 0; --t)
                for (int j = 1; j <= types[i][0] && t - types[i][0] * j >= 0; j++)
                    dp[t] = (dp[t] + dp[t - types[i][1] * j]) % mod;

        for (auto it : dp)
            cout << it << " ";
        return dp[0];
    }
};

class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        vector<TreeNode *> q;
        q.push_back(root);
        int i = 0;
        while (i < q.size() && q[i])
        {
            q.push_back(q[i]->left);
            q.push_back(q[i]->right);
            i++;
        }
        while (i < q.size() && !q[i])
            i++;
        return q.size() == i;
    }
};
class Solution
{
public:
    int splitNum(int num)
    {
        int a = 0, b = 0;
        string s = to_string(num);
        sort(s.begin(), s.end());
        bool f = 0;
        for (char it : s)
        {
            if (f)
                a = a * 10 + (it - '0');
            else
                b = b * 10 + (it - '0');
            f = !f;
        }
        return a + b;
    }
};
class Solution
{
public:
    long long coloredCells(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 5;
        n--;
        return (n * n + n) * 2 + 1;
    }
};
class Solution
{
    int power(long long a, int n, int p)
    {
        int res = 1;
        while (n > 0)
        {
            // if n is odd then multiply res by a
            if (n & 1)
                res = (res * a) % p;
            // here the n must be even
            n >>= 1; // n=n/2
            a = (a * a) % p;
        }
        return res;
    }

public:
    int countWays(vector<vector<int>> &ranges)
    {
        int n_independent_ranges = 0;
        sort(ranges.begin(), ranges.end());
        int prev = ranges[0][1];
        for (auto it : ranges)
        {
            if (it[0] > prev)
                n_independent_ranges++;
            prev = max(it[1], prev);
        }
        return power(2, n_independent_ranges + 1, 1e9 + 7);
    }
};
class Solution
{
    unordered_map<int, int> in_idx;
    TreeNode *sa(vector<int> &inorder, vector<int> &postorder, int in_left, int in_right, int post_left, int post_right)
    {
        if (in_left > in_right || post_left > post_right)
            return NULL;
        int root_idx = in_idx[postorder[post_right]];
        int nodes_in_left = root_idx - in_left;
        TreeNode *root = new TreeNode(postorder[post_right]);
        root->left = sa(inorder, postorder, in_left, root_idx - 1, post_left, post_left + nodes_in_left - 1);
        root->right = sa(inorder, postorder, root_idx + 1, in_right, post_left + nodes_in_left, post_right - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        in_idx.clear();
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            in_idx[inorder[i]] = i;
        return sa(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};

class yNode
{
    yNode *next[26];
    bool isComplete = false;
    friend class xTrie;
};

class xTrie
{
    yNode *root;

public:
    xTrie()
    {
        root = new yNode();
    }

    void insert(string word)
    {
        yNode *temp = root;
        for (auto it : word)
        {
            if (!temp->next[it - 'a'])
                temp->next[it - 'a'] = new yNode();
            temp = temp->next[it - 'a'];
        }
        temp->isComplete = true;
    }

    bool search(string word)
    {
        yNode *temp = root;
        for (auto it : word)
        {
            if (!temp->next[it - 'a'])
                return false;
            temp = temp->next[it - 'a'];
        }
        return temp->isComplete;
    }

    bool startsWith(string prefix)
    {
        yNode *temp = root;
        for (auto it : prefix)
        {
            if (!temp->next[it - 'a'])
                return false;
            temp = temp->next[it - 'a'];
        }
        return true;
    }
};

/**
 * Your xTrie object will be instantiated and called as such:
 * xTrie* obj = new xTrie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class BrowserHistory
{
    string pages[5001] = {};
    int start = 0, end = 1, current = 0;

public:
    BrowserHistory(string homepage)
    {
        pages[0] = homepage;
    }

    void visit(string url)
    {
        pages[++current] = url;
        end = current + 1;
    }

    string back(int steps)
    {
        if (current - steps >= 0)
            current -= steps;
        else
            current = 0;
        return pages[current];
    }

    string forward(int steps)
    {
        if (current + steps < end)
            current += steps;
        else
            current = end - 1;
        return pages[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

class Solution
{
public:
    int distMoney(int money, int children)
    {
        if (money < children)
            return -1;
        if (money > 8 && money % 8 == 4)
            return children - 2;
        return money / 8;
    }
};
class Solution
{
public:
    int maximizeGreatness(vector<int> &nums)
    {
        priority_queue<int> st;
        sort(nums.begin(), nums.end());
        int prev = 1, ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (!st.empty() && st.top() > nums[i])
                st.pop(), ans++;
            st.push(nums[i]);
        }
        return ans;
    }
};

class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        vector<bool> marked(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});
        while (!pq.empty())
        {
            if (!marked[pq.top().second])
            {
                marked[pq.top().second] = 1;
                if (pq.top().second > 0)
                    marked[pq.top().second - 1] = 1;
                if (pq.top().second < n - 1)
                    marked[pq.top().second + 1] = 1;
                ans += pq.top().first;
            }
            pq.pop();
        }
        return ans;
    }
};

class Solution
{
public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long left = 1, right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
        auto canRepair = [&](long long time)
        {
            int carsRepaired = 0;
            for (auto it : ranks)
                carsRepaired += sqrt(time / it);
            return carsRepaired >= cars;
        };
        while (left < right)
        {
            long long mid = left + (right - left) / 2;
            if (canRepair(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
class Solution
{
public:
    int distMoney(int money, int children)
    {
        if (money < children)
            return -1;
        while (money >= 8)
            return money / 8;
    }
};

class xNode
{
    xNode *next[26];
    bool isComplete = false;
    friend class WordDictionary;
};

class WordDictionary
{
    xNode *root;

public:
    WordDictionary()
    {
        root = new xNode();
    }

    void addWord(string word)
    {
        xNode *temp = root;
        for (auto it : word)
        {
            if (!temp->next[it - 'a'])
                temp->next[it - 'a'] = new xNode();
            temp = temp->next[it - 'a'];
        }
        temp->isComplete = true;
    }

    bool search_sa(string &s, int i, xNode *temp)
    {
        if (!temp)
            return false;
        if (s.size() == i)
            return temp->isComplete;
        bool a = false;
        if (s[i] == '.')
            for (int x = 0; x <= 26; x++)
                a |= search_sa(s, i + 1, temp->next[x]);
        else
            a |= search_sa(s, i + 1, temp->next[s[i] - 'a']);
        return a;
    }

    bool search(string word)
    {
        xNode *temp = root;
        return search_sa(word, 0, temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class Solution
{
    unordered_map<int, int> map;
    int dp[(1 << 20)][21];
    int sa(vector<pair<int, int>> &nums, int idx, int k, int mask = 0)
    {
        if (idx == nums.size())
            return 0;
        if (dp[mask][idx] != -1)
            return dp[mask][idx];
        int temp = 0;
        if (map.find(nums[idx].first - k) == map.end())
        {
            map[nums[idx].first]++;
            temp += (1 << (nums[idx].second - 1)) + sa(nums, idx + 1, k, mask | (1 << idx));
            if (--map[nums[idx].first] == 0)
                map.erase(nums[idx].first);
        }
        temp += sa(nums, idx + 1, k, mask);
        return dp[mask][idx] = temp;
    }

public:
    int beautifulSubsets(vector<int> &nums, int value)
    {
        map.clear();
        // int ans = 0;
        // memset(dp, -1, sizeof dp);
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> temp = {{nums[0], 1}};
        for (int i = 1; i < nums.size(); i++)
            if (temp.back().first == nums[i])
                temp.back().second++;
            else
                temp.push_back({nums[i], 1});
        int ans = 0;
        for (int i = 0; i < temp.size(); i++)
        {
        }
    }
};

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        unordered_map<int, int> map;
        for (auto &it : nums)
            it = map[(it % value + value) % value]++;
        int ans = 0;
        while (1)
        {
            if (map.find(ans % value) == map.end())
                return ans;
            if (--map[ans % value] == 0)
                map.erase(ans % value);
            ans++;
        }
        return 1;
    }
};

class Solution
{

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        unordered_set<int> set(days.begin(), days.end());
        int dp[366] = {};
        for (int i = 0; i <= 365; i++)
        {
            if (set.find(i) == set.end())
                dp[i] = dp[i - 1];
            else
                dp[i] = min({dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
        }
        return dp[365];
    }
};

class Solution
{
    int dp[502][502] = {};
    int sa(vector<int> &A, int time, int idx)
    {
        if (A.size() == idx)
            return 0;
        if (dp[time][idx] != -1)
            return dp[time][idx];
        return dp[time][idx] = max(A[idx] * time + sa(A, time + 1, idx + 1), sa(A, time, idx + 1));
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        memset(dp, -1, sizeof dp);
        return sa(satisfaction, 1, 0);
    }
};

class Solution
{

    bool sa(vector<vector<int>> &grid, int i, int j)
    {
    }

public:
    bool hasValidPath(vector<vector<int>> &grid)
    {
    }
};

class Solution
{
public:
    vector<int> successfulPairs(vector<int> spells, vector<int> potions, long long success)
    {
        int n = spells.size(), m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {
            int low = 0, high = m - 1;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                long long x = spells[i] * potions[mid];
                if (x < success)
                    low = mid + 1;
                else
                    high = mid;
            }
            ans[i] = m - low - (spells[i] * potions[low] < success);
        }
        return ans;
    }
};

class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set(nums1.begin(), nums1.end());
        int ans = INT_MAX;
        for (auto it : nums2)
            if (set.count(it))
                ans = min(ans, it);
        if (ans != INT_MAX)
            return ans;
        int x = *min_element(nums1.begin(), nums1.end());
        int y = *min_element(nums2.begin(), nums2.end());
        if (x < y)
            return x * 10 + y;
        else
            return y * 10 + x;
    }
};
class Solution
{
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals)
    {
        unordered_map<char, int> map;
        for (int i = 0; i < chars.size(); i++)
            map[chars[i]] = vals[i];
        int ans = 0, temp = 0;
        for (auto it : s)
        {
            int currVal = map.find(it) == map.end() ? it - 'a' + 1 : map[it];
            temp = max(temp + currVal, currVal);
            ans = max(temp, ans);
        }
        return ans;
    }
};

class Solution
{
    int sa(vector<vector<int>> &adj, vector<int> &visited, int node, int temp = 1)
    {
        if (visited[node])
            return temp > visited[node] + 2 ? temp - visited[node] : INT_MAX; // if temp is less than or equal to visited[node]+2 then it means single edge
        int res = INT_MAX;
        visited[node] = temp;
        for (auto it : adj[node])
            res = min(res, sa(adj, visited, it, temp + 1));
        return res;
    }

public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        int ans = INT_MAX;
        vector<vector<int>> adj(n, vector<int>());
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++)
            ans = min(sa(adj, vector<int>(n) = {}, i), ans);
        return ans == INT_MAX ? -1 : ans;
    }
};

class Solution
{
public:
    long long makeSubKSumEqual(vector<int> &arr, int k)
    {
        vector<long> nums;
        int i = 0, n = arr.size();
        long long sum = 0;
        for (; i < k; i++)
            sum += arr[i];
        nums.push_back(sum);
        for (int j = i; j < i + n - 1; j++)
        {
            sum += -arr[j - k] + arr[j % n];
            nums.push_back(sum);
        }
        long long t = accumulate(nums.begin(), nums.end(), 0LL) / nums.size();
        sum = 0;
        long long upp = 0, low = 0;
        for (auto it : nums)
        {
            upp += abs(t + 1 - it);
            low += abs(t - it);
        }
        return min(upp, low);
    }
};

class Solution
{

    vector<int> topo_sort(vector<vector<int>> &adj, int n, vector<int> &inDegree)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (inDegree[i] == 0)
                q.push(i);
        vector<int> topo;
        while (!q.empty())
        {
            int it = q.front();
            q.pop();
            topo.push_back(it);
            for (auto i : adj[it])
                if (--inDegree[i] == 0)
                    q.push(i);
        }
        return topo;
    }
    unordered_map<int, vector<int>> dp;
    vector<int> get_max(vector<vector<int>> &adj, vector<bool> &visited, int node, string &color)
    {
        visited[node] = true;
        vector<int> temp(26, 0);
        for (auto it : adj[node])
            if (!visited[it])
            {
                vector<int> x = get_max(adj, visited, it, color);
                for (int i = 0; i < 26; i++)
                    temp[i] = max(temp[i], x[i]);
            }
            else
            {
                for (int i = 0; i < 26; i++)
                    temp[i] = max(temp[i], dp[it][i]);
            }
        temp[color[node] - 'a']++;
        return dp[node] = temp;
    }

public:
    int
    largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            ++inDegree[it[1]];
        }

        vector<int> topo = topo_sort(adj, n, inDegree);
        if (topo.size() != n)
            return -1;
        vector<bool> visited(n, 0);
        vector<int> dp(26, 0);
        int ans = -1;
        for (auto it : topo)
        {
            if (!visited[it])
            {
                vector<int> temp = get_max(adj, visited, it, colors);
                for (auto it : temp)
                    ans = max(ans, it);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        stack<int> st;
        long ans = 0;
        vector<long> prefix(nums.size() + 1);
        prefix[0] = 0;
        for (int i = 1; i <= nums.size(); i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        for (int i = 0; i <= nums.size(); i++)
        {
            while (!st.empty() && (i == nums.size() || nums[st.top()] > nums[i]))
            {
                int x = st.top();
                st.pop();
                long sum = prefix[i] - (st.empty() ? 0 : prefix[st.top() + 1]);
                ans = max(ans, sum * nums[x]);
            }
            st.push(i);
        }
        return ans % 1000000007;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // int dp[1001][2001] = {};
    // int sa(vector<vector<int>> &coins, int idx, int k)
    // {
    //     if (idx == coins.size() || k <= 0)
    //         return 0;
    //     if (dp[idx][k] != -1)
    //         return dp[idx][k];
    //     int coins_sum = 0, temp = 0;
    //     temp = max(temp, sa(coins, idx + 1, k));
    //     for (int j = 0; j < k && j < coins[idx].size(); j++)
    //     {
    //         coins_sum += coins[idx][j];
    //         temp = max(temp, coins_sum + sa(coins, idx + 1, k - j - 1));
    //     }
    //     return dp[idx][k] = temp;
    // }

public:
    int maxValueOfCoins(vector<vector<int>> piles, int K)
    {
        // memset(dp, -1, sizeof dp);
        // return sa(piles, 0, K);

        vector<vector<int>> dp(piles.size() + 1, vector<int>(K + 1, 0));

        for (int i = 1; i <= piles.size(); i++)
        {
            for (int k = 0; k <= K; k++)
            {
                int curr = 0;
                for (int j = 1; j <= k && j < piles[i].size(); j++)
                {
                    curr += piles[i - 1][j - 1];
                    dp[i][k] = max(dp[i][k], curr + dp[i - 1][k - j - 1]);
                }
            }
        }
        return dp[piles.size()][K];
    }
};

int main()
{
}
class Solution
{
public:
    vector<int> findColumnWidth(vector<vector<int>> &grid)
    {
        vector<int> ans(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
            {
                int x = grid[i][j] < 0;

                ans[j] = max(ans[j], (int)to_string(abs(grid[i][j])).size() + x);
            }
        return ans;
    }
};

class Solution
{
public:
    vector<long long> findPrefixScore(vector<int> &nums)
    {
        vector<long long> ans;
        long long sum = 0;
        int maxi = INT_MIN;
        for (auto it : nums)
        {
            maxi = max(maxi, it);
            sum += maxi + it;
            ans.push_back(sum);
        }
        return ans;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    void sum_level(TreeNode *root, int level, unordered_map<int, long> &sumLevel)
    {
        if (!root)
            return;
        sumLevel[level] += root->val;
        sum_level(root->left, level + 1, sumLevel);
        sum_level(root->right, level + 1, sumLevel);
    }

    long dfs(TreeNode *root, unordered_map<int, long> &sums, int level)
    {
        if (!root)
            return 0;
        int sum = dfs(root->left, sums, level + 1) + dfs(root->right, sums, level + 1);
        if (root->left)
            root->left->val = sums[level + 1] - sum;
        if (root->right)
            root->right->val = sums[level + 1] - sum;
        return root->val;
    }

public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        unordered_map<int, long> level_sum;
        sum_level(root, 0, level_sum);
        dfs(root, level_sum, 0);
        root->val = 0;
        return root;
    }
};

class Graph
{
    vector<vector<pair<int, int>>> adj;
    int x;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        adj.resize(n, vector<pair<int, int>>());
        for (auto it : edges)
            adj[it[0]].push_back({it[1], it[2]});
        x = n;
    }

    void addEdge(vector<int> edge)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    int find_shortest_path(int n1, int n2)
    {
        vector<int> distance(x, INT_MAX);
        distance[n1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair stores the distance from source and the node;
        pq.push({0, n1});
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
        return distance[n2] == INT_MAX ? -1 : distance[n2];
    }

    int shortestPath(int node1, int node2)
    {
        return find_shortest_path(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        vector<int> ans = {0, 0};
        for (int i = 0; i < mat.size(); i++)
        {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (ans[1] < sum)
                ans = {i, sum};
        }
        return ans;
    }
};

class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        int score = 0, ans = INT_MAX;
        for (auto it : divisors)
        {
            int tem = 0;
            for (auto i : nums)
                if (i % it == 0)
                    tem++;
            if (tem > score)
            {
                ans = it;
                score = tem;
            }
            else if (tem == score)
                ans = min(ans, it);
        }
        return ans;
    }
};

class Solution
{
public:
    int addMinimum(string word)
    {
        stack<char> st;
        char prev = word[0];
        int ans = 0;
        if (prev == 'b')
            ans = 1;
        else if (prev == 'c')
            ans = 2;
        for (int i = 1; i < word.size(); i++)
        {
            if (prev - word[i] == 1)
                i++;
            else
            {
                if (prev == 'a')
                {
                    ++ans;
                    prev = 'b';
                }
                else if (prev == 'b')
                {
                    ans += 2;
                }
            }
        }
    }
};

class Solution
{
    void dfs(vector<vector<int>> &adj, vector<int> &prices, int x, int y, int node, int end, int &ans, int sum = 0, int prev = -1)
    {

        if (prices[node] > x)
        {
            y = x;
            x = prices[node];
        }
        else if (prices[node] > y)
            y = prices[node];
        int f = sum + prices[node];
        if (node == end)
        {
            ans = f - (x + y) / 2;
            return;
        }
        for (auto it : adj[node])
            if (it != prev)
                dfs(adj, prices, x, y, it, end, ans, f, node);
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        vector<vector<int>> adj(n, vector<int>());
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int res = 0;
        for (auto it : trips)
        {
            int ans = 0;
            dfs(adj, price, 0, 0, it[0], it[1], ans);
        }
        return res;
    }
};

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
        int parent_of_v = find_parent(v);
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
class Solution
{
    void dfs(vector<vector<int>> &adj, vector<int> &prices, int node, int end, unordered_map<int, int> &map, int prev = -1)
    {
        map[node]++;
        for (auto it : adj[node])
            if (it != prev)
                dfs(adj, prices, it, end, map, node);
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        unordered_map<int, int> map;
        multimap<int, int> adjacent;
        vector<vector<int>> adj(n, vector<int>());
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            adjacent.insert({it[0], it[1]});
            adjacent.insert({it[1], it[0]});
        }
        for (auto it : trips)
            dfs(adj, price, it[0], it[1], map);
        priority_queue<int> pq;
        for (auto it : map)
            pq.push(it.first * it.second);
        int res = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
        }
    }
};
class Solution
{
    int dp[1001][1001] = {}, mod = 1000000007;
    int sa(vector<string> &words, string &target, int k = 0, int i = 0)
    {
        if (i == target.size() || i == words[0].size() || words[0].size() - k < target.size() - i)
            return i == target.size();
        if (dp[i][k] != -1)
            return dp[i][k];
        int temp = sa(words, target, k + 1, i);
        for (int j = 0; j < words.size(); j++)
            if (words[j][k] == target[i])
                temp = (0LL + temp + sa(words, target, k + 1, i + 1)) % mod;
        return dp[i][k] = temp % mod;
    }

public:
    int numWays(vector<string> &words, string target)
    {
        memset(dp, -1, sizeof dp);
        return sa(words, target);
    }
};

class Solution
{
    int dp[1001][1001] = {}, mod = 1000000007;
    int sa(vector<string> &words, string &target, vector<vector<int>> &freq, int k = 0, int i = 0)
    {
        if (i == target.size() || i == words[0].size() || words[0].size() - k < target.size() - i)
            return i == target.size();
        if (dp[i][k] != -1)
            return dp[i][k];
        int exclude = sa(words, target, freq, k + 1, i);
        int include = freq[k][target[i] - 'a'] * sa(words, target, freq, k + 1, i + 1);
        return dp[i][k] = (0L + exclude + include) % mod;
    }

public:
    int numWays(vector<string> &words, string target)
    {
        memset(dp, -1, sizeof dp);
        int n = words[0].size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < words.size(); j++)
                freq[i][words[j][i] - 'a']++;
        return sa(words, target, freq);
    }
};

static bool comparator(const pair<int, string> &a, const pair<int, string> &b)
{
    return a.first > b.first;
}
vector<string> Sorter(vector<string> WebPage, vector<int> Backlinks)
{
    vector<pair<int, string>> pages(WebPage.size());
    for (int i = 0; i < WebPage.size(); i++)
        pages[i] = {Backlinks[i], WebPage[i]};
    sort(pages.begin(), pages.end(), comparator);
    vector<string> ans;
    for (auto it : pages)
        ans.push_back(it.second);
    return ans;
}
bool increasePopularity(vector<vector<int>> &adj, vector<long long> &Popularity, int byX, int node, int target, int parent = -1)
{
    if (node == target)
    {
        Popularity[node] += byX;
        return true;
    }
    bool flag = 0;
    for (auto it : adj[node])
    {
        if (it != parent)
        {
            if (increasePopularity(adj, Popularity, byX, it, target, node))
            {
                Popularity[node - 1] += byX;
                return true;
            }
        }
    }
    return false;
}

long long popularity(int N, vector<long long> Popularity, vector<vector<int>> uv, int q, vector<vector<int>> abx)
{
    vector<vector<int>> adj(N + 1, vector<int>());
    for (auto it : uv)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    for (int i = 0; i < q; i++)
    {
        increasePopularity(adj, Popularity, abx[i][2], abx[i][0], abx[i][1]);
    }
    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans += ((i & 1) ? Popularity[i] * -1 : Popularity[i]);
    return abs(ans);
}


