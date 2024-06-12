#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// DAY:1
// 312. Burst Balloons link::https://leetcode.com/problems/burst-balloons/
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    int dp[n][n];
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            int maxCoin = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int left = k == i ? 0 : dp[i][k - 1];
                int right = k == j ? 0 : dp[k + 1][j];
                int val = (i == 0 ? 1 : nums[i - 1]) * nums[k] * (j == n - 1 ? 1 : nums[j + 1]);
                int total = left + right + val;
                maxCoin = max(maxCoin, total);
            }
            dp[i][j] = maxCoin;
        }
    }
    return dp[0][n - 1];
}
// DAY:2
// 1010. Pairs of Songs With Total Durations Divisible by 60  link::https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
int numPairsDivisibleBy60(vector<int> &time)
{
    int ans = 0;
    int t[60] = {0};
    for (int i = 0; i < time.size(); i++)
    {
        if (t[(60 - time[i] % 60) % 60] != 0)
            ans += t[(60 - time[i] % 60) % 60];
        t[time[i] % 60] += 1;
    }
    return ans;
}
// DAY:3
// 997. Find the Town Judge  link::https://leetcode.com/problems/find-the-town-judge/
int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> arr(n, 0);
    for (int i = 0; i < trust.size(); i++)
    {
        arr[trust[i][0] - 1]--;
        arr[trust[i][0] - 1]++;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] == n - 1)
            return i + 1;
    return -1;
}
// DAY:4
//   1009. Complement of Base 10 Integer https://leetcode.com/problems/complement-of-base-10-integer/
int bitwiseComplement(int n)
{
    int mask = 0, num = n;
    while (n)
    {
        mask = (mask << 1) | 1;
        n /= 2;
    }
    return num ^ mask;
    // return (~num) & mask;
}
// DAY:5
// 131. Palindrome Partitioning  https://leetcode.com/problems/palindrome-partitioning/
class Solution1
{
public:
    bool is_palindrome(string str, int start, int end)
    {
        while (start < end)
        {
            if (str[start++] != str[end--])
                return false;
        }
        return true;
    }
    void Thompson(int index, string str, vector<string> path, vector<vector<string>> &res)
    {
        if (index == str.size())
            res.push_back(path);
        else
            for (int i = index; i < str.size(); ++i)
            {
                if (is_palindrome(str, index, i))
                {
                    path.push_back(str.substr(index, i - index + 1));
                    Thompson(i + 1, str, path, res);
                    path.pop_back();
                }
            }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        Thompson(0, s, path, res);
        return res;
    }
};
// Day:6
// 1094. Car Pooling https://leetcode.com/problems/car-pooling/
class Solution
{
public:
    static bool sortcol(const vector<int> &v1,
                        const vector<int> &v2)
    {
        return v1[1] < v2[1];
    }
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        priority_queue<pair<int, int>> pq_leave;
        for (int i = 0; i < trips.size(); i++)
            pq_leave.push({-1 * trips[i][2], trips[i][0]}); // the values are multiplied by -1 to create min heap
        sort(trips.begin(), trips.end(), sortcol);
        int currPassenger = 0;
        for (int i = 0; i < trips.size(); i++)
        {
            if (currPassenger > capacity)
                return false;
            while (!pq_leave.empty() && trips[i][1] >= -1 * pq_leave.top().first)
            {
                currPassenger -= pq_leave.top().second;
                pq_leave.pop();
            }
            currPassenger += trips[i][0];
        }
        if (currPassenger > capacity)
            return false;
        return true;
    }
};
// Day:7 382. Linked List Random Node    https://leetcode.com/problems/linked-list-random-node/
class Solution
{
    int len = 0;
    ListNode *headNode;

public:
    Solution(ListNode *head)
    {
        headNode = head;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
    }

    int getRandom()
    {
        int rand_num = rand() % len;
        ListNode *temp = headNode;
        while (rand_num--)
            temp = temp->next;
        return temp->val;
    }
};

