#include <bits/stdc++.h>
using namespace std;
int count(vector<vector<int>> &matrix, int num)
{
    int row = 0, col = matrix.size() - 1, cnt = 0;
    while (col >= 0 && row < matrix.size())
        if (matrix[row][col] > num)
            col--;
        else
            cnt += col + 1, row++;
    return cnt;
    // cout << "ok";
}

class Solution
{
    int count(vector<vector<int>> &matrix, int num)
    {
        int row = 0, col = matrix.size() - 1, cnt = 0;
        while (col >= 0 && row < matrix.size())
            if (matrix[row][col] > num)
                col--;
            else
                cnt += col + 1, row++;
        return cnt;
        // cout << "ok";
    }

public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size(), t = 0, low = matrix[0][0], high = matrix[n - 1][n - 1];
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int cnt = count(matrix, mid);
            if (cnt <= k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

int main()
{

    return 0;
}

class MyCalendar
{
    set<pair<int, int>> events;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto it = events.lower_bound({start, end});
        if (it != events.end() && !(it->first >= end) || (it != events.begin() && !(prev(it)->second <= start)))
            return false;
        events.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class Solution
{
    unordered_map<string, int> dp;
    int sa(vector<int> &tasks, int st, int &ans, int timeLeft, int mask)
    {
        if (mask == 0)
            return 0;
        string key = to_string(mask) + "$" + to_string(timeLeft);
        if (dp.find(key) != dp.end())
            return dp[key];
        int sess = INT_MAX;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (mask & (1 << i))
            {
                if (timeLeft >= tasks[i])
                    sess = sa(tasks, st, ans, timeLeft - tasks[i], ~(1 << i) & mask);
                else
                    sess = min(sess, sa(tasks, st, ans, st - tasks[i], ~(1 << i) & mask) + 1);
            }
        }
        return dp[key] = sess;
    }

public:
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        int mask = 1, n = tasks.size();
        mask = (mask << n) - 1;
        int ans = INT_MAX;
        return sa(tasks, sessionTime, ans, sessionTime, mask);
    }
};

class Solution
{
    int st;
    vector<vector<int>> dp;
    int sa(vector<int> &tasks, int timeLeft, int mask)
    {
        if (mask == 0)
            return timeLeft != st;
        if (dp[mask][timeLeft] != -1)
            return dp[mask][timeLeft];
        int sess = INT_MAX;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (mask & (1 << i))
            {
                if (timeLeft > tasks[i])
                    sess = min(sess, sa(tasks, timeLeft - tasks[i], ~(1 << i) & mask));
                else if (timeLeft == tasks[i])
                    sess = min(sess, sa(tasks, st, ~(1 << i) & mask) + 1);
                else
                    sess = min(sess, sa(tasks, st - tasks[i], ~(1 << i) & mask) + 1);
            }
        }
        return dp[mask][timeLeft] = sess;
    }

public:
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        int mask = 1, n = tasks.size();
        mask = (mask << n) - 1;
        dp.resize(mask + 1, vector<int>(n + 1, -1));
        st = sessionTime;
        int ans = INT_MAX;
        return sa(tasks, sessionTime, mask);
    }
};

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = -1, high = nums.size() - 1;
        while (low + 1 < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high])
                low = mid;
            else
                high = mid;
        }
        return nums[high];
    }
};

class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        int num_ref, up = 1, left_start = 1, side = p;
        while (q)
        {
            num_ref = p / q;
            if (p % q == 0)
            {
                // cout << "state" << left_start << " " << up << ">>";
                if (up)
                {
                    if (((left_start && num_ref % 2 == 0) || (!left_start && num_ref % 2 == 1)))
                        return 2;
                    else
                        return 1;
                }
                else if ((num_ref % 2 == 0 && !left_start) || (num_ref & 1 && left_start))
                    return 0;
            }
            // else cout<<"nt ";
            if (num_ref % 2 == 0)
                left_start = !left_start;
            up = !up;
            p = side - (q - p % q);
            // cout << p << " "
            //  << "statent" << left_start << " " << up << ">>\n";
        }
        return 0;
    }
};

