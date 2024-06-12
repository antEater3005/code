#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> sa(n, vector<int>(m));
        sa[0][0] = dungeon[0][0] < 0 ? dungeon[0][0] : 1;
        for (int i = 1; i < n; i++)
        {
            dungeon[i][0] += dungeon[i - 1][0];
            sa[i][0] = min(sa[i - 1][0], dungeon[i][0]);
        }
        for (int i = 1; i < m; i++)
        {
            dungeon[0][i] += dungeon[0][i - 1];
            sa[0][i] = min(sa[0][i - 1], dungeon[0][i]);
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (sa[i - 1][j] > sa[i][j - 1])
                {
                    dungeon[i][j] += dungeon[i - 1][j];
                    sa[i][j] = min(dungeon[i][j], sa[i - 1][j]);
                }
                else
                {
                    dungeon[i][j] += dungeon[i][j - 1];
                    sa[i][j] = min(dungeon[i][j], sa[i][j - 1]);
                }
        for (auto i : dungeon)
        {
            for (auto it : i)
                cout << it << " ";
            cout << endl;
        }
        return (sa[n - 1][m - 1] < 0 ? abs(sa[n - 1][m - 1]) : 0) + 1;
    }
};

/*
3 3 4 8 10
15 21 24 26 27
28 30 30 31 36
40 41 41 42 49
50 50 53 53 58
*/

/*
[2,3,1,4,4,1,1]
5
[5,6,7,8,9]
4
[3,2,20,1,1,3]
10
[8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309]
134365
[1241,8769,9151,3211,2314,8007,3713,5835,2176,8227,5251,9229,904,1899,5513,7878,8663,3804,2685,3501,1204,9742,2578,8849,1120,4687,5902,9929,6769,8171,5150,1343,9619,3973,3273,6427,47,8701,2741,7402,1412,2223,8152,805,6726,9128,2794,7137,6725,4279,7200,5582,9583,7443,6573,7221,1423,4859,2608,3772,7437,2581,975,3893,9172,3,3113,2978,9300,6029,4958,229,4630,653,1421,5512,5392,7287,8643,4495,2640,8047,7268,3878,6010,8070,7560,8931,76,6502,5952,4871,5986,4935,3015,8263,7497,8153,384,1136]
894887480
*/

//  dcdbeada
struct Node
{
    bool isEnd;
    Node *arr[26];

public:
    Node()
    {
        isEnd = 0;
        memset(arr, NULL, sizeof(arr));
    }
    Node *get(char ch)
    {
        return arr[ch - 'a'];
    }
    void create(char ch)
    {
        arr[ch - 'a'] = new Node();
    }
    bool end()
    {
        return isEnd;
    }
    void setEnd()
    {
        isEnd = 1;
    }
};

// class Trie
// {
// private:
//     Node *root;

// public:
//     Trie()
//     {
//         root = new Node();
//     }
//     void insert(string &s)
//     {
//         Node *t = root;
//         for (char ch : s)
//         {
//             if (!t->get(ch))
//                 t->create(ch);
//             t = t->get(ch);
//         }
//         t->setEnd();
//     }
//     string check(string &s)
//     {
//         Node *t = root;
//         string prefix = "";
//         for (char ch : s)
//         {
//             prefix += ch;
//             if (!t->get(ch))
//                 return s;
//             t = t->get(ch);
//             if (t->end())
//                 return prefix;
//         }
//         return s;
//     }
// };
// class Solution
// {
//     vector<string> tokenize(string &s, string del = " ")
//     {
//         vector<string> ans;
//         int i = 0, j = s.find(del);
//         while (j != -1)
//         {
//             ans.push_back(s.substr(i, j - i));
//             i = j + del.size();
//             j = s.find(del, i);
//         }
//         ans.push_back(s.substr(i, j - i));
//         return ans;
//     }

// public:
//     string replaceWords(vector<string> &dictionary, string sentence)
//     {
//         Trie *head = new Trie;
//         vector<string> words = tokenize(sentence);
//         for (string &s : dictionary)
//             head->insert(s);
//         sentence = "";
//         for (string &s : words)
//             sentence += head->check(s) + ' ';
//         sentence.pop_back();
//         return sentence;
//     }
// };
// struct Node
// {
//     int data;
//     Node *left, *right;
// };