// Day:8 1463. Cherry Pickup II   https://leetcode.com/problems/cherry-pickup-ii/
int cache[71][71][71];
int fun(int row, int c1, int c2, vector<vector<int>> &grid)
{
    if (row >= grid.size() || c1 >= grid[0].size() || c2 >= grid[0].size() || c1 <= -1 || c2 <= -1)
        return 0;
    if (cache[row][c1][c2] != -1)
        return cache[row][c1][c2];

    int cherry_collected = 0;
    if (c1 == c2)
    {
        cherry_collected += grid[row][c1];
    }
    else
        cherry_collected += grid[row][c1] + grid[row][c2];
    int cherry1 = fun(row + 1, c1 - 1, c2 - 1, grid);
    int cherry2 = fun(row + 1, c1 - 1, c2, grid);
    int cherry3 = fun(row + 1, c1 - 1, c2 + 1, grid);

    int cherry4 = fun(row + 1, c1, c2 - 1, grid);
    int cherry5 = fun(row + 1, c1, c2, grid);
    int cherry6 = fun(row + 1, c1, c2 + 1, grid);

    int cherry7 = fun(row + 1, c1 + 1, c2 - 1, grid);
    int cherry8 = fun(row + 1, c1 + 1, c2, grid);
    int cherry9 = fun(row + 1, c1 + 1, c2 + 1, grid);
    cherry_collected += max(cherry1, max(cherry2, max(cherry3, max(cherry4, max(cherry5, max(cherry6, max(cherry7, max(cherry8, cherry9))))))));
    return cache[row][c1][c2] = cherry_collected;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid[0].size();
    memset(cache, -1, sizeof(cache));
    int a = fun(0, 0, n - 1, grid);
    return a <= 0 ? 0 : a;
}

// Day::9 1041. Robot Bounded In Circle    https://leetcode.com/problems/robot-bounded-in-circle/
bool isRobotBounded(string instructions)
{
    pair<int, int> coordinates = {0, 0};
    int direction = 1;
    for (int i = 0; i < instructions.length(); i++)
    {
        char a = instructions[i];                          // for debugging
        int x = coordinates.first, y = coordinates.second; // for debugging
        if (instructions[i] == 'L')
        {
            direction = direction - 1 == 0 ? 4 : direction - 1;
        }
        else if (instructions[i] == 'R')
        {
            direction = direction + 1 == 5 ? 1 : direction + 1;
        }
        else
        {
            if (direction == 1 || direction == 3)

                direction == 1 ? coordinates.second++ : coordinates.second--;

            else
                direction == 2 ? coordinates.first++ : coordinates.first--;
        }
    }
    cout << coordinates.first << " " << coordinates.second << endl; // for debugging
    return ((coordinates.first == 0 && coordinates.second == 0) || direction != 1);
}
// Day::10 67. Add Binary   https://leetcode.com/problems/add-binary/

string addBinary(string a, string b)
{
    string ans = "";
    int carry = 0;
    int al = a.length(), bl = b.length();
    // for (int i = al - 1, j = bl - 1; i >= 0 && j >= 0; i--, j--)
    while (al && bl)
    {
        al--;
        bl--;
        int t = a[al] - '0' + b[bl] - '0' + carry;
        ans = to_string(t % 2) + ans;
        carry = t / 2;
    }

    while (al--)
    {

        ans = to_string((a[al] - '0' + carry) % 2) + ans;
        carry = (a[al] - '0' + carry) / 2;
    }
    while (bl--)
    {

        ans = to_string((b[bl] - '0' + carry) % 2) + ans;
        carry = (b[bl] - '0' + carry) / 2;
    }
    if (carry)
    {
        return ans = '1' + ans;
    }
    return ans;
}

string addBinary(string a, string b)
{
    string ans = "";
    int carry = 0;
    int al = a.length() - 1, bl = b.length() - 1;
    while (al >= 0 || bl >= 0)
    {
        if (al >= 0)
            carry += a[al--] - '0';
        if (bl >= 0)
            carry += b[bl--] - '0';
        ans = to_string(carry % 2) + ans;
        carry = carry > 1 ? 1 : 0;
    }
    if (carry)
        ans = to_string(carry) + ans;
    return ans;
}

// DAY::11 1022. Sum of Root To Leaf Binary Numbers  https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