class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        int height = (p * q) / __gcd(p, q),
            n_of_ref = height / q,
            n_of_blocks = height / p;
        if (!(n_of_blocks & 1))
            return 0;
        if (n_of_ref & 1)
            return 1;
        return 2;
    }
};

int kthMex(int n, int k, int arr[])
{
    sort(arr, arr + n);
    int ans = k;
    k -= arr[0];
    if (k <= 0)
        return ans - 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            continue;
        int x = arr[i + 1] - arr[i] - 1;
        if (k - x <= 0)
        {
            return arr[i] + k;
        }
        k -= x;
    }
    return arr[n - 1] + k;
}
/*
Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
*/
class Solution
{
#define MOD 1000000007
public:
    int countVowelPermutation(int n)
    {
        long a = 1, e = 1, i = 1, o = 1, u = 1, a2, e2, i2, o2, u2;
        for (int i = 1; i < n; i++)
        {
            a2 = (e + i + u) % MOD;
            e2 = (a + i) % MOD;
            i2 = (e + o) % MOD;
            o2 = i % MOD;
            u2 = (i + o) % MOD;
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        return (a + e + i + o + u) % MOD;
    }
};
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), size = 0, left, right, mid;
        vector<int> memo(n);
        for (int it : nums)
        {
            left = -1, right = size;
            while (left + 1 < right)
            {
                mid = left + ((right - left) >> 1);
                if (it > memo[mid])
                    left = mid;
                else
                    right = mid;
            }
            if (right == size)
                size++;
            memo[right] = it;
        }
        return size;
    }
};
class Solution
{
public:
    static bool compare(pair<int, char> &a, pair<int, char> &b)
    {
        return a.first > b.first;
    }
    int leastInterval(vector<char> &tasks, int s)
    {
        unordered_map<char, int> map;
        for (char ch : tasks)
            map[ch]++;
        vector<pair<int, char>> v;
        for (auto it : map)
            v.push_back({it.second, it.first});
        sort(v.begin(), v.end(), compare);
        // for (auto it : v)
        //     cout << it.first << " ";
        int next = 0;
        int n = tasks.size(), ans = 0;
        while (n)
        {
            string tasks = "";
            int mini = INT_MAX;
            for (auto it : v)
            {
                if (map[it.second])
                {
                    mini = min(mini, map[it.second]);
                    tasks.push_back(it.second);
                }
                if (tasks.size() > s)
                    break;
            }
            for (char ch : tasks)
            {
                map[ch] -= mini;
                if (map[ch] == 0)
                    map.erase(ch);
            }
            ans += (s + 1) * mini - (s - tasks.size());
            n -= tasks.size() * mini;
        }
        return ans;
    }
};
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int s)
    {
        vector<int> map(26, 0);
        priority_queue<int> pq;

        for (auto ch : tasks)
            map[ch - 'a']++;
        for (auto it : map)
            if (it)
                pq.push(it);

        int emptySlots = s * pq.top();
        pq.pop();
        while (!pq.empty())
        {
            int slotsReq = pq.top();
            pq.pop();
            if (emptySlots < slotsReq)
            {
                emptySlots += (slotsReq - emptySlots) * s;
            }
            emptySlots -= slotsReq;
        }
        if (emptySlots >= s)
            emptySlots -= s;
    }
};

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        long ans = 0, mod = 1e9 + 7;
        unordered_map<int, long> count;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            count[arr[i]] = 1;
            for (int j = 0; j < n; j++)
                if (arr[i] % arr[j] == 0)
                    count[arr[i]] = (count[arr[i]] + count[arr[j]] * count[arr[i] / arr[j]]) % mod;
            ans = (ans + count[arr[i]]) % mod;
        }
        return ans;
    }
};
int solution(int N, vector<int> A)
{
    sort(A.begin(), A.end());
    int sum = 0;
    vector<int> pre(N);
    for (int j = 0; j < N; j++)
    {
        sum += A[j];
        pre[j] = sum;
    }
    int ans = INT_MAX;
    for (int j = 0; j < N; j++)
    {
        if (j == (N - 1))
        {
            int mid = (N / 2);
            int lc = mid + 1, rc = N - mid - 1;
            ans = min(ans, (lc * A[mid] - pre[mid] + pre[N - 1] - pre[mid] - rc * A[mid]));
            // cout << lc << " " << rc << " " << ans << "\n";
        }
        else
        {
            int mid1 = (j + 1) / 2;
            int lc1 = mid1 + 1, rc1 = j - mid1;
            int mid2 = (N - 1 - j + 1) / 2 + j;
            int lc2 = mid2 - j, rc2 = N - 1 - mid2;
            int temp = lc1 * A[mid1] - pre[mid1] + pre[j] - pre[mid1] - rc1 * A[mid1];
            temp += lc2 * A[mid2] - (pre[mid2] - pre[j]) + pre[N - 1] - pre[mid2] - rc2 * A[mid2];
            ans = min(ans, temp);
            // cout << j << " " << mid1 << " " << mid2 << "\n";
        }
    }
    return ans;
}
// class Solution
// {
//     int sa(vector<vector<int>> &g, int n, int m)
//     {
//         int ans = -1;
//         for (int i = n; i < n + 3; i++)
//         {
//             for (int j = m; j < m + 3; j++)
//             {
//                 ans = max(ans, g[i][j]);
//             }
//         }
//         return ans;
//     }