// int previousAndNext(string s)
// {
//     int pSum = 0, nSum = 0;
//     bool a = true, b = true;
//     for (int i = 0; i < s.size(); i++)
//     {
//         int d = s[i] - '0';
//         if (a)
//             if (d % 2 == 0)
//             {
//                 nSum += s.size() - i + d;
//                 a = false;
//             }
//             else
//                 nSum += d;
//         if (b)
//             if (d % 2 == 0)
//             {
//                 if (d == 0)
//                 {
//                     pSum -= pSum < 2 ? pSum : 2;
//                     pSum += (s.size() - i) * 9;
//                 }
//                 else
//                     pSum += d - 1 + (s.size() - i - 1) * 9;
//                 b = 0;
//             }
//             else
//                 pSum += d;
//     }
//     return pSum + nSum;
// }
// class Solution
// {
//     string d2b(int n)
//     {
//         string s = "";
//         while (n)
//         {
//             s = (n % 2 ? '1' : '0') + s;
//             n /= 2;
//         }
//         return s;
//     }
//     int b2d(string s)
//     {
//         int n = 0, fac = 1;
//         for (int i = s.size() - 1; i >= 0; i--)
//         {
//             n = n + fac * (s[i] == '1' ? 1 : 0);
//             fac *= 2;
//         }
//         return n;
//     }

// class Solution
// {
// public:
//     int fillCups(vector<int> &amount)
//     {
//         priority_queue<int> pq;
//         for (int i : amount)
//             pq.push(i);
//         int ans = 0;
//         while (pq.top() != 0)
//         {
//             int t = pq.top();
//             pq.pop();
//             int s = pq.top();
//             pq.pop();
//             pq.push(t - 1);
//             pq.push(s - 1);
//             ans++;
//         }
//         return ans;
//     }
// };

// class Solution
// {
// public:
//     bool canChange(string start, string target)
//     {
//         int i = 0, j = 0, n = target.size();
//         while (i < n || j < n)
//         {
//             while (i < n && start[i] == '_')
//                 i++;
//             while (j < n && target[j] == '_')
//                 j++;
//             if (i < n && j < n)
//             {
//                 if (target[j] != start[i])
//                     return false;
//                 else if (start[i] == 'R' && i > j)
//                     return false;
//                 else if (start[i] == 'L' && i < j)
//                     return false;
//             }
//             else if (i < n || j < n)
//                 return false;
//         }
//         return true;
//     }
// };

// class Solution
// {
//     bool saumya(vector<int> &m, vector<int> &sides, int idx, int &side)
//     {
//         if (idx == m.size())
//         {
//             if (sides[0] == side && sides[1] == side && sides[2] == side && sides[3] == side)
//                 return true;
//             return false;
//         }
//         for (int i = 0; i < 4; i++)
//         {
//             if (sides[i] + m[idx] <= side)
//             {
//                 sides[i] += m[idx];
//                 if (saumya(m, sides, idx + 1, side))
//                     return true;
//                 sides[i] -= m[idx];
//             }
//         }
//         return false;
//     }

// public:
//     bool makesquare(vector<int> &matchsticks)
//     {
//         int peri = accumulate(matchsticks.begin(), matchsticks.end(), 0), n = matchsticks.size();
//         if (peri % 4 != 0 || n < 4)
//             return false;
//         sort(matchsticks.begin(), matchsticks.end(), greater<int>());
//         int side = peri / 4;
//         vector<int> sides(4, 0);
//         return saumya(matchsticks, sides, 0, side);
//     }
// };

// class Solution
// {
//     bool saumya(vector<int> &nums, vector<int> &sides, int idx, const int target)
//     {
//         if (idx == nums.size())
//         {
//             for (int i = 1; i < sides.size(); i++)
//                 if (sides[i - 1] != sides[i])
//                     return false;
//             return true;
//         }
//         for (int i = 0; i < sides.size(); i++)
//         {
//             if (sides[i] + nums[idx] <= target)
//             {
//                 sides[i] += nums[idx];
//                 if (saumya(nums, sides, idx + 1, target))
//                     return true;
//                 sides[i] -= nums[idx];
//             }
//         }
//         return false;
//     }

// public:
//     bool canPartitionKSubsets(vector<int> &nums, int k)
//     {
//         int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
//         if (sum % k != 0 || n < k)
//             return 0;
//         sort(nums.begin(), nums.end(), greater<int>());
//         vector<int> sides(k, 0);
//         return saumya(nums, sides, 0, sum / k);
//     }
// };

// class Solution
// {
//     bool dfs(vector<int> &nums, vector<bool> &visited, int idx, int k, int target, int curr_sum)
//     {
//         if (k == 1)
//             return true;
//         if (idx >= nums.size())
//             return false;
//         if (curr_sum == target)
//             return dfs(nums, visited, 0, k - 1, target, 0);
//         for (int i = idx; i < nums.size(); i++)
//         {
//             if (visited[i] || curr_sum + nums[i] > target)
//                 continue;
//             visited[i] = 1;
//             if (dfs(nums, visited, i + 1, k, target, curr_sum + nums[i]))
//                 return true;
//             visited[i] = 0;
//         }
//         return false;
//     }

// public:
//     bool canPartitionKSubsets(vector<int> &nums, int k)
//     {
//         int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
//         if (sum % k != 0 || n < k)
//             return false;
//         sort(nums.begin(), nums.end(), greater<int>());
//         // for (int i : nums)
//         //     cout << i << " ";
//         vector<bool> visited(n, 0);
//         return dfs(nums, visited, 0, k, sum / k, 0);
//     }
// };

class RandomizedSet
{
    unordered_set<int> st;

public:
    RandomizedSet()
    {
        st.clear();
    }

    bool insert(int val)
    {
        return st.insert(val).second;
    }

    bool remove(int val)
    {
        if (st.count(val) == 0)
            return 0;
        st.erase(val);
        return true;
    }

    int getRandom()
    {
        return *next(st.begin(), rand() % st.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedCollection
{
    unordered_multiset<int> st;

public:
    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        bool f = st.find(val) == st.end();
        st.insert(val);
        return f;
    }

    bool remove(int val)
    {
        if (st.count(val) == 0)
            return 0;
        st.erase(st.find(val));
        return true;
    }

    int getRandom()
    {
        return *next(st.begin(), rand() % st.size());
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x);
};
Node::Node(int x)
{
    data = x;
    left = right = NULL;
}

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
    int dp[51][51][51] = {[0 ... 50] = {[0 ... 50] = {[0 ... 50] = -1}}}, mod = 1e9 + 7;
    pair<int, int> arr[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dfs(int m, int n, int i, int j, int moves)
    {
        if (i < 0 || j < 0 || i == m || j == n)
            return 1;
        if (moves <= 0)
            return 0;
        if (dp[i][j][moves] != -1)
            return dp[i][j][moves];
        long ans = 0;
        for (int k = 0; k < 4; k++)
            ans += dfs(m, n, i + arr[k].first, j + arr[k].second, moves - 1) % mod;
        return dp[i][j][moves] = ans % mod;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(m, n, startRow, startColumn, maxMove) % mod;
    }
};

class Solution
{
    int max = 1e6;
    int dp[101][101][21] = {[0 ... 100] = {[0 ... 100] = {[0 ... 20] = -1}}};

private:
    int saumya(vector<int> &houses, vector<vector<int>> &cost, int h, const int c, int target, int prev)
    {
        if (target < 0)
            return max;
        if (h == houses.size())
            return target == 0 ? 0 : max;
        if (dp[h][target][prev] != -1)
            return dp[h][target][prev];
        if (houses[h] != 0)
            return dp[h][target][prev] = saumya(houses, cost, h + 1, c, target - (houses[h] != prev), houses[h]);
        int ans = max;
        for (int i = 1; i <= c; i++)
            ans = min(ans, cost[h][i - 1] + saumya(houses, cost, h + 1, c, target - (i != prev), i));
        return dp[h][target][prev] = ans;
    }

public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        int ans = saumya(houses, cost, 0, n, target, 0);
        return ans == max ? -1 : ans;
    }
};

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int p = 0, l = 0;
        for (int i : nums)
            m[i]++;
        for (auto i : m)
        {
            p += i.second / 2;
            l += i.second & 1;
        }
        return {p, l};
    }
};
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int ans = -1;
        for (int i : nums)
        {
            int sum = 0, n = i;
            while (n)
            {
                sum += n % 10;
                n /= 10;
            }
            if (m.find(sum) != m.end())
            {
                ans = max(ans, i + m[sum]);
                m[sum] = max(m[sum], i);
            }
            else
                m[sum] = i;
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto q : queries)
        {
            vector<pair<string, int>> tr;
            int i = 0;
            for (; i < nums.size(); i++)
            {
                string t = nums[i].substr(nums[i].size() - q[1]);
                tr.push_back({t, i});
            }
            sort(tr.begin(), tr.end());
            ans.push_back(tr[q[0] - 1].second);
        }
        return ans;
    }
};

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int gcd = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++)
            gcd = __gcd(numsDivide[i], gcd);
        sort(nums.begin(), nums.end());
        int count = 0;
        while (count < nums.size() && gcd % nums[count] != 0)
            count++;
        return count == nums.size() ? -1 : count;
    }
};

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ITR(x, c) for (__typeof(c.begin()) x = c.begin(); x != c.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))
//-------------------------------------------------------

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ret;
        FORR(q, queries)
        {
            vector<pair<string, int>> V;
            int i;
            FOR(i, nums.size())
            {
                V.push_back({nums[i].substr(nums[0].size() - q[1]), i});
            }
            sort(ALL(V));
            ret.push_back(V[q[0] - 1].second);
        }
        return ret;
    }
};

class Solution
{
public:
    int dp[1001][1001] = {};
    int kInversePairs(int n, int k)
    {
        if (k <= 0)
            return k == 0;
        if (dp[n][k] == 0)
        {
            dp[n][k] = 1;
            for (int i = 0; i <= min(k, n - 1); i++)
                dp[n][k] = (dp[n][k] + kInversePairs(n - 1, k - i)) % 1000000007;
        }
        return dp[n][k] - 1;
    }
};

class Solution
{
    int mod = 1000000007;

public:
    int kInversePairs(int n, int k)
    {
        int dp[1001][1001] = {1};
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = (dp[i - 1][j] + (j > 0 ? dp[i][j - 1] : 0)) % mod;
                if (j >= i)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
            }
        return dp[n][k];
    }
};

class Solution
{
public:
    long long countPairs(vector<int> &nums, int k)
    {
        typedef long long ll;
        unordered_map<ll, ll> gcd_s;
        ll count = 0;
        for (int &i : nums)
        {
            int curr_gcd = __gcd(i, k);
            for (auto &it : gcd_s)
                if (it.first * curr_gcd % k == 0)
                    count += it.second;
            gcd_s[curr_gcd]++;
        }
        return count;
    }
};

class Solution
{

public:
    int nthUglyNumber(int n)
    {
        vector<int> ans(n);
        ans[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++)
        {
            ans[i] = min(ans[p2] * 2, min(ans[p3] * 3, ans[p5] * 5));
            if (ans[i] == ans[p2] * 2)
                p2++;
            if (ans[i] == ans[p3] * 3)
                p3++;
            if (ans[i] == ans[p5] * 5)
                p5++;
        }
        return ans[n - 1];
    }
};

class Solution
{
    int ans[1690];

public:
    int nthUglyNumber(int n)
    {
        return ans[n - 1];
    }
    Solution()
    {
        ans[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < 1690; i++)
        {
            ans[i] = min(ans[p2] * 2, min(ans[p3] * 3, ans[p5] * 5));
            if (ans[i] == ans[p2] * 2)
                p2++;
            if (ans[i] == ans[p3] * 3)
                p3++;
            if (ans[i] == ans[p5] * 5)
                p5++;
        }
    }
};

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                matrix[i][j] += matrix[i][j - 1];
        unordered_map<int, int> counter;
        for (int i = 0; i < m; i++)
            for (int j = i; j < m; j++)
            {
                counter = {{0, 1}};
                int curr = 0;
                for (int k = 0; k < n; k++)
                {
                    curr += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    ans += counter.find(curr - target) == counter.end() ? 0 : counter[curr - target];
                    counter[curr]++;
                }
            }
        return ans;
    }
};

class NumMatrix
{
    vector<vector<int>> mat;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        mat.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1] + matrix[i - 1][j - 1] - mat[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return mat[row2 + 1][col2 + 1] - mat[row1][col2 + 1] - mat[row2 + 1][col1] + mat[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

class NumArray
{
    vector<int> sum;

public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        sum.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
    }

    int sumRange(int left, int right)
    {
        return sum[right + 1] - sum[left];
    }
};

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        int p = 0;
        unordered_map<int, int> nums;
        for (int &i : arr)
            nums[i % k]++, i = i % k;
        for (int &i : arr)
        {
            if (i == 0 && nums[i] % 2 == 0 || (k % 2 == 0 && i == k / 2))
            {
                p += nums[i] / 2;
                nums[i] = 0;
                continue;
            }
            int a = -1 * i, b = i > 0 ? k - i : -k - i;
            int m = min(nums[i], nums[a]);
            p += m;
            nums[i] -= m;
            nums[a] -= m;
            m = min(nums[i], nums[b]);
            p += m;
            nums[i] -= m;
            nums[b] -= m;
        }
        cout << p << " ";
        return p == arr.size() / 2;
    }
};

int maximumPath(int n, vector<vector<int>> Matrix)
{
    int max_path = *max_element(Matrix[0].begin(), Matrix[0].end());
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Matrix[i][j] += max(Matrix[i - 1][j], max(j == 0 ? 0 : Matrix[i - 1][j - 1], j == n - 1 ? 0 : Matrix[i - 1][j + 1]));
            max_path = max(Matrix[i][j], max_path);
        }
    }
    return max_path;
}
class Solution
{
    using iter = vector<int>::const_iterator;
    TreeNode *saumya(iter i, iter j)
    {
        if (i >= j)
            return NULL;
        iter mid = i + (j - i) / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = saumya(i, mid);
        root->right = saumya(mid + 1, j);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return saumya(nums.begin(), nums.end());
    }
};

struct trieNode
{
    trieNode *links[26];
    int endOfWord = 0;
};

class Trie
{
    trieNode *root;

public:
    Trie()
    {
        root = new trieNode();
    }

public:
    void insertWord(string s)
    {
        trieNode *temp = root;
        for (char ch : s)
        {
            if (temp->links[ch - 'a'] == NULL)
                temp->links[ch - 'a'] = new trieNode();
            temp = temp->links[ch - 'a'];
        }
        temp->endOfWord++;
    }
    int count(trieNode *root, string &s, vector<int> pos[], int idx)
    {
    }
    int count_words(string &s, vector<int> pos[])
    {
        trieNode *temp = root;
        return count(root, s, pos, -1);
    }
};

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<int> pos[128];
        int i = 0;
        FOR(i, s.size())
        pos[s[i]].push_back(i);
        Trie root;
        FOR(i, words.size())
        root.insertWord(words[i]);
        return root.count_words(s, pos);
    }
};

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<const char *> queue[128];
        for (auto &word : words)
            queue[word[0]].push_back(word.c_str());
        for (char ch : s)
        {
            auto waiting = queue[ch];
            queue[ch].clear();
            for (auto it : waiting)
                queue[*++it].push_back(it);
        }
        return queue[0].size();
    }
};

class Solution
{
    void merge(vector<pair<int, int>> &arr, int l, int mid, int h, vector<int> &ans)
    {
        int left = l, right = mid + 1, count = 0;
        vector<pair<int, int>> temp;
        while (left <= mid && right <= h)
        {
            if (arr[left].first <= arr[right].first)
            {
                temp.push_back(arr[left]);
                ans[arr[left].second] += count;
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                count++;
                right++;
            }
        }
        while (left <= mid)
        {
            ans[arr[left].second] += count;
            temp.push_back(arr[left++]);
        }
        while (right <= h)
            temp.push_back(arr[right++]);
        for (int i = l; i <= h; i++)
            arr[i] = temp[i - l];
    }
    void split(vector<pair<int, int>> &arr, int l, int h, vector<int> &ans)
    {
        if (l < h)
        {
            int mid = (l + h) / 2;
            split(arr, l, mid, ans);
            split(arr, mid + 1, h, ans);
            merge(arr, l, mid, h, ans);
        }
    }

public:
    vector<int> constructLowerArray(int *arr, int n)
    {
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++)
            nums[i] = {arr[i], i};
        vector<int> ans(n, 0);
        split(nums, 0, n - 1, ans);
        return ans;
    }
};

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
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head->next || left == right)
            return head;
        ListNode *dummy_head = new ListNode(0), *tail = dummy_head, *prev = NULL, *curr;
        dummy_head->next = head;
        int i = 0;
        while (i < left - 1)
            tail = tail->next, i++;
        prev = tail->next;
        i = 0;
        ListNode *curr = prev->next, *nxt = curr->next;
        while (i < right - left && nxt)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            i++;
        }
        if (i < right - left)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        curr = tail->next;
        tail->next = prev;
        curr->next = curr;
        return dummy_head->next;
    }
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode list1 = ListNode(0), list2 = ListNode(0), *curr = head;
        ListNode *p1 = &list1, *p2 = &list2;
        while (curr->next)
        {
            if (curr->val < x)
                p1->next = curr, p1 = curr;
            else
                p2->next = curr, p2 = curr;
            curr = curr->next;
        }
        p1->next = list2.next;
        p2->next = NULL;
        return list1.next;
    }
};

class Solution
{
    void merge(vector<pair<int, int>> &nums, vector<int> &ans, int left, int mid, int right)
    {
        vector<pair<int, int>> temp(right - left + 1);
        int m = mid + 1, count = 0, i = 0, l = left;
        while (l <= mid && m <= right)
            if (nums[l] <= nums[m])
            {
                temp[i++] = nums[l];
                ans[nums[l].second] += count;
                l++;
            }
            else
            {
                temp[i++] = nums[m++];
                count++;
            }
        while (l <= mid)
        {
            temp[i++] = nums[l];
            ans[nums[l].second] += count;
            l++;
        }
        while (m <= right)
            temp[i++] = nums[m++];
        for (l = left; l <= right; l++)
            nums[l] = temp[l - left];
    }
    void split(vector<pair<int, int>> &nums, vector<int> &ans, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            split(nums, ans, left, mid);
            split(nums, ans, mid + 1, right);
            merge(nums, ans, left, mid, right);
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        vector<pair<int, int>> arr(nums.size());
        int idx = 0;
        for (int i = 0; i < nums.size(); i++)
            arr[i] = {nums[i], i};
        split(arr, ans, 0, nums.size() - 1);
        return ans;
    }
};

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, maxLen = 0;
        unordered_map<char, int> m;
        for (i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) != m.end())
            {
                maxLen = max(maxLen, i - j);
                j = max(j + 1, m[s[i]]);
            }
            m[s[i]] = i;
        }
        return max(maxLen, int(s.size() - j));
    }
};

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        int first = -1, second = -1;
        first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        second = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        cout << first << " " << second << " ";
        second = second == n ? 0 : second;
        return {(nums[first] == target ? first : -1), (nums[second] == target ? second : -1)};
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || p == root || q == root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q), *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        return !left ? right : left;
    }
};

class Solution
{
    void path(TreeNode *root, vector<TreeNode *> p, TreeNode *target, bool &a)
    {
        if (a || !root)
            return;
        p.push_back(root);
        a = (target == root);
        path(root->left, p, target, a);
        path(root->right, p, target, a);
        p.pop_back();
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> a, b;
        bool f = 0;
        path(root, a, p, f);
        f = 0;
        path(root, b, q, f);
        TreeNode *ans = root;
        for (int i = 1; i < a.size() && i < b.size() && a[i] == b[i]; i++)
        {
            cout << a[i]->val << "->";
            ans = a[i];
        }
        return ans;
    }
};

class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        int a[14] = {0}, b[4] = {0};
        for (int i = 0; i < 5; i++)
            a[ranks[i]]++;
        for (int i = 0; i < 5; i++)
            b[suits[i] - 'a']++;
        for (int i = 0; i < 4; i++)
            if (b[i] == 5)
                return "Flush";
        int m = 0;
        for (int i = 0; i < 14; i++)
            m = max(m, a[i]);
        if (m > 1)
            return m == 3 ? "Three of a Kind" : "Pair";
        return "High Card";
    }
};

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int i = 0;
        long long ans = 0;
        while (i < nums.size())
        {
            long long count = 0;
            while (i < nums.size() && nums[i] == 0)
                i++, count++;
            if (count != 0)
                ans += (count * (count + 1)) / 2;
            i++;
        }
        return ans;
    }
};

class NumberContainers
{
    unordered_map<int, int> mm;
    unordered_map<int, set<int>> index_of;

public:
    NumberContainers()
    {
        // cout << " Number System started--- :) ";
    }

    void change(int index, int number)
    {
        int prev = -1;
        if (mm.find(index) != mm.end())
            prev = mm[index];
        if (number == prev)
            return;
        mm[index] = number;
        if (prev != -1)
            index_of[prev].erase(index);
        index_of[number].insert(index);
    }

    int find(int number)
    {
        if (index_of.find(number) == index_of.end() || index_of[number].empty())
            return -1;
        return *index_of[number].begin();
    }
};

class Solution
{
public:
    int minOperations(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
            pq.push(arr[i]);
        int ans = 0;
        while (pq.top() < k && pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a + b);
            ans++;
        }
        if (pq.top() >= k)
            return ans;
        return -1;
    }
};

vector<int> subarraySum(int arr[], int n, long long k)
{
    if (k == 0)
        return {-1};
    int i = 0, j = 0;
    long long sum = 0;
    for (j = 0; j < n; j++)
    {
        sum += arr[j];
        while (sum > k)
            sum -= arr[i++];
        if (sum == k)
            return {i + 1, j + 1};
    }
    return {-1};
}

// Question 1
// TC = O(N) N=max(len(search_word),len(result));
// SC = O(1)
int minChar_append(string search_word, string result)
{
    int i = 0, j = 0;
    while (i < search_word.size() && j < result.size())
    {
        if (search_word[i] == result[j])
            j++;
        i++;
    }
    return result.size() - j;
}

// Question 2
// TC = O(N)
// SC = O(N),  N=len(stocks array)
long long maxCumulative_stock_sum(vector<int> stocks, int k)
{
    long long ans = 0, sum = 0;
    int prev = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < stocks.size(); i++)
    {
        if (i - prev == k) // if window size is greater than k increase prev and subtract stocks[prev];
            sum -= stocks[prev++];
        sum += stocks[i];

        if (m.find(stocks[i]) != m.end()) // if stocks[i] is already in the window we have to take out all the stocks[j] where j<= m[stocks[i]]
            while (prev <= m[stocks[i]])
                sum -= stocks[prev++];

        m[stocks[i]] = i; // insert the stock[i] in the window
        // if window size if equal to k take the max
        if (i - prev + 1 == k)
            ans = max(ans, sum);
    }
    return ans;
}

class Solution
{
public:
    bool canConvertString(string s, string t, int k)
    {
        if (s.size() != t.size())
            return false;
        int multiplier[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            int moves = (t[i] - s[i] + 26) % 26;
            if (moves != 0 && moves + multiplier[moves] * 26 > k)
                return false;
            multiplier[moves]++;
        }
        return true;
    }
};

int minFlips(string S)
{
    int a = 0, b = 0;
    for (int i = 0; i < S.size(); i++)
    {
        a += ((i & 1) && S[i] == '0') || (!(i & 1) && S[i] == '1') ? 1 : 0; // need '1' at odd index and '0' otherwise
        b += ((i & 1) && S[i] == '1') || (!(i & 1) && S[i] == '0') ? 1 : 0; // need '0' at odd index and '1' otherwise
    }
    return min(a, b);
}
struct node
{
    int data;
    node *next, *down;

    node(int x)
    {
        data = x;
        next = NULL;
        down = NULL;
    }
};

#define MAX 20
node *constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    node *ans = new node(0), *temp = ans, *head;
    vector<node *> prev;
    for (int i = 0; i < n; i++)
    {
        temp->next = new node(mat[0][i]);
        temp = temp->next;
        prev.push_back(temp);
    }
    for (int i = 1; i < n; i++)
    {
        vector<node *> curr(n);
        for (int j = n - 1; j >= 0; j--)
        {
            curr[j] = new node(mat[i][j]);
            curr[j]->next = j == n - 1 ? NULL : curr[j + 1];
            prev[j]->down = curr[j];
        }
        swap(curr, prev);
    }
    return ans->next;
}

vector<long long int> ans(int n, vector<long long int> nums)
{
    vector<long long int> res(n, 0);
    long long int product = 1;
    int count = 0, idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count++;
            idx = i;
            continue;
        }
        product *= nums[i];
    }
    if (count == 1)
    {
        res[idx] = product;
        return res;
    }
    if (count == 2)
        return res;
    for (int i = 0; i < res.size(); i++)
    {
        res[i] = product / nums[i];
    }
    return res;
}

// Question 1
// TC = O(N) N=max(len(search_word),len(result));
// SC = O(1)
int minChar_append(string search_word, string result)
{
    int i = 0, j = 0;
    while (i < search_word.size() && j < result.size())
    {
        if (search_word[i] == result[j])
            j++;
        i++;
    }
    return result.size() - j;
}

// Question 2
// TC = O(N)
// SC = O(N),  N=len(stocks array)
long long maxCumulative_stock_sum(vector<int> stocks, int k)
{
    long long ans = 0, sum = 0;
    int prev = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < stocks.size(); i++)
    {
        if (i - prev == k) // if window size is greater than k increase prev and subtract stocks[prev];
            sum -= stocks[prev++];
        sum += stocks[i];

        if (m.find(stocks[i]) != m.end()) // if stocks[i] is already in the window we have to take out all the stocks[j] where j<= m[stocks[i]]
            while (prev <= m[stocks[i]])
                sum -= stocks[prev++];

        m[stocks[i]] = i; // insert the stock[i] in the window
        // if window size if equal to k take the max
        if (i - prev + 1 == k)
            ans = max(ans, sum);
    }
    return ans;
}

class Solution
{
    int MOD = 1e9 + 7;

public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(target + 1, 0);
            temp[0] = 1;
            for (int j = 1; j <= target; j++)
                for (int m = 1; m <= k && m <= j; m++)
                    temp[j] = (temp[j] + dp[j - m]) % MOD;
            swap(dp, temp);
        }
        return dp[target];
    }
};

string UncommonChars(string A, string B)
{
    int freq[256] = {0};
    for (int i = 0; i < A.size(); i++)
        freq[A[i]] = 1;
    for (int i = 0; i < B.size(); i++)
    {
        if (freq[B[i]] >= 1)
            freq[B[i]]++;
        else
            freq[B[i]] = -1;
    }
    string ans = "";
    for (int i = 0; i < 256; i++)
        if (freq[i] == 1 || freq[i] == -1)
            ans += (char)i;
    if (ans.size() == 0)
        return "-1";
    return ans;
}

static bool check(string &a, string &b)
{
    if (a.size() == b.size())
        return a > b;
    int minLen = min(a.size(), b.size());
    string preA = a.substr(0, minLen), preB = b.substr(0, minLen);
    if (preA == preB)
    {
        int x = a.size() == minLen ? 0 : stoi(a.substr(minLen)), y = b.size() == minLen ? 0 : stoi(b.substr(minLen));
        return x > y;
    }
    else
        return preA > preB;
}
static bool check(string &a, string &b)
{
    string x = a + b, y = b + a;
    long long m = stoll(x), n = stoll(y);
    return m > n;
}

class Solution
{
public:
    static bool check(string &a, string &b)
    {
        return stol(a + b) > stol(b + a);
    }
    string largestNumber(vector<int> &nums)
    {
        vector<string> numbers;
        for (auto it : nums)
            numbers.push_back(to_string(it));
        sort(numbers.begin(), numbers.end(), check);
        string ans = "";
        if (numbers[0] == "0")
            return "0";
        for (auto it : numbers)
            ans += it;
        return ans;
    }
};

class Solution
{
    bool row_check[10][10], col_check[10][10], box_check[3][3][10];
    bool solve(vector<vector<char>> &grid)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == '.')
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (!row_check[i][k] && !col_check[j][k] && !box_check[i / 3][j / 3][k])
                        {
                            grid[i][j] = char(k + 48);
                            row_check[i][k] = 1;
                            col_check[j][k] = 1;
                            box_check[i / 3][j / 3][k] = 1;
                            if (solve(grid))
                                return true;
                            grid[i][j] = '.';
                            row_check[i][k] = 0;
                            col_check[j][k] = 0;
                            box_check[i / 3][j / 3][k] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        memset(row_check, 0, sizeof(row_check));
        memset(col_check, 0, sizeof(col_check));
        memset(box_check, 0, sizeof(box_check));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                {
                    int k = board[i][j] - '0';
                    row_check[i][k] = 1;
                    col_check[j][k] = 1;
                    box_check[i / 3][j / 3][k] = 1;
                }
        solve(board);
    }
};

class Solution
{
    int dp[1001] = {0};
    int sa(vector<int> &nums, int target)
    {
        if (target <= 0)
            return target == 0;
        if (dp[target] != -1)
            return dp[target];
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
            if (target < nums[i])
                break;
            else
                cnt += sa(nums, target - nums[i]);
        return dp[target] = cnt;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        memset(dp, -1, sizeof(dp));
        sort(nums.begin(), nums.end());
        return sa(nums, target);
    }
};
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        for (string s : words)
        {
            if (s.size() != pattern.size())
                continue;
            unordered_set<char> st;
            unordered_map<char, char> map;
            for (int i = 0; i < s.size(); i++)
            {
                map[pattern[i]] = s[i];
                st.insert(s[i]);
            }
            if (st.size() != map.size())
                continue;
            string temp = pattern;
            for (int i = 0; i < temp.size(); i++)
                temp[i] = map[temp[i]];
            if (temp == s)
                ans.push_back(s);
        }
        return ans;
    }
};

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= target; i++)
            for (int j = 0; j < nums.size(); j++)
                if (i - nums[j] >= 0)
                    dp[i] += dp[i - nums[j]] + 0LL;
        return dp[target];
    }
};

class Solution
{
    // int dp[2001];
    // bool is_pal(string &s, int start, int end)
    // {
    //     while (start < end)
    //         if (s[start++] != s[end--])
    //             return false;
    //     return true;
    // }
    // int sa(string &s, int idx, int &ans)
    // {
    //     if (idx == s.size())
    //         return 0;
    //     if (dp[idx] != -1)
    //         return dp[idx];
    //     int count = INT_MAX;
    //     for (int i = idx; i < s.size(); i++)
    //         if (is_pal(s, idx, i))
    //         {
    //             count = min(count, 1 + sa(s, i + 1, ans));
    //         }
    //     return dp[idx] = min(dp[idx], count);
    // }

public:
    int minCut(string s)
    {
        // TopDown Dp
        // memset(dp, -1, sizeof(dp));
        // int ans = INT_MAX;
        // return sa(s, 0, ans);

        // Bottom Up
        int n = s.size();
        vector<int> cuts(n + 1, 0);
        iota(cuts.begin(), cuts.end(), -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++)
                cuts[i + j + 1] = min(cuts[i + j + 1], 1 + cuts[i - j]);
            for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++)
                cuts[i + j + 1] = min(cuts[i + j + 1], 1 + cuts[i - j + 1]);
        }
        return cuts.back();
    }
};

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> ans;
        int temp[26] = {0}, subset[26] = {0};
        for (int i = 0; i < words2.size(); i++)
        {
            memset(temp, 0, sizeof(temp));
            for (int j = 0; j < words2[i].size(); j++)
                subset[words2[i][j] - 'a'] = max(subset[words2[i][j] - 'a'], ++temp[words2[i][j] - 'a']);
        }
        int diff_char = accumulate(begin(subset), end(subset), 0);
        for (int i = 0; i < words1.size(); i++)
        {
            int count = diff_char;
            copy(begin(subset), end(subset), temp);
            for (int j = 0; j < words1[i].size(); j++)
                if (temp[words1[i][j] - 'a'] > 0)
                    count--, temp[words1[i][j] - 'a']--;
            if (count == 0)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int ans = -1, n = heights.size(), i = 0;
        for (i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] > heights[i]))
            {
                int idx = st.top();
                st.pop();
                int x = st.empty() ? 0 : st.top() + 1;
                ans = max(ans, heights[idx] * (i - x));
            }
            st.push(i);
        }
        return ans;
    }
};

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), ans = -1;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] += matrix[i][j] == '1' && i > 0 ? mat[i - 1][j] + 1 : matrix[i][j] - '0';
        for (int i = 0; i < n; i++)
        {
            stack<int> st;
            for (int j = 0; j <= m; j++)
            {
                while (!st.empty() && (j == m || mat[i][st.top()] > mat[i][j]))
                {
                    int ht = st.top();
                    st.pop();
                    int x = st.empty() ? 0 : st.top() + 1;
                    ans = max(ans, mat[i][ht] * (j - x));
                }
                st.push(j);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        clock_t start, end;
        start = clock();
        int n = matrix.size(), m = matrix[0].size(), ans = -1;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] += matrix[i][j] == '1' && i > 0 ? mat[i - 1][j] + 1 : matrix[i][j] - '0';
        for (int i = 0; i < n; i++)
        {
            stack<int> st;
            for (int j = 0; j <= m; j++)
            {
                while (!st.empty() && (j == m || mat[i][st.top()] > mat[i][j]))
                {
                    int ht = st.top();
                    st.pop();
                    int width = j - (st.empty() ? 0 : (st.top() + 1));
                    int side = min(width, mat[i][ht]);
                    ans = max(ans, side * side);
                }
                st.push(j);
            }
        }
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << time_taken << " sec";
        return ans;
    }
};


 