void UMP(TreeNode *root, int &ans, int temp)
{
    if (!root)
        return;
    if (!root->right && !root->left)
    {
        ans += temp * 2 + root->val;
        return;
    }
    temp = temp * 2 + root->val;
    UMP(root->left, ans, temp);
    UMP(root->right, ans, temp);
}
int sumRootToLeaf(TreeNode *root)
{
    int ans = 0;
    UMP(root, ans, 0);
    return ans;
}
// DAY::12  701. Insert into a Binary Search Tree   https://leetcode.com/problems/insert-into-a-binary-search-tree/

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    else if (root->val < val)
        root->right = insertIntoBST(root->right, val);
    return root;
}
TreeNode *insertIntoBST1(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    TreeNode *curr = root;
    while (true)
    {
        if (curr->val > val)
        {
            if (curr->left)
                curr = curr->left;
            else
            {
                curr->left = new TreeNode(val);
                break;
            }
        }
        else
        {
            if (curr->right)
                curr = curr->right;
            else
            {
                curr->right = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

// DAY::13 452. Minimum Number of Arrows to Burst Balloons   https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    int ans = 0, range = INT_MIN;
    for (int i = 0; i < points.size(); i++)
    {
        if (range < points[i][0])
        {
            ans++;
            range = points[i][1];
        }
        range = min(range, points[i][1]);
    }
    return points.size() == 1 ? 1 : ans;
}

// DAY::14 8. String to Integer (atoi)   https://leetcode.com/problems/string-to-integer-atoi/
int myAtoi(string s)
{
    int ans = 0, i = 0;
    int isNegative = false;

    while (i < s.size())
    {
        while (s[i] == ' ')
        {
            i++;
        }

        if (s[i] == '-' && ans == 0)
            isNegative = true;
        else if (s[i] >= '0' && s[i] <= '9')
        {
            if (ans > INT_MAX / 10)
            {
                return INT_MAX;
            }
            else if (ans < INT_MIN / 10)
            {
                return INT_MIN;
            }
            if (ans != 0 && isNegative)
            {
                ans = ans * -1;
                isNegative = false;
            }
            ans = ans * 10 + s[i] - '0';
        }
        else
            break;
        i++;
    }
    return ans;
}

// DAY::15 1345. Jump Game IV   https://leetcode.com/problems/jump-game-iv/
// This question is based on BFS traversal of graph
int minJumps(vector<int> &arr)
{
    int n = arr.size(), number_of_steps = 0;
    unordered_map<int, vector<int>> index_of_values;
    for (int i = 0; i < n; i++)
        index_of_values[arr[i]].push_back(i);
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        for (int size = q.size(); size > 0; size--)
        {
            int temp = q.front();
            q.pop();
            if (temp == n - 1)
                return number_of_steps;
            vector<int> next = index_of_values[arr[temp]];
            next.push_back(temp - 1);
            next.push_back(temp + 1);
            for (int j : next)
            {
                if (j > 0 && j < n && !visited[j])
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
            index_of_values[arr[temp]].clear();
        }
        number_of_steps++;
    }
    return number_of_steps;
}
// DAY::16 849. Maximize Distance to Closest Person https://leetcode.com/problems/maximize-distance-to-closest-person/
int maxDistToClosest(vector<int> &seats)
{
    int i = 0, prevIdx = -1, maxDis = 0, n = seats.size() - 1;
    while (i < seats.size())
    {
        if (i == 0 && seats[i] == 0)
        {
            while (seats[i] == 0)
            {
                i++;
                maxDis++;
            }
        }
        if (seats[i] == 1)
        {
            if (maxDis < (i - prevIdx) / 2 && prevIdx != -1)
            {
                maxDis = (i - prevIdx) / 2;
            }
            prevIdx = i;
        }
        i++;
    }
    return max(maxDis, n - prevIdx);
}
// DAY::17	290. Word Pattern	https://leetcode.com/problems/word-pattern/
bool wordPattern1(string pattern, string s)
{
    unordered_map<char, string> map;
    unordered_map<string, char> map2;
    int j = 0;
    string temp = "";
    int a = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ')
            a++;
    if (a + 1 != pattern.size())
        return false;
    for (int i = 0; i < pattern.length(); i++)
    {
        while (s[j] != ' ' && j < s.length())
            temp += s[j++];
        j++;
        if (map2.find(temp) != map2.end())
        {
            if (map2[temp] != pattern[i])
                return false;
        }
        else if (map.find(pattern[i]) != map.end())
        {
            if (map[pattern[i]] != temp)
                return false;
        }
        else
        {
            map[pattern[i]] = temp;
            map2[temp] = pattern[i];
        }
        temp = "";
    }
    return true;
}
bool wordPattern2(string pattern, string s)
{

    unordered_map<char, string> map;
    set<string> used;
    int j = 0, cnt = 0;
    string temp = "";
    string a = "";
    for (int i = 0; i < s.length(); i++)
        if (s[i] == ' ')
            cnt++;
    if (cnt + 1 != pattern.size())
        return false;
    for (int i = 0; i < pattern.length(); i++)
    {
        while (s[j] != ' ' && j < s.length())
            temp += s[j++];
        j++;
        if (map.find(pattern[i]) != map.end())
        {
            if (map[pattern[i]] != temp)
                return false;
        }
        else
        {
            if (used.count(temp) > 0)
                return false;
            map[pattern[i]] = temp;
            used.insert(temp);
        }
        temp = "";
    }
    return true;
}
bool wordPattern5(string pattern, string str)
{
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i)
    {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}

// DAY::18 605. Can Place Flowers	https://leetcode.com/problems/can-place-flowers/
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (n == 0)
        return true;
    if (flowerbed.size() == 1)
    {
        if (n == 1 && flowerbed[0] == 0)
            return true;
        else
            return false;
    }
    for (int i = 0; i < flowerbed.size(); i++)
    {

        if (i == 0)
        {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                n--;
                flowerbed[i] = 1;
            }
        }
        else if (i == flowerbed.size() - 1)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
            {
                n--;
                flowerbed[i] = 1;
            }
        }
        else if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
        {
            n--;
            flowerbed[i] = 1;
        }
    }
    return n <= 0;
}
bool canPlaceFlowers3(vector<int> &flowerbed, int n)
{
    if (n == 0)
        return true;
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (flowerbed[i] == 0)
        {
            bool left = i == 0 ? 0 : flowerbed[i - 1];
            bool right = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
            if (!left && !right)
            {
                n--;
                flowerbed[i] = 1;
            }
        }
    }
    return n <= 0 ? 1 : 0;
}
// DAY::19 142. Linked List Cycle II	 https://leetcode.com/problems/linked-list-cycle-ii/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head)
{
    if (!head)
        return head;
    bool flag = false;
    ListNode *fast = head, *slow = head;
    while (fast->next && fast)
    {

        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->next;
    }
    return NULL;
}
// DAY::20 875. Koko Eating Bananas 	https://leetcode.com/problems/koko-eating-bananas/
bool isPossible(vector<int> piles, int can_be, int time)
{
    for (int ele : piles)
        time -= ceil(1.0 * ele / can_be);
    return time >= 0;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int start = 1, end = 0;
    for (int ele : piles)
        end = max(ele, end);
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int time = 0;
        for (int ele : piles)
            time += ceil(1.0 * ele / mid);
        if (h >= time)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

int minEatingSpeed2(vector<int> &piles, int H)
{
    int low = 1, high = 1000000000, k = 0;
    while (low <= high)
    {
        k = (low + high) / 2;
        int h = 0;
        for (int i = 0; i < piles.size(); i++)
            h += ceil(1.0 * piles[i] / k);
        if (h > H)
            low = k + 1;
        else
            high = k - 1;
    }
    return low;
}

// DAY::21 134. Gas Station		https://leetcode.com/problems/gas-station/

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int total_gas = 0, total_cost = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        total_cost += cost[i];
        total_gas += gas[i];
    }
    if (total_gas < total_cost)
        return -1;
    int curr_gas = 0, ans = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        curr_gas += gas[i] - cost[i];
        if (curr_gas < 0)
        {
            ans = i + 1;
            curr_gas = 0;
        }
    }
    return ans;
}
int canCompleteCircuit2(vector<int> &gas, vector<int> &cost)
{

    int curr_gas = 0, start = 0, total_difference = 0;
    ;
    for (int i = 0; i < gas.size(); i++)
    {
        curr_gas += gas[i] - cost[i];
        total_difference += gas[i] - cost[i];
        if (curr_gas < 0)
        {
            start = i + 1;
            curr_gas = 0;
        }
    }

    return total_difference >= 0 ? start : -1;
}

// DAY::21 Stone Game IV	https://leetcode.com/problems/stone-game-iv/
bool kar98(int n, unordered_map<int, bool> &dp)
{
    if (n == 0)
        return false;
    if (dp.find(n) != dp.end())
        return dp[n];
    for (int i = sqrt(n); i >= 1; i--)
    {
        if (!(kar98(n - i * i, dp)))
            return dp[n] = 1;
    }
    return dp[n] = 0;
}
bool winnerSquareGame(int n)
{
    unordered_map<int, bool> dp;
    return kar98(n, dp);
}

// DAY::22	1291. Sequential Digits	https://leetcode.com/problems/sequential-digits/
vector<int> sequentialDigits(int low, int high)
{
    vector<int> ans;
    for (int i = 1; i <= 9; i++)
    {
        int temp = 0;
        for (int j = i; j <= 9; j++)
        {
            temp = temp * 10 + j;
            if (temp <= high && temp >= low)
                ans.push_back(temp);
            if (temp > high)
                break;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// DAY::24 520. Detect Capital	https://leetcode.com/problems/detect-capital/
bool detectCapitalUse(string word)
{
    int capital_count = 0;
    for (char a : word)
        if (isupper(a))
            capital_count++;
    if (capital_count == 0 || (capital_count == 1 && isupper(word[0])) || capital_count == word.length())
        return true;
    return false;
}
bool detectCapitalUse(string word)
{
    for (int i = 1; i < word.length(); i++)
        if (isupper(word[1]) != isupper(word[i]) || islower(word[0]) && isupper(word[i]))
            return 0;
    return 1;
}

// DAY::25 941. Valid Mountain Array		https://leetcode.com/problems/valid-mountain-array/
bool validMountainArray(vector<int> &arr)
{
    if (arr.size() < 3)
        return false;
    int peak_cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i < arr.size() - 1 && arr[i] == arr[i + 1])
            return false;

        if (i > 0 && i < arr.size() - 1 && arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
            peak_cnt++;
    }
    if (peak_cnt == 0 || peak_cnt > 1)
        return false;
    return peak_cnt == 1 && arr[0] < arr[1] && arr[arr.size() - 1] < arr[arr.size() - 2] ? true : false;
}
// solution 2 ::from leetcode discuss section  def validMountainArray(self, A: List[int]) -> bool:
// in this approach we assume there are two persons who climb the mountain from both side, until they reach there first peak if they stop at same place the condition for mountain is fulfilled

bool validMountainArray(vector<int> &arr)
{
    int i = 0, j = arr.size() - 1;
    while (i < j && arr[i] < arr[i + 1])
        i++;
    while (j > 0 && arr[j] < arr[j - 1])
        j--;
    return j == i && i > 0 && j < arr.size() - 1 ? 1 : 0; // we also check for a peak b/w 0 and the arr.size()-1 exclusively;
}

// DAY::26 1305. All Elements in Two Binary Search Trees   https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
void dfs(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    dfs(root->left, ans);
    ans.push_back(root->val);
    dfs(root->right, ans);
}
vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> ans;
    dfs(root1, ans);
    dfs(root2, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
// Instead of sorting we can use two pointers and a third integer vector to store the ans;
vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> v1, v2, ans;
    dfs(root1, v1);
    dfs(root2, v2);
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] > v2[j])
        {
            ans.push_back(v2[j++]);
        }
        else
        {
            ans.push_back(v1[i++]);
        }
    }
    while (i < v1.size())
        ans.push_back(v1[i++]);
    while (j < v2.size())
        ans.push_back(v2[j++]);
    return ans;
}

// DAY::28   211. Design Add and Search Words Data Structure   https://leetcode.com/problems/design-add-and-search-words-data-structure/
// Topic::Trie
struct node
{
    node *link[27];
    bool endOfWord;

    bool containsKey(char ch)
    {
        return link[ch - 'a'];
    }
    node *get_next(char ch)
    {
        return link[ch - 'a'];
    }
    void put(char ch, node *next_reference_node)
    {
        link[ch - 'a'] = next_reference_node;
    }
    void wordComplete()
    {
        endOfWord = true;
    }
};
class WordDictionary
{
private:
    node *root;

public:
    WordDictionary()
    {
        root = new node();
    }

    void addWord(string word)
    {
        node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->containsKey(word[i]))
                temp->put(word[i], new node());
            temp = temp->get_next(word[i]);
        }
        temp->wordComplete();
    }
    bool searchHelp(string word, node *temp)
    {
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (ch == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (temp->link[j])
                    {
                        string a = word.substr(i + 1, word.length()); // this removes a word from the start;and we call for the rest to find int the sub tree
                        if (searchHelp(a, temp->link[j]))
                            return true;
                    }
                }
                return false;
            }
            else if (!temp->containsKey(ch))
                return false;
            temp = temp->get_next(ch);
        }
        return temp->endOfWord;
    }
    bool search(string word)
    {
        node *temp = root;
        return searchHelp(word, root);
    }
};

// DAY::29   84. Largest Rectangle in Histogram    https://leetcode.com/problems/largest-rectangle-in-histogram/
/**MONOTONIC STACK::it's a stack of elements either in increasing or decreasing order;*/
int largestRectangleArea(vector<int> &heights)
{
    int ans = 0, n = heights.size();
    int l_smaller[n];
    l_smaller[0] = -1;
    int r_smaller[n];
    r_smaller[n - 1] = n;

    for (int i = 1; i < n; i++)
    {
        int p = i - 1;
        while (p >= 0 && heights[p] >= heights[i])
            p = l_smaller[p];
        l_smaller[i] = p;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int p = i + 1;
        while (p < n && heights[p] >= heights[i])
            p = r_smaller[p];
        r_smaller[i] = p;
    }
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (r_smaller[i] - l_smaller[i] - 1));
    }

    return ans;
}
/**Method::2::Using stack */
int largestRectangleArea(vector<int> &h)
{
    stack<int> st;
    int i = 0, n = h.size(), ans = 0;
    while (i < n)
    {
        while (!st.empty() && h[st.top()] > h[i])
        {
            int ht = h[st.top()];
            st.pop();
            if (st.empty())
                ans = max(ans, ht * i);
            else
            {
                int width = i - st.top() - 1;
                ans = max(ans, ht * width);
            }
        }
        st.push(i++);
    }
    while (!st.empty())
    {
        int ht = h[st.top()];
        st.pop();
        if (st.empty())
            ans = max(ans, ht * i);
        else
        {
            int width = i - st.top() - 1;
            ans = max(ans, width * ht);
        }
    }

    return ans;
}

/**DAY::30 189. Rotate Array    https://leetcode.com/problems/rotate-array/*/
/**Solution::1*/
void rotate(vector<int> &nums, int k)
{
    vector<int> ans;
    k %= nums.size();
    for (int i = nums.size() - k; i < nums.size(); i++)
        ans.push_back(nums[i]);
    for (int i = 0; i < nums.size() - k; i++)
        ans.push_back(nums[i]);
    nums = ans;
}
/**Solution::2*/
void rotate(vector<int> &nums, int k)
{
    k %= nums.size();
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}

/**DAY::31 1672. Richest Customer Wealth    https://leetcode.com/problems/richest-customer-wealth/ */
int maximumWealth(vector<vector<int>> &accounts)
{
    int max_money = 0;
    for (int i = 0; i < accounts.size(); i++)
    {
        int curr_max = 0;
        for (int j = 0; j < accounts[i].size(); j++)
            curr_max += accounts[i][j];

        max_money = max(max_money, curr_max);
    }
    return max_money;
}
int main()
{
    cout << winnerSquareGame(2) << "\n";

    return 0;
}