// public:
//     vector<vector<int>> largestLocal(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         vector<vector<int>> ans(n - 2, vector<int>(n - 2));
//         for (int i = 0; i < n - 2; i++)
//         {
//             for (int j = 0; j < n - 2; j++)
//             {
//                 ans[i][j] = sa(grid, i, j);
//             }
//         }
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     int edgeScore(vector<int> &edges)
//     {
//         int n = edges.size();
//         vector<int> ans(n);
//         for (int i = 0; i < n; i++)
//             ans[edges[i]] += i;
//         int s = -1, maxi = -1;
//         for (int i = 0; i < n; i++)
//         {
//             if (maxi < ans[i])
//             {
//                 maxi = ans[i];
//                 s = i;
//             }
//         }
//         return s;
//     }
// };
class Solution
{
public:
    string smallestNumber(string pattern)
    {
        string ans = "";
        int n = pattern.size();
        for (int i; i <= n; i++)
            ans.push_back(char(i + '0'));
        for (int i = 0; i < n; i++)
        {
            while (pattern[i] == 'I')
                i++;
            int start = i;
            while (i < n && pattern[i] == 'D')
                i++;
            int end = i;
            while (start < end)
                swap(ans[start++], ans[end--]);
        }
        return ans;
    }
};
class Solution
{
    unordered_set<int> st;
    bool sa(int n)
    {
        int a = n;
        int arr[10] = {0};
        while (n)
        {
            if (st.find(n) != st.end())
                return false;
            if (arr[n % 10]++)
            {
                st.insert(a);
                return false;
            }
            n = n / 10;
        }
        return true;
    }

public:
    int countSpecialNumbers(int n)
    {
        int ans = 0;
        while (n)
        {
            if (sa(n))
                ans++;
            n--;
        }
        return ans;
    }
};

class Solution
{
    vector<string> get_neighbors(unordered_set<string> &words, string s)
    {
        vector<string> neighbors;
        for (int i = 0; i < s.size(); i++)
        {
            string temp = s;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                temp[i] = ch;
                if (words.count(temp) != 0)
                    neighbors.push_back(temp);
            }
        }
        return neighbors;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> words;
        for (auto &it : wordList)
            words.insert(it);
        int minPathLen = INT_MAX;
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> visited;
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                auto temp = q.front();
                q.pop();
                vector<string> neighbors = get_neighbors(words, temp.back());
                for (auto &it : neighbors)
                {
                    temp.push_back(it);
                    visited.insert(it);
                    if (it == endWord)
                        ans.push_back(temp);
                    else
                        q.push(temp);
                    temp.pop_back();
                }
            }
            if (!ans.empty())
                break;
            for (auto &it : visited)
                words.erase(it);
            visited.clear();
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> w1, w2;
        for (auto &it : words)
            w1[it]++;
        vector<int> ans;
        int wLen = words.back().size();
        for (int i = 0, j; i <= (int)s.size() - (int)words.size() * wLen; i++)
        {
            w2.clear();
            for (j = 0; j < (int)words.size(); j++)
            {
                string temp = s.substr(i + j * wLen, wLen);
                if (w1.find(temp) == w1.end())
                    break;
                w2[temp]++;
                if (w1[temp] < w2[temp])
                    break;
            }
            if (j == words.size())
                ans.push_back(i);
        }
        return ans;
    }
};

class Solution
{
public:
    bool able(string s, string t)
    {
        int c = 0;
        for (int i = 0; i < s.length(); i++)
            c += (s[i] != t[i]);
        return c == 1;
    }
    void bfs(vector<vector<int>> &g, vector<int> parent[], int n, int start, int end)
    {
        vector<int> dist(n, 1005);
        queue<int> q;
        q.push(start);
        parent[start] = {-1};
        dist[start] = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int u : g[x])
            {
                if (dist[u] > dist[x] + 1)
                {
                    dist[u] = dist[x] + 1;
                    q.push(u);
                    parent[u].clear();
                    parent[u].push_back(x);
                }
                else if (dist[u] == dist[x] + 1)
                    parent[u].push_back(x);
            }
        }
    }
    void shortestPaths(vector<vector<int>> &Paths, vector<int> &path, vector<int> parent[], int node)
    {
        if (node == -1)
        {
            // as parent of start was -1, we've completed the backtrack
            Paths.push_back(path);
            return;
        }
        for (auto u : parent[node])
        {
            path.push_back(u);
            shortestPaths(Paths, path, parent, u);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // start and end are indices of beginWord and endWord
        int n = wordList.size(), start = -1, end = -1;
        vector<vector<string>> ANS;
        for (int i = 0; i < n; i++)
        {
            if (wordList[i] == beginWord)
                start = i;
            if (wordList[i] == endWord)
                end = i;
        }

        // if endWord doesn't exist, return empty list
        if (end == -1)
            return ANS;

        // if beginWord doesn't exist, add it in start of WordList
        if (start == -1)
        {
            wordList.emplace(wordList.begin(), beginWord);
            start = 0;
            end++;
            n++;
        }
        // for each word, we're making adjency list of neighbour words (words that can be made with one letter change)
        // Paths will store all the shortest paths (formed later by backtracking)
        vector<vector<int>> g(n, vector<int>()), Paths;

        // storing possible parents for each word (to backtrack later), path is the current sequence (while backtracking)
        vector<int> parent[n], path;

        // creating adjency list for each pair of words in the wordList (including beginword)
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (able(wordList[i], wordList[j]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }

        bfs(g, parent, n, start, end);

        // backtracking to make shortestpaths
        shortestPaths(Paths, path, parent, end);
        for (auto u : Paths)
        {
            vector<string> now;
            for (int i = 0; i < u.size() - 1; i++)
                now.push_back(wordList[u[i]]);
            reverse(now.begin(), now.end());
            now.push_back(wordList[end]);
            ANS.push_back(now);
        }
        return ANS;
    }
};

class Solution
{
    bool canChange(string &a, string &b)
    {

        int i = 0, cnt = 0;
        while (i < a.size())
            cnt += a[i] == b[i];
        return cnt == 1;
    }
    void bfs() public : vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size(), start = -1, end = -1;
        for (int i = 0; i < n; i++)
            if (wordList[i] == beginWord)
                start = i;
            else if (wordList[i] == endWord)
                end = i;

        if (start == -1)
        {
            wordList.emplace(wordList.begin(), beginWord);
            end++, n++;
            start = 0;
        }
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (canChange(wordList[i], wordList[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
    }
};

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0, n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int k = 0;
                for (; k < n; k++)
                    if (grid[i][k] != grid[k][j])
                        break;
                ans += (int)(k == n);
            }
        }
        return ans;
    }
};

class FoodRatings
{
    unordered_map<string, set<pair<int, string>>> food_list;
    unordered_map<string, string> find_cuisine;
    unordered_map<string, int> food_Rating;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            food_list[cuisines[i]].insert({-ratings[i], foods[i]});
            find_cuisine[foods[i]] = cuisines[i];
            food_Rating[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating)
    {
        food_list[find_cuisine[food]].erase({-food_Rating[food], food});
        food_list[find_cuisine[food]].insert({-newRating, food});
        food_Rating[food] = newRating;
    }

    string highestRated(string cuisine)
    {
        return (*food_list[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        if (changed.size() & 1)
            return {};
        map<int, int> freq;
        for (auto &it : changed)
            freq[it]++;
        vector<int> ans;
        if (freq[0])
            ans.resize(freq[0] / 2, 0);
        for (auto &it : freq)
        {
            if (it.second == 0 || it.first == 0)
                continue;
            if (it.second <= freq[it.first * 2])
            {
                for (int i = 0; i < it.second; i++)
                    ans.push_back(it.first);
                freq[it.first * 2] -= it.second;
                freq[it.first] = 0;
            }
            else
                return {};
        }
        return ans;
    }
};
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MAX);
        int left = 0, right = nums.size() - 1;
    }
};

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (auto &it : arr)
            freq[it]++;
        int ans = 0, cnt = 0;
        vector<int> v;
        for (auto &it : freq)
            v.push_back(it.second);
        sort(v.begin(), v.end(), greater<int>());
        for (auto &it : v)
        {
            cnt += it;
            ans++;
            if (it >= arr.size() / 2)
                break;
        }
        return ans;
    }
};
class Solution
{
public:
    long long minCost_to_bid(int numProject, vector<int> &projectId, vector<int> &cost)
    {
        int arr[numProject];
        memset(arr, -1, sizeof(arr));
        long long ans = 0;
        for (int i = 0; i < projectId.size(); i++)
            if (arr[projectId[i]] == -1)
                ans += arr[projectId[i]] = cost[i];
            else
                ans += arr[projectId[i]] + (arr[projectId[i]] = min(arr[projectId[i]], cost[i]));
        return ans;
    }
};
class Solution
{
    void bfs(vector<int> &adj, int start, vector<int> &dis)
    {
        int len = 0;
        while (start != -1 && dis[start] == INT_MAX)
        {
            dis[start] = len++;
            start = adj[start];
        }
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dis1(n, INT_MAX), dis2(n, INT_MAX);
        bfs(edges, node1, dis1);
        bfs(edges, node2, dis2);
        int ans = -1, mini = INT_MAX;
        for (int i = 0; i < n; i++)
            if (dis1[i] != INT_MAX && dis2[i] != INT_MAX)
            {
                if (max(dis1[i], dis2[i]) < mini)
                    ans = i, mini = max(dis1[i], dis2[i]);
            }
        return ans;
    }
};
class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size(), ans = -1;
        vector<pair<int, int>> visited(n, {-1, -1});
        for (int i = 0; i < n; i++)
            for (int idx = i, dist = 0; idx != -1; idx = edges[idx])
                if (visited[idx].first == -1)
                    visited[idx] = {i, dist++};
                else
                {
                    if (visited[idx].first == i)
                        ans = max(ans, dist - visited[idx].second);
                    break;
                }
        return ans;
    }
};

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        map<int, int> freq; // stores freq and len of subsequence in which it's used
        for (int &it : nums)
            freq[it]++;
        unordered_set<int> st;
        while (!freq.empty())
        {
            int start = freq.begin()->first, curr_len = 0;
            for (int i = start; i < start + 3; i++)
                if (freq.find(i) != freq.end())
                {
                    curr_len++;
                    freq[i]--;
                    if (freq[i] == 0)
                        freq.erase(i);
                }
                else
                    break;
            if (curr_len < 3 && st.find(start - 1) != st.end())
            {
                st.erase(start - 1);
                st.insert(start + curr_len - 1);
            }
            else if (curr_len < 3)
                return false;
            st.insert(start + 2);
        }
        return true;
    }
};
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> freq, ends; // stores freq and len of subsequence in which it's used
        for (int &it : nums)
            freq[it]++;
        for (auto &it : nums)
        {
            if (freq[it] == 0)
                continue;
            if (ends[it - 1] > 0)
            {
                ends[it - 1]--;
                ends[it]++;
                freq[it]--;
            }
            else if (freq[it + 1] > 0 && freq[it + 2] > 0)
            {
                ends[it + 2]++;
                freq[it]--;
                freq[it + 1]--;
                freq[it + 2]--;
            }
            else
                return false;
        }
        return true;
    }
};

class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        int l = 0, r = 446;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if ((mid * mid + mid) / 2 <= grades.size())
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};