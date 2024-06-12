#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int get_mask(string &s, int x)
    {
        int mask = 0;
        for (int i = 0; i < 7; i++)
            if (x & (1 << i))
                mask |= (1 << (s[i] - 'a'));
        return mask;
    }

public:
    vector<int> findNumOfValidWords(vector<string> words, vector<string> puzzles)
    {
        unordered_map<int, int> word_count;
        // unordered_set<int> visited;
        for (auto it : words)
        {
            int mask = 0;
            for (auto ch : it)
                mask |= (1 << (ch - 'a'));
            ++word_count[mask];
        }
        vector<int> ans;
        for (auto it : puzzles)
        {
            int res = 0;
            for (int i = 0; i <= 127; i += 2) // both i and i|1 that is i+1 have same mask and will count twice so we take half of the res or increment i by 2;
            {
                int mask = get_mask(it, i | 1);
                if (word_count.find(mask) != word_count.end())
                    res += word_count[mask];
            }
            ans.push_back(res);
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
    void dfs(TreeNode *root, int &ans, int left = 0, int right = 0)
    {
        if (!root)
            return;
        ans = max(ans, max(left, right));
        dfs(root->left, ans, right + 1, 0);
        dfs(root->right, ans, 0, left + 1);
    }

public:
    int longestZigZag(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

class Solution
{
    // int dp[101][101][101] = {};
    int mod = 1000000007;
    // int recurse(vector<int> &group, vector<int> &profit, int minProfit, int n, int idx = 0)
    // {
    //     if (n < 0)
    //         return 0;
    //     if (minProfit < 0) // incase we achieved profit more than our min profit the minProfit will become negative and can cause runtime error so we rest the minProfit to 0;            minProfit = 0;
    //         minProfit = 0;
    //     if (n == 0 || idx >= group.size())
    //         return minProfit == 0;
    //     if (dp[idx][minProfit][n] != -1)
    //         return dp[idx][minProfit][n];
    //     int ans = (0L + recurse(group, profit, minProfit, n, idx + 1)) % mod;
    //     ans = (0L + ans + recurse(group, profit, minProfit - profit[idx], n - group[idx], idx + 1)) % mod;
    //     return dp[idx][minProfit][n] = ans % mod;
    // }

public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        // memset(dp, -1, sizeof dp);
        // return recurse(group, profit, minProfit, n);
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int k = 1; k <= group.size(); k++)
        {
            int p = profit[k - 1];
            int g = group[k - 1];
            for (int i = n; i >= g; i--)
                for (int j = minProfit; j >= 0; j--)
                    dp[i][j] = (dp[i][j] + dp[i - g][max(0, j - p)]) % mod;
        }
        int sum = 0;
        for (int i = 0; i <= n; i++)
            sum = (sum + dp[i][minProfit]) % mod;
        return sum;
    }
};
class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        stack<int> st;
        long ans = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            while (!st.empty() && (i == nums.size() || nums[st.top()] < nums[i]))
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

class Solution
{
    int skills;
    vector<int> ans = {};
    void sa(vector<int> &people_skill_bits, int acquired_skills, int idx, vector<int> &temp)
    {
        if (idx == people_skill_bits.size() || acquired_skills == skills)
        {
            if (acquired_skills == skills && (ans.size() > temp.size() || ans.empty()))
                ans = temp;
            // cout << acquired_skills << " ";
            return;
        }
        if (!ans.empty() && ans.size() < temp.size())
            return;
        sa(people_skill_bits, acquired_skills, idx + 1, temp);
        if (acquired_skills < (acquired_skills | people_skill_bits[idx]))
        {
            temp.push_back(idx);
            sa(people_skill_bits, acquired_skills | people_skill_bits[idx], idx + 1, temp);
            temp.pop_back();
        }
    }

public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        unordered_map<string, int> skill_idx;
        int n = req_skills.size();
        skills = (1 << n) - 1;
        // cout << skills;
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
        vector<int> temp;
        sa(people_skill_bits, 0, 0, temp);
        return ans;
    }
};

class Solution
{
    int dp[301][301] = {};
    int recurse(vector<int> &nums, int i, int j)
    {
        if (j < i)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = 0;
        for (int k = i; k <= j; k++)
            maxi = max(maxi, nums[i - 1] * nums[k] * nums[j + 1] + recurse(nums, i, k - 1) + recurse(nums, k + 1, j));
        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        memset(dp, -1, sizeof dp);
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return recurse(nums, 1, nums.size() - 2);
    }
};

class Solution
{
    // int dp[51][51] = {};
    // int recurse(vector<int> &values, int i, int j)
    // {
    //     if (j - i < 2)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int mini = INT_MAX;
    //     for (int k = i + 1; k < j; k++)
    //         mini = min(mini, values[i] * values[k] * values[j] + recurse(values, i, k) + recurse(values, k, j));
    //     return dp[i][j] = mini;
    // }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        // memset(dp, -1, sizeof dp);
        // return recurse(values, 0, values.size() - 1);
        int dp[51][51] = {0};
        for (int i = values.size() - 1; i >= 0; i++)
        {
            for (int j = i + 2; j < values.size(); j++)
            {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], values[i] * values[k] * values[j] + dp[i][k] + dp[k][j]);
            }
        }
        return dp[values.size() - 1][values.size() - 1];
    }
};

class Solution
{
    // int dp[501] = {};
    // int recurse(vector<int> &nums, int k, int idx)
    // {
    //     if (idx == nums.size())
    //         return 0;
    //     if (dp[idx] != -1)
    //         return dp[idx];
    //     int maxAns = 0;
    //     for (int i = idx, maxNum = -1; i < idx + k && i < nums.size(); i++)
    //     {
    //         maxNum = max(maxNum, nums[i]);
    //         maxAns = max(maxAns, maxNum * (i - idx + 1) + recurse(nums, k, i + 1));
    //     }
    //     return dp[idx] = maxAns;
    // }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        // memset(dp, -1, sizeof dp);
        // return recurse(arr, k, 0);
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            for (int j = i, maxNum = -1; j < i + k && j < n; j++)
            {
                maxNum = max(maxNum, arr[j]);
                dp[i] = max(dp[i], maxNum * (j - i + 1) + dp[j + 1]);
            }
        return dp[0];
    }
};

class Solution
{
    int maxFrom[41][41] = {};
    int dp[41][41] = {};
    int recurse(int i, int j)
    {
        if (j < i)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int k = i, maxi = 0; k < j; k++)
            mini = min(mini, maxFrom[i][k] * maxFrom[k + 1][j] + recurse(i, k) + recurse(k + 1, j));
        return dp[i][j] = mini;
    }

public:
    int mctFromLeafValues(vector<int> &arr)
    {
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < arr.size(); i++)
        {
            maxFrom[i][i] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
                maxFrom[i][j] = max(maxFrom[i][j - 1], arr[j]);
        }
        return recurse(0, arr.size() - 1);
    }
};

class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        int res = 0;                // Initialize the running total cost to 0.
        vector<int> st = {INT_MAX}; // Create a stack `st` with a sentinel value of `INT_MAX`.
        for (auto it : arr)         // Loop through each element of `arr`.
        {
            while (st.back() <= it) // While the top element of `st` is less than or equal to `it`:
            {
                int x = st.back(); // Pop the top element of `st` and store it in `x`.
                st.pop_back();
                // Calculate the cost of combining `x` with the minimum of `it` and the new top element of `st`.
                res += x * min(it, st.back());
            }
            st.push_back(it); // Push `it` onto the stack `st`.
        }
        for (int i = 2; i < st.size(); i++) // Loop through the remaining elements on the stack (excluding the sentinel `INT_MAX`).
            // Calculate the cost of combining each adjacent pair of elements on the stack and add it to the running total `res`.
            res += st[i] * st[i - 1];
        return res; // Return the total minimum cost of the binary tree.
    }
};

class Solution
{
    int memo[100001][2];

public:
    int sa(string &s, int i, bool flag)
    {
        if (i == s.size())
            return 0;
        if (memo[i][flag] != -1)
            return memo[i][flag];
        int ans = INT_MAX;
        if (!flag && s[i] == '1')
        {
            ans = min(ans, 1 + sa(s, i + 1, flag));
        }
        else if (flag && s[i] == '0')
            ans = min(ans, 1 + sa(s, i + 1, 1));
        int leave;
        if (!(flag && s[i] == '0'))
            leave = sa(s, i + 1, s[i] == '1');
        else
            leave = INT_MAX;
        return memo[i][flag] = min(leave, ans);
    }
    int minFlipsMonoIncr(string s)
    {
        memset(memo, -1, sizeof memo);
        return sa(s, 0, 0);
    }
};

class Solution
{
    map<pair<int, int>, int> dp;
    int mod = 1000000007;
    bool sa(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
    int solve(string &s, int i, string t)
    {
        if (t.size() == 5)
            return sa(t);
        if (i == s.size())
            return 0;
        if (dp.find({i, t == "" ? -1 : stoi(t)}) != dp.end())
            return dp[{i, t == "" ? -1 : stoi(t)}];
        int ex = solve(s, i + 1, t);
        int in = solve(s, i + 1, t + s[i]) % mod;
        return dp[{i, t == "" ? -1 : stoi(t)}] = (0LL + ex + in) % mod;
    }

public:
    int countPalindromes(string s)
    {
        dp.clear();
        return solve(s, 0, "");
    }
};

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        vector<int> ans;
        int freq[102] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] + 50]++;
            if (i >= k)
            {
                int i = 0, num = 0;
                while (i < 100 && num < x)
                    num += freq[i++];
                if (num >= x)
                    ans.push_back(i - 50);
                else
                    ans.push_back(0);
            }
        }
        return ans;
    }
};
class SmallestInfiniteSet
{
    priority_queue<int, vector<int>, greater<int>> pq;
    bool added[1001];
    int x;

public:
    SmallestInfiniteSet()
    {
        memset(added, 0, sizeof added);
        x = 1;
    }

    int popSmallest()
    {
        int n;
        if (pq.empty() || x < pq.top())
            n = x++;
        else
        {
            n = pq.top();
            pq.pop();
            added[n] = 0;
        }
        return n;
    }

    void addBack(int num)
    {
        if (num < x && !added[num])
        {
            added[num] = 1;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
const int N = 1e5 + 10;
class Solution
{
public:
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        int n = nums1.size();
        vector<long long> ans;
        long long sum = 0;
        bitset<N> nums1_state(0);
        for (int i = 0; i < nums1.size(); i++)
        {
            sum += nums2[i];
            if (nums1[i])
                nums1_state[i] = 1;
        }
        bitset<N> bit_init(0);
        bit_init.flip();
        for (auto it : queries)
        {
            if (it[0] == 1)
            {
                int sz = it[2] - it[1] + 1; // size of window
                bitset<N> mask = (bit_init << sz);
                mask = ~mask;
                mask = (mask << it[1]);
                nums1_state ^= mask;
            }
            else if (it[0] == 2)
                sum += it[1] * nums1_state.count();
            else
                ans.push_back(sum);
        }
        return ans;
    }
};

class Solution
{
    vector<int> parent;
    int find_parent(int n)
    {
        if (n == parent[n])
            return n;
        return parent[n] = find_parent(parent[n]);
    }

    int is_similar(string &a, string &b)
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
            diff += (a[i] != b[i]);
        return diff == 2 || diff == 0;
    }
    void _union(int a, int b)
    {
        int x = find_parent(a), y = find_parent(b);
        if (x == y)
            return;
        parent[x] = y;
    }

public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (is_similar(strs[i], strs[j]))
                    _union(i, j);
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(find_parent(i));
        return st.size();
    }
};
class DSU
{
    vector<int> parent, rank;
    int n;
    int DSUsize;

public:
    DSU(int size)
    {
        n = DSUsize = size;
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find_parent(int n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = find_parent(parent[n]);
    }
    void _union(int a, int b)
    {
        int x = find_parent(a), y = find_parent(b);
        if (x == y)
            return;
        --DSUsize;
        if (rank[x] < rank[y])
            parent[y] = x;
        else if (rank[x] > rank[y])
            parent[x] = y;
        else
            parent[x] = y, ++rank[y];
    }
    int size()
    {
        return DSUsize;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DSU alice(n), bob(n);
        sort(edges.begin(), edges.end(), greater<int>());
        int ans = 0;
        for (auto it : edges)
        {
            int type = it[0], a = it[1], b = it[2];
            if (type == 3)
            {
                int x = alice.find_parent(a), y = alice.find_parent(b);
                int x1 = bob.find_parent(a), y1 = bob.find_parent(b);
                if (x == y && x1 == y1)
                {
                    ++ans;
                    continue;
                }
                else
                {
                    alice._union(a, b);
                    bob._union(a, b);
                }
            }
            else if (type == 2)
            {
                int x1 = bob.find_parent(a), y1 = bob.find_parent(b);
                if (x1 == y1)
                {
                    ans++;
                    continue;
                }
                else
                    bob._union(a, b);
            }
            else
            {
                int x1 = alice.find_parent(a), y1 = alice.find_parent(b);
                if (x1 == y1)
                {
                    ans++;
                    continue;
                }
                else
                    alice._union(a, b);
            }
        }
        if (alice.size() == 1 && bob.size() == 1)
            return ans;
        return -1;
    }
};

class DSU
{
    vector<int> parent, rank;
    int n;
    int DSUsize;

public:
    DSU(int size)
    {
        n = DSUsize = size;
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find_parent(int n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = find_parent(parent[n]);
    }
    void _union(int a, int b)
    {
        int x = find_parent(a), y = find_parent(b);
        if (x == y)
            return;
        --DSUsize;
        if (rank[x] < rank[y])
            parent[y] = x;
        else if (rank[x] > rank[y])
            parent[x] = y;
        else
            parent[x] = y, ++rank[y];
    }
    int size()
    {
        return DSUsize; // return number of components
    }
    bool isUnited(int a, int b)
    {
        return find_parent(a) == find_parent(b);
    }
};
class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        vector<bool> ans(queries.size());
        sort(edgeList.begin(), edgeList.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });
        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });
        DSU disjoint_set(n);
        int i = 0;
        for (auto it : queries)
        {
            int a = it[0], b = it[1], limit = it[2];
            while (i < edgeList.size() && edgeList[i][2] < limit)
                disjoint_set._union(edgeList[i][0], edgeList[i++][1]);
            ans[it[3]] = disjoint_set.isUnited(a, b);
        }
        return ans;
    }
};

class Solution
{
public:
    int maximizeSum(vector<int> &nums, int n)
    {
        int k = n - 1;
        return *max_element(nums.begin(), nums.end()) * n + (k * k - k) / 2;
    }
};

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        unordered_map<int, int> m1, m2;
        vector<int> ans;
        for (int i = 0; i < A.size(); i++)
        {
            int x = 0;
            if (m1.find(B[i]) != m1.end())
                x++;
            ++m2[B[i]];
            if (m2.find(A[i]) != m2.end())
                x++;
            ++m1[A[i]];

            ans.push_back((ans.empty() ? 0 : ans.back()) + x);
        }
        return ans;
    }
};

class Solution
{
    bool vis[11][11];
    pair<int, int> cords[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        vis[i][j] = 1;
        int ans = grid[i][j];
        for (auto it : cords)
        {
            int x = it.first + i, y = it.second + j;
            if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size() || vis[x][y] || grid[x][y] == 0)
                continue;
            ans += dfs(grid, x, y);
        }
        return ans;
    }

public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int maxi = 0;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (!vis[i][j] && grid[i][j] != 0)
                    maxi = max(maxi, dfs(grid, i, j));
        return maxi;
    }
};

class Solution
{
public:
    long long countOperationsToEmptyArray(vector<int> &nums)
    {
        long long ans = 0;
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++)
            arr.push_back({nums[i], i});
        sort(nums.begin(), nums.end());
    }
};

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.size();
        queue<int> q1, q2;
        for (int i = 0; i < n; i++)
            senate[i] == 'R' ? q1.push(i) : q2.push(i);
        while (!q1.empty() && !q2.empty())
        {
            int x = q1.front(), y = q2.front();
            q1.pop();
            q2.pop();
            x < y ? q1.push(x + n) : q2.push(y + n);
        }
        return q1.empty() ? "Dire" : "Radiant";
    }
};

class Solution
{
    int get_score(vector<int> &pins)
    {
        int score = 0;
        for (int i = 0; i < pins.size(); i++)
        {
            if ((i > 0 && pins[i - 1] == 10) || (i > 1 && pins[i - 2] == 10))
                score += pins[i] * 2;
            else
                score += pins[i];
        }
        return score;
    }

public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int a = get_score(player1), b = get_score(player2);
        return a == b ? 0 : a < b ? 2
                                  : 1;
    }
};

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, pair<int, int>> nums_idx;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                nums_idx[mat[i][j]] = {i, j};
        unordered_map<int, int> row, col;
        for (int i = 0; i < arr.size(); i++)
        {
            auto it = nums_idx[arr[i]];
            if (++row[it.first] == m || ++col[it.second] == n)
                return i;
        }
        return 0;
    }
};
class Solution
{

public:
    int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads)
    {
        typedef tuple<int, int, int> node;
        int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        priority_queue<node> q;
        unordered_map<long, int> dis;
        vector<vector<int>> useful_roads;
        for (auto it : specialRoads)
            if (abs(it[0] - it[2]) + abs(it[1] - it[3]) > it[4])
                useful_roads.push_back(it);
        dis[1L * start[0] * 100000 + start[1]] = 0;
        q.push({0, start[0], start[1]});
        while (!q.empty())
        {

            auto [currCost, currX, currY] = q.top();
            q.pop();
            for (auto &it : useful_roads)
            {
                int x = it[0], y = it[1], next_x = it[2], next_y = it[3], specialCost = it[4];
                long nm = 1L * next_x * 100000 + next_y;
                if (dis.find(nm) == dis.end())
                    dis[nm] = INT_MAX;
                int cost_2_next = currCost + abs(currX - x) + abs(currY - y) + specialCost;
                if (dis[nm] > cost_2_next)
                {
                    q.push({cost_2_next, next_x, next_y});
                    dis[nm] = cost_2_next;
                    ans = min(ans, cost_2_next + abs(target[0] - next_x) + abs(target[1] - next_y));
                }
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int largestRectangleArea(vector<int> &h)
    {
        int ans = -1;
        stack<int> st;
        for (int i = 0; i <= h.size(); i++)
        {
            while (!st.empty() || (i == h.size() && h[st.top()] > h[i]))
            {
                int x = st.top();
                st.pop();
                int left = st.empty() ? 0 : st.top() + 1;
                ans = max(ans, h[x] * (i - left));
            }
            st.push(i);
        }
        return ans;
    }
};

class Solution
{
    vector<vector<int>> dp;
    int mod = 1000000007;
    int recurse(int n, int k)
    {
        if (k == 0 || n == 0)
            return n == 0;
        if (dp[n][k] != -1)
            return dp[n][k];
        int take = 0;
        if (n - k >= 0)
            take = recurse(n - k, k) % mod;
        int leave = recurse(n, k - 1) % mod;
        return dp[n][k] = (take + leave) % mod;
    }

public:
    int numOfWays(int n, int k)
    {
        dp.resize(n + 1, vector<int>(k + 1, -1));
        return recurse(n, k);
    }
};

class Solution
{
public:
    string smallestBeautifulString(string s, int k)
    {
        auto isValid = [&](int i)
        {
            return (i < 1 || s[i] != s[i - 1]) && (i < 2 || s[i] != s[i - 2]);
        };

        int i = s.size();
        while (i > 0)
        {
            ++s[i - 1];
            while (!isValid(i - 1))
                ++s[i - 1];
            if (s[i - 1] - 'a' <= k)
            {
                for (i = i + 1; i <= s.size(); ++i)
                    for (s[i - 1] = 'a'; !isValid(i - 1); ++s[i - 1])
                        ;
                return s;
            }
        }
        return "";
    }
};

class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        map<int, int> map;
    }
};

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        long long ans = 0;
        vector<pair<int, int>> nums;
        for (int i = 0; i < nums1.size(); i++)
            nums.push_back({nums2[i], nums1[i]});
        sort(nums.rbegin(), nums.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (auto &[a, b] : nums)
        {
            if (pq.size() == k)
            {
                sum -= pq.top();
                pq.pop();
            }
            sum += b;
            pq.push(b);
            if (pq.size() == k)
                ans = max(ans, 1LL * sum * a);
        }
        return ans;
    }
};

class Solution
{
    int dp[50005][2] = {};
    int sa(vector<int> &stones, int idx = 0, bool alice = 1)
    {
        if (idx >= stones.size())
            return 0;
        if (dp[idx][alice] != -1)
            return dp[idx][alice];
        int temp = alice == 1 ? INT_MIN : INT_MAX;
        for (int k = idx, sum = 0; k < idx + 3 && k < stones.size(); k++)
        {
            sum += stones[k];
            if (alice)
                temp = max(temp, sum + sa(stones, k + 1, !alice));
            else
                temp = min(temp, sa(stones, k + 1, !alice));
        }
        return dp[idx][alice] = temp;
    }

public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        memset(dp, -1, sizeof dp);
        int alice = sa(stoneValue);
        cout << dp[0][0] << " " << dp[0][1] << endl;
        int totalScore = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        if (totalScore - alice < alice)
            return "Alice";
        else if (totalScore - alice > alice)
            return "Bob";
        return "Tie";
    }
};

class Solution
{
    int dp[101][32][2] = {};
    int sa(vector<int> &stones, int idx = 0, int m = 1, int turn = 0)
    {
        if (idx == stones.size())
            return 0;
        if (dp[idx][m][turn] != -1)
            return dp[idx][m][turn];
        int temp = turn ? INT_MAX : INT_MIN;
        for (int k = 0, sum = 0; k < m * 2 && idx + k < stones.size(); k++)
        {
            sum += stones[idx + k];
            if (turn)
                temp = max(temp, sum + sa(stones, idx + k + 1, max(m, k + 1), !turn));
            else
                temp = max(temp, sa(stones, idx + k + 1, max(m, k + 1), !turn));
        }
        return dp[idx][m][turn] = temp;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        memset(dp, -1, sizeof dp);
        return sa(piles);
    }
};
class Solution
{
    int dp[103][103] = {};
    int sa(vector<int> &cuts, int s, int e)
    {
        if (s == e)
            return 0;
        if (dp[s][e] != -1)
            return dp[s][e];
        int mini = INT_MAX;
        for (int k = s; k < e; k++)
            mini = min(mini, cuts[e] - cuts[s - 1] + sa(cuts, s, k) + sa(cuts, k + 1, e));
        return dp[s][e] = mini;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        memset(dp, -1, sizeof dp);
        return sa(cuts, 1, cuts.size());
    }
};

class Solution
{
    int dp[51] = {};
    int sa(string &s, int idx, unordered_set<string> &words)
    {
        if (idx == s.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int ans = 1 + sa(s, idx + 1, words);
        for (int i = 1; i + idx <= s.size(); i++)
        {
            string temp = s.substr(idx, i);
            if (words.find(temp) != words.end())
                ;
            ans = min(ans, sa(s, idx + i, words));
        }
        return dp[idx] = ans;
    }

public:
    int minExtraChar(string s, vector<string> &d)
    {
        unordered_set<string> w(d.begin(), d.end());
        memset(dp, -1, sizeof dp);
        return sa(s, 0, w);
    }
};

class Solution
{
    void sa(vector<int> &nums, int idx, long long &ans, long long temp)
    {
        if (idx == nums.size())
        {
            ans = max(ans, temp);
            return;
        }
        sa(nums, idx + 1, ans, temp * nums[idx]);
        sa(nums, idx + 1, ans, temp);
    }

public:
    long long maxStrength(vector<int> &nums, int idx = 0)
    {
        long long ans = 0;
        sa(nums, 0, ans, 0LL);
        return ans;
    }
};

class Solution
{

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        vector<pair<int, int>> cord = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        int n = grid.size();
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            if (it.second.first == n - 1 && it.second.second == n - 1)
                return it.first;
            for (auto [x, y] : cord)
            {
                int a = x + it.second.first, b = y + it.second.second;
                if (a < 0 || b < 0 || a == n || b == n || grid[a][b] == 1)
                    continue;
                grid[a][b] = 1;
                q.push({it.first + 1, {a, b}});
            }
        }
        return -1;
    }
};

class Solution
{
    bool can_detonate(vector<int> &a, vector<int> &b)
    {
        int x1 = a[0], y1 = a[1], x2 = b[0], y2 = b[1];
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0) >= a[2];
    }
    bool visited[101] = {0};
    int dfs(vector<vector<int>> &adj, int node)
    {
        visited[node] = true;
        int t = 1;
        for (auto it : adj[node])
            if (!visited[it])
                t += dfs(adj, it);
        // visited[node] = false;
        return t;
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        vector<vector<int>> adj(n + 1, vector<int>());
        for (int i = 0; i < bombs.size(); i++)
        {
            for (int j = 0; j < bombs.size(); j++)
            {
                if (i == j)
                    continue;
                if (can_detonate(bombs[i], bombs[j]))
                    adj[i].push_back(j);
            }
        }
        for (auto it : adj)
        {
            for (auto i : it)
                cout << i << " ";
            cout << " ";
        }
        int ans = 0;
        for (int i = 0; i < bombs.size(); i++)
        {
            memset(visited, 0, sizeof visited);
            ans = max(ans, dfs(adj, i));
        }
        return ans;
    }
};

class Solution
{
    bool check(int val, int maxSum, int n, int idx)
    {
        int left = max(val - idx, 0);
        long result = (val + left) * (val - left + 1) / 2;
        int right = max(val - ((n - 1) - idx), 0);
        result += (val + right) * (val - right + 1) / 2;
        return (result - val <= maxSum);
    }

public:
    int maxValue(int n, int index, int maxSum)
    {
        if (n == 1)
            return maxSum;
        maxSum -= n;
        int left = 1, right = maxSum;
        long long ans = 0;
        while (left < right)
        {
            int mid = left + (right + left) / 2;
            if (check(mid, maxSum, n, index))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

class SnapshotArray
{
    int sp_id;
    vector<int> nums;
    unordered_map<int, vector<pair<int, int>>> prev_val;

public:
    SnapshotArray(int length)
    {
        sp_id = 0;
        nums.resize(length, 0);
    }

    void set(int index, int val)
    {
        if (!prev_val[index].empty() && sp_id == prev_val[index].back().first)
            prev_val[index].back().second = val;
        else
            prev_val[index].push_back({sp_id, val});
    }

    /*
    ["SnapshotArray","snap","snap","get","set","snap","set"]
    [[4],[],[],[3,1],[2,4],[],[1,4]]
    */
    int snap()
    {
        return sp_id++;
    }

    int get(int index, int snap_id)
    {
        auto it = upper_bound(prev_val[index].begin(), prev_val[index].end(), pair<int, int>(snap_id, INT_MAX));
        if (it == prev_val[index].begin())
            return 0;
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

class Solution
{
    vector<vector<int>> pascal_triangle;
    int mod = 1e9 + 7;
    int sa(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return 1;
        vector<int> left, right;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        int left_res = sa(left) % mod, right_res = sa(right) % mod;
        return ((1LL * pascal_triangle[nums.size() - 1][left.size()] * left_res) % mod * right_res) % mod;
    }

public:
    int numOfWays(vector<int> &nums)
    {
        int n = nums.size();
        pascal_triangle.resize(n);
        for (int i = 0; i < nums.size(); i++)
        {
            pascal_triangle[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++)
                pascal_triangle[i][j] = (0L + pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j]) % mod;
        }
        return sa(nums) - 1;
    }
};

class Solution
{
    int dp[2001][2001][2] = {}, maxi = 2000;
    int dfs(vector<int> &a, vector<int> &b, int i, int j, bool prev)
    {
        if (i == a.size())
            return 0;
        int prevElement = prev ? i == 0 ? INT_MIN : a[i - 1] : b[j];
        j = upper_bound(begin(b) + j, end(b), prevElement) - begin(b);
        if (dp[i][j][prev] == 0)
        {
            dp[i][j][prev] = maxi;
            if (j < b.size())
                dp[i][j][prev] = dfs(a, b, i + 1, j, false) + 1;
            if (prevElement < a[i])
                dp[i][j][prev] = min(dp[i][j][prev], dfs(a, b, i + 1, j, true));
        }
        return dp[i][j][prev];
    }

public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(begin(arr2), end(arr2));
        int ans = dfs(arr1, arr2, 0, 0, 1);
        return ans >= maxi ? -1 : ans;
    }
};

class Solution
{
public:
    long long increasingQuadruplets(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);

        // prefix
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    left[i]++;

        // suffix
        for (int i = n - 1; i >= 0; i--)
            for (int j = n - 1; j > i; j--)
                if (nums[i] < nums[j])
                    left[i]++;

        long long ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] < nums[j])
                    ans += left[i] * right[j];
        return ans;
    }
};

class Solution
{
public:
    int minTime(int n, vector<int> &health, vector<int> &power)
    {
        int ans = 0;
        stack<pair<int, int>> st;
        for (int i = 1; i < n; i++)
        {
            int h = health[i];
            while (!st.empty() && h > 0)
            {
                auto it = st.top();
                int take = min((h + it.second - 1) / it.second, it.second);
                h -= take * it.first;
                st.top().second -= take;
                if (st.top().second == 0)
                    st.pop();
            }
            if (st.empty() && h > 0)
            {
                ans += h / power[i - 1];
            }
        }
    }
};

class Solution
{
public:
    bool lovelyCards(int N, vector<int> &Cards)
    {
        bool odd = false, even = false;
        for (int i = 0; i < N; i++)
        {
            odd |= (Cards[i] & 1);
            even |= !(Cards[i] & 1);
        }
        return odd && even;
    }
};

class Solution
{
    int dp[21][10001] = {};
    int sa(vector<int> &rods, int idx = 0, int left_len = 0, int right_len = 0)
    {
        if (idx == rods.size())
            return (right_len == left_len) ? 0 : INT_MIN;
        if (dp[idx][left_len - right_len + 5000] != -1)
            return dp[idx][left_len - right_len + 5000];
        int ans = 0;
        ans = rods[idx] + max(ans, sa(rods, idx + 1, left_len + rods[idx], right_len));
        ans = max(ans, sa(rods, idx + 1, left_len, right_len + rods[idx]));
        ans = max(ans, sa(rods, idx + 1, left_len, right_len));
        return dp[idx][left_len - right_len + 5000] = ans;
    }

public:
    int tallestBillboard(vector<int> &rods)
    {
        memset(dp, -1, sizeof dp);
        return sa(rods);
    }
};

class Solution
{
    int dp[1001][26][26] = {0};
    int sa(vector<string> &words, int idx, int front, int end)
    {
        if (idx == words.size())
            return 0;
        if (dp[idx][front][end] != -1)
            return dp[idx][front][end];
        int ans = 50001;
        ans = min(ans, (int)words[idx].size() - (words[idx][0] - 'a' == end) + sa(words, idx + 1, front, words[idx].back() - 'a'));
        ans = min(ans, (int)words[idx].size() - (words[idx].back() - 'a' == front) + sa(words, idx + 1, words[idx][0] - 'a', end));
        return dp[idx][front][end] = ans;
    }

public:
    int minimizeConcatenatedLength(vector<string> &words)
    {
        memset(dp, -1, sizeof dp);
        return words[0].size() + sa(words, 1, words[0][0] - 'a', words[0].back() - 'a');
    }
};

class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        bool visited[30][30][64] = {0};
        int keys = 0, distance = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '@')
                {
                    q.push({i, j, 0});
                    visited[i][j][0] = true;
                }
                else if (grid[i][j] <= 'f' && grid[i][j] >= 'a')
                    keys++;
        int cord[5] = {0, 1, 0, -1, 0};
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto it = q.front();
                q.pop();
                if (__builtin_popcount(it[2]) == keys)
                    return distance;
                for (int k = 0; k < 4; k++)
                {
                    int x = it[0] + cord[k], y = it[1] + cord[k + 1], key = it[2];
                    if (x < 0 || y < 0 || x == m || y == n || grid[x][y] == '#')
                        continue;
                    char ch = grid[x][y];
                    if (ch >= 'A' && ch <= 'F' && !(key & (1 << (ch - 'A'))))
                        continue;
                    if (ch >= 'a' && ch <= 'f')
                        key = key | (1 << (ch - 'a'));
                    if (!visited[x][y][key])
                        q.push({x, y, key});
                    visited[x][y][key] = true;
                }
            }
            distance++;
        }
        return -1;
    }
};

class Solution
{
    int visited[1001] = {0};
    void sa(vector<vector<pair<int, int>>> &adj, vector<int> &quality, int &maxQuality, int timeLeft, int currQuality = 0, int node = 0)
    {
        if (++visited[node] == 1)
            currQuality += quality[node];
        if (node == 0)
            maxQuality = max(maxQuality, currQuality);
        for (auto [child, time] : adj[node])
            if (timeLeft >= time)
                sa(adj, quality, maxQuality, timeLeft - time, currQuality, child);
        --visited[node];
    }

public:
    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
    {
        int n = values.size();
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int maxQuality = 0;
        sa(adj, values, maxQuality, maxTime);
        return maxQuality;
    }
};

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (1L * m * k > bloomDay.size())
            return -1;
        int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end()) + 1;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            int no_boq_can = 0, temp = 0;
            for (int i = 0; i < bloomDay.size(); i++)
                if (bloomDay[i] <= mid)
                {
                    no_boq_can += ++temp / k;
                    temp %= k;
                }
                else
                    temp = 0;
            if (no_boq_can >= m)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};

class DSU2
{
    vector<int> parent, rank;

public:
    DSU2(int n)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n + 1);
    }
    int find_parent(int n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = find_parent(parent[n]);
    }
    void merge(int x, int y)
    {
        int p_x = find_parent(x), p_y = find_parent(y);
        if (rank[p_x] < rank[p_y])
            parent[p_x] = p_y;
        else if (rank[p_x] > rank[p_y])
            parent[p_y] = p_x;
        else
        {
            parent[p_x] = p_y;
            ++rank[p_y];
        }
    }
};
class Solution
{

public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        vector<vector<bool>> land(row + 2, vector<bool>(col + 1, 0));
        DSU2 *dsu = new DSU2((row + 2) * col + 1);
        int dir[5] = {0, 1, 0, -1, 0};
        auto stretch = [&](int x, int y)
        { return x * col + y; };
        for (int i = 0; i < col - 1; i++)
        {
            dsu->merge(i, i + 1);
            dsu->merge(stretch(row + 1, i), stretch(row + 1, i + 1));
        }
        for (int i = 0; i < col; i++)
        {
            land[0][i] = 1;
            land[row + 1][i] = 1;
        }
        for (int i = cells.size() - 1; i >= 0; i--)
        {
            int a = cells[i][0], b = cells[i][1] - 1;
            for (int k = 0; k < 4; k++)
            {
                int x = a + dir[k], y = b + dir[k + 1];
                if (x < 0 || y < 0 || x > row + 1 || y == col || !land[x][y])
                    continue;
                dsu->merge(stretch(a, b), stretch(x, y));
            }
            if (dsu->find_parent(0) == dsu->find_parent(stretch(row + 1, 0)))
                return i;
            land[a][b] = 1;
        }
        return -1;
    }
};

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xor_nums = 0;
        for (int &it : nums)
            xor_nums ^= it;
        int last_set_bit_pos = xor_nums & (-xor_nums);
        vector<int> ans = {0, 0};
        for (auto it : nums)
            ans[it && (1 << last_set_bit_pos)] ^= it;
        return ans;
    }
};

struct Node
{
    int val;
    Node *next;
    Node(int v, Node *n = NULL)
    {
        val = v;
        next = n;
    }
};
class MyLinkedList
{
    Node *head, *tail;
    int len;

public:
    MyLinkedList()
    {
        head = tail = NULL;
        len = 0;
    }

    int get(int index)
    {
        if (index >= len)
            return -1;
        int idx = 0;
        Node *temp = head;
        while (idx < index)
            temp = temp->next;
        return temp->val;
    }

    void addAtHead(int val)
    {
        if (!head && !tail)
            head = tail = new Node(val);
        else
            head = new Node(val, head);
        ++len;
    }

    void addAtTail(int val)
    {
        if (!head && !tail)
            head = tail = new Node(val);
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
        ++len;
    }

    void addAtIndex(int index, int val)
    {
        if (index > len)
            return;
        if (index == 0)
        {
            addAtHead(val);
            ++len;
            return;
        }
        Node *temp = head;
        int idx = index - 1;
        while (idx < index - 1)
        {
            idx++;
            temp = temp->next;
        }
        if (temp == tail)
        {
            temp->next = new Node(val);
            tail = temp->next;
            ++len;
            return;
        }
        temp->next = new Node(val, temp->next);
        ++len;
    }

    void deleteAtIndex(int index)
    {
        if (index >= len)
            return;
        if (index == 0)
        {
            len = 0;
            Node *temp = head;
            if (len == 1)
                head = tail = NULL;
            else
                head = head->next;
            delete (temp);
            --len;
            return;
        }
        Node *temp = head;
        int idx = 0;
        while (idx < index - 1)
        {
            idx++;
            temp = temp->next;
        }
        Node *t = temp->next;
        temp->next = t->next;
        if (t == tail)
            tail = temp;
        delete (t);
        --len;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

class Solution
{
public:
    int minimumMoney(vector<pair<int, int>> &products)
    {
        sort(products.begin(), products.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first - a.second > b.first - b.second; });
        int maxMoney = 0, currMoney = 0;
        for (auto [worst, expe] : products)
        {
            if (currMoney < worst)
            {
                maxMoney += (worst - currMoney);
                currMoney = worst;
            }
            currMoney -= expe;
        }
        return maxMoney;
    }
};

class Solution
{
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k)
    {
    }
};

vector<int> split(string s)
{
    stringstream ss(s);
    string word;
    vector<int> x;
    while (ss >> word)
        x.push_back(stof(word));
    return x;
}
float distance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}
string check(vector<int> &points)
{
    if (points[0] == points[3] && points[1] == points[4])
        return "Concentric";
    float d = distance(points[0], points[1], points[3], points[4]);
    if (d < max(points[2], points[5]) && d + min(points[2], points[5]) < max(points[2], points[5]))
        return "Disjoint-inside";
    else if (d == points[2] + points[5])
        return "Touching";
    else if (d < points[2] + points[5])
        return "Intersecting";
    else if (d > points[2] + points[5])
        return "Disjoint-Outside";
}
vector<string> solve(vector<string> circlePairs)
{
    vector<string> ans;
    for (string s : circlePairs)
    {
        vector<int> temp = split(s);
        string x = check(temp);
        ans.push_back(x);
    }
    return ans;
}