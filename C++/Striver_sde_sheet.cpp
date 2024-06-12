#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// DAY::1:: 73. Set Matrix Zeroes    https://leetcode.com/problems/set-matrix-zeroes/
/**space complexity::O(n+m)
        time complexity::O(n*m)*/
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<bool> arr_i(n, 0);
    vector<bool> arr_j(m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 0)
            {
                arr_i[i] = 1;
                arr_j[j] = 1;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr_i[i] || arr_j[j])
                matrix[i][j] = 0;
    return;
}
/**constant space solution*/
void setZeroes2(vector<vector<int>> &matrix)
{
    bool row = 0, col = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
            if (i == 0 && matrix[i][j] == 0)
                col = 1;
            if (j == 0 && matrix[i][j] == 0)
                row = 1;
        }
    }
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (row)
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    if (col)
        for (int j = 0; j < matrix[0].size(); j++)
            matrix[0][j] = 0;
}

// 698. Partition to K Equal Sum Subsets    https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++)
    {
        vector<int> temp;
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i)
                temp.push_back(1);
            else
            {
                int next = ans[i - 2][j - 2] + ans[i - 2][j - 1]; // add two consecutive elements from the previously pushed array;
                temp.push_back(next);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> Xor;
    int currxor = 0, ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        currxor ^= arr[i];
        if (currxor == x)
            ans++;
        if (Xor.find(currxor ^ x) != Xor.end())
        {
            ans += Xor[currxor ^ x];
        }
        Xor[currxor]++;
    }
    return ans;
}
int lengthOfLongestSubstring(string s)
{
    vector<int> occur(256, -1);
    int start = -1, maxLen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (occur[s[i]] > start)
            start = occur[s[i]];
        occur[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}
ListNode *reverseList(ListNode *head)
{
    if (!head)
        return head;
    ListNode *prev = NULL, *curr = head, *nxt = head->next;
    while (nxt)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    curr->next = prev;
    return curr;
}
ListNode *middleNode(ListNode *head)
{
    ListNode *r = head, *t = head;
    while (r && r->next)
    {
        r = r->next->next;
        t = t->next;
    }
    return t;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    ListNode *head = list1->val > list2->val ? list2 : list1;
    head->next = list1->val > list2->val ? mergeTwoLists(list1, list2->next) : mergeTwoLists(list1->next, list2);
    return head;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *Nth = head, *t = head, *prev;
    while (n--)
        Nth = Nth->next;
    while (Nth)
    {
        prev = t;
        t = t->next;
        Nth = Nth->next;
    }
    if (t == head)
        return head->next;
    else
        prev->next = t->next;
    delete (t);
    return head;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp = new ListNode(0), *result;
    int carry = 0;
    result = temp;
    while (l1 && l2)
    {
        int sum = l1->val + l2->val + carry;
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
        carry = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    ListNode *t = !l1 ? l2 : l1;
    while (t)
    {
        int sum = t->val + carry;
        temp->next = new ListNode(sum % 10);
        carry = sum / 10;
        t = t->next;
        temp = temp->next;
    }
    if (carry)
    {
        temp->next = new ListNode(carry);
    }
    return result->next;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *A = headA, *B = headB;
    int a = 0, b = 0;
    while (A)
    {
        a++;
        A = A->next;
    }
    while (B)
    {
        b++;
        B = B->next;
    }
    int d = a - b;
    A = headA;
    B = headB;
    if (d < 0)
        while (d++ != 0)
            B = B->next;
    else if (d > 0)
        while (d--)
            A = A->next;
    while (A && B)
    {
        if (A == B)
            return A;
        A = A->next;
        B = B->next;
    }
    return NULL;
}
bool hasCycle(ListNode *head)
{
    ListNode *r = head, *t = head;
    while (r && r->next)
    {
        r = r->next->next;
        t = t->next;
        if (t == r)
            return true;
    }
    return false;
}

ListNode *reve(ListNode *head, ListNode *end)
{
    ListNode *prev = NULL, *nxt = head->next;
    while (head != end)
    {
        head->next = prev;
        prev = head;
        head = nxt;
        nxt = nxt->next;
    }
    head->next = prev;
    return head;
}
bool isPalindrome(ListNode *head)
{
    if (!head->next)
        return true;
    ListNode *fast = head, *slow = head;
    bool flag = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast)
        flag = true;
    fast = reve(head, slow);
    if (flag)
        slow = slow->next;
    while (fast)
    {
        if (fast->val != slow->val)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    bool flag = false;
    while (!flag && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            flag = 1;
    }
    if (flag)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (!k || !head)
        return head;
    ListNode *temp = head;
    int a = 1;
    while (temp->next)
    {
        a++;
        temp = temp->next;
    }
    temp->next = head;
    temp = head;
    a = a - (k % a);
    for (int i = 1; i < a; i++)
        temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
}
void twosum(vector<vector<int>> &ans, vector<int> nums, int start, int end, int target)
{
    while (start < end)
    {
        int sum = nums[start] + nums[end];
        if (sum == target)
        {
            ans.push_back({-target, nums[start], nums[end]});
            while (start < end && nums[start] == nums[start + 1])
                start++;
            while (start < end && nums[end] == nums[end - 1])
                end--;
            start++;
            end--;
        }
        else if (sum > target)
            end--;
        else
            start++;
    }
}
// [-2,0,0,2,2]
vector<vector<int>> threeSum(vector<int> &nums)
{
    if (nums.size() < 3)
        return {};
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    twosum(ans, nums, 1, nums.size() - 1, -nums[0]);
    for (int i = 1; i < nums.size() - 1; i++)
    {
        if (nums[i] != nums[i - 1])
            twosum(ans, nums, i + 1, nums.size() - 1, -nums[i]);
    }
    return ans;
}
vector<vector<int>> threeSum1(vector<int> &nums)
{
    if (nums.size() < 3)
        return {};
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int start = i + 1, end = nums.size() - 1;
        if (i == 0 || nums[i] != nums[i - 1])
        {
            while (start < end)
            {
                int sum = nums[start] + nums[end];
                if (sum == -nums[i])
                {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while (start < end && nums[start] == nums[start + 1])
                        start++;
                    while (start < end && nums[end] == nums[end - 1])
                        end--;
                    start++;
                    end--;
                }
                else if (sum > -nums[i])
                    end--;
                else
                    start++;
            }
        }
    }
    return ans;
}
/**TC=O(n)
 * SC=O(n) */
int trap1(vector<int> &height)
{
    int length = height.size(), left_max = height[0], right_max = height[length - 1], trappedWater = 0;
    vector<int> depth(length, 100005);
    for (int left = 0; left < length; left++)
    {
        int right = length - left - 1;
        left_max = max(left_max, height[left]);
        depth[left] = min(depth[left], left_max);
        right_max = max(right_max, height[right]);
        depth[right] = min(depth[right], right_max);
    }
    for (int i = 0; i < length; i++)
    {
        cout << depth[i] << " ";
        trappedWater += depth[i] - height[i];
    }
    return trappedWater;
}
/** optimized solution
 * TC=O(n)
 * SC=O(1) */
int trap(vector<int> &height)
{
    int left = 0, right = height.size() - 1, left_max = height[0], right_max = height[right], trappedWater = 0;

    while (left <= right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= left_max)
                left_max = height[left];
            else
                trappedWater += left_max - height[left];
            left++;
        }
        else
        {
            if (right_max <= height[right])
                right_max = height[right];
            else
                trappedWater += right_max - height[right];
            right--;
        }
    }

    return trappedWater;
}
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() < 2)
        return nums.size();
    int change = 1, curr = 1;
    while (curr < nums.size())
    {
        if (nums[change - 1] != nums[curr])
            swap(nums[change++], nums[curr]);
        curr++;
    }
    return change;
}
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = 0, curr = 0;
    for (int a : nums)
    {
        if (a == 0)
        {
            maxi = max(curr, maxi);
            curr = 0;
        }
        else
            curr++;
    }
    return max(maxi, curr);
}
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> meeting;
    for (int i = 0; i < n; i++)
        meeting.push_back({start[i], end[i]});
    sort(meeting.begin(), meeting.end());
    int ans = 1, endtime = meeting[0].second;
    for (int i = 0; i < n; i++)
    {
        if (meeting[i].first >= endtime)
        {
            ans++;
            endtime = meeting[i].second;
        }
    }
    return ans;
}
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 0, j = 0, maxi = 0, ans = 0;
    while (j < n && i < n)
    {
        if (arr[i] <= dep[j])
        {
            i++;
            maxi += 1;
        }
        else
        {
            maxi--;
            j++;
        }
        ans = max(maxi, ans);
    }
    return ans;
}
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
static bool com(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, com);
    vector<bool> slot(n, 0);
    int noOfJobs = 0, maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead - 1; j >= 0; j--) // find slots less than the deadline
        {
            if (slot[j])
                continue;
            else
            {
                slot[j] = 1;
                maxProfit += arr[i].profit;
                noOfJobs++;
                break;
            }
        }
    }
    return {noOfJobs, maxProfit};
}
ListNode *swapPairs(ListNode *head)
{
    if (!head->next || !head)
        return head;
    ListNode *dummyhead = new ListNode(0), *prev = head, *curr = head->next, *next = curr->next;
    dummyhead->next = head->next;
    while (true)
    {
        curr->next = prev;
        if (!next || !next->next)
        {
            curr->next = prev;
            prev->next = next;
            break;
        }
        else
        {
            prev->next = next->next;
            curr = prev->next;
            prev = next;
            next = curr->next;
        }
    }
    return dummyhead->next;
}
bool columnCheck(vector<vector<char>> mat)
{
    for (int i = 0; i < 9; i++)
    {
        set<char> freq;
        for (int j = 0; j < 9; j++)
        {
            if (mat[i][j] != '.')
            {
                if (freq.count(mat[i][j]))
                    return false;
                freq.insert(mat[i][j]);
            }
        }
    }
    return true;
}
bool rowCheck(vector<vector<char>> mat)
{
    for (int j = 0; j < 9; j++)
    {
        set<char> freq;
        for (int i = 0; i < 9; i++)
        {
            if (mat[i][j] != '.')
            {
                if (freq.count(mat[i][j]))
                    return false;
                freq.insert(mat[i][j]);
            }
        }
    }
    return true;
}
bool squareCheck(vector<vector<char>> mat)
{
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            set<char> freq;
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    if (mat[k][l] != '.')
                    {
                        if (freq.count(mat[k][l]))
                            return false;
                        freq.insert(mat[k][l]);
                    }
                }
            }
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char>> &mat)
{
    return columnCheck(mat) && rowCheck(mat) && squareCheck(mat);
}
bool isValidSudoku(vector<vector<char>> &mat)
{

    for (int i = 0; i < 9; i++)
    {
        vector<int> colm(9, 0);
        vector<int> row(9, 0);
        for (int j = 0; j < 9; j++)
        {
            if (mat[i][j] != '.')
            {
                if (colm[mat[i][j] - '1'] == 0)
                    colm[mat[i][j] - '1'] += 1;
                else
                    return 0;
            }
            if (mat[j][i] != '.')
            {
                if (row[mat[j][i] - '1'] == 0)
                    row[mat[j][i] - '1'] += 1;
                else
                    return 0;
            }
            if (i % 3 == 0 && j % 3 == 0)
            {
                vector<int> box(9, 0);
                for (int k = i; k < (i + 3); k++)
                {
                    for (int l = j; l < (j + 3); l++)
                    {
                        if (mat[k][l] != '.')
                        {
                            if (box[mat[k][l] - '1'] == 0)
                                box[mat[k][l] - '1'] += 1;
                            else
                                return 0;
                        }
                    }
                }
            }
        }
    }

    return 1;
}
class Solution
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    }
};

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int count = 0;
        int j = 0;
        for (int i = 0; i < players.size() && j < trainers.size(); i++)
        {
            if (players[i] <= trainers[j])
            {
                count++;
                j++;
            }
        }
        return count;
    }
};
class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int p = nums.size() - 1, sa = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (sa | nums[i] >= sa)
            {
                sa |= nums[i];
                p = i;
            }
            ans[i] = p - i + 1;
        }
        return ans;
    }
};
class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    static bool compare1(vector<int> &a, vector<int> &b)
    {

        return a[0] < b[0];
    }

    long long minimumMoney(vector<vector<int>> &transactions)
    {
        // sort(transactions.begin(), transactions.end(), compare);
        vector<vector<int>> g, s, e;
        long long ans = 0, run = 0;
        for (auto it : transactions)
        {
            if (it[0] > it[1])
                s.push_back(it);
            else if (it[0] < it[1])
                g.push_back(it);
            else
                e.push_back(it);
        }
        sort(g.begin(), g.end(), compare);
        sort(e.begin(), e.end(), compare1);
        sort(s.begin(), s.end(), compare1);
        for (auto it : s)
        {
            ans = max(ans, run += it[0]);
            run -= it[1];
        }
        if (!e.empty())
            ans = max(ans, run + e[0][0]);
        if (!g.empty())
            ans = max(ans, run + g[0][0]);
        return ans;
    }
};

class Solution
{
    bool isPalindrome(string &s)
    {
        int l = 0, r = s.size() - 1;
        while (l <= r)
        {
            if (s[l++] != s[r--])
                return 0;
        }
        return 1;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++)
        {
            string s = words[i];
            reverse(s.begin(), s.end());
            map[s] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                string pre = words[i].substr(0, j), suf = words[i].substr(j);
                if (map.count(pre) && isPalindrome(suf) && map[pre] != i)
                    ans.push_back({i, map[pre]});
                if (!pre.empty() && map.count(suf) && isPalindrome(pre) && map[suf] != i)
                    ans.push_back({map[suf], i});
            }
        }
        return ans;
    }
};
class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vector<string>> map;
        for (auto it : paths)
        {
            string pre = "";
            int i = 0;
            while (it[i] != ' ')
                pre.push_back(it[i++]);
            i++;
            while (i < it.size())
            {
                int x = it.find('(', i), y = it.find(')', i);
                string filName = it.substr(i, x - i), data = it.substr(x + 1, y - x - 1);
                map[data].push_back(pre + "/" + filName);
                i = y + 2;
            }
        }
        vector<vector<string>> ans;
        for (auto it : map)
            if (it.second.size() > 1)
                ans.push_back(it.second);
        return ans;
    }
};
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] < 1)
                nums[i] = nums.size() + 1;

        for (int i = 0; i < nums.size(); i++)
            if (abs(nums[i]) <= nums.size() && nums[nums[i] - 1] > 0)
                nums[nums[i] - 1] *= -1;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                return i + 1;
        return nums.size() + 1;
    }
};
struct Trie
{
    int val[26] = {0};
    Trie *next[26] = {NULL};
};

class MapSum
{
    Trie *head;
    unordered_map<string, int> map;

public:
    MapSum()
    {
        head = new Trie();
    }

    void insert(string key, int val)
    {
        Trie *node = head;
        bool flag = map.find(key) != map.end();
        for (char t : key)
        {
            if (node->next[t - 'a'] == NULL)
            {
                node->next[t - 'a'] = new Trie();
            }
            if (flag)
                node->val[t - 'a'] -= map[key] + val;
            else
                node->val[t - 'a'] += val;
            node = node->next[t - 'a'];
        }
        map[key] = val;
    }

    int sum(string prefix)
    {
        Trie *node = head;
        int sum = 0;
        for (char a : prefix)
        {
            sum = node->val[a - 'a'];
            node = node->next[a - 'a'];
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

class MyCircularQueue
{
    vector<int> arr;
    int front, cnt, size;

public:
    MyCircularQueue(int k)
    {
        arr.resize(k);
        front = 0;
        cnt = 0;
        size = k;
    }

    bool enQueue(int value)
    {
        if (isFull)
            return false;
        arr[(front + cnt) % size] = value;
        cnt++;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % size;
        cnt--;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return arr[(front + cnt - 1) % size];
    }

    bool isEmpty()
    {
        cnt == 0;
    }

    bool isFull()
    {
        return cnt == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

class Solution
{
    int find_parent(vector<int> &parent, int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find_parent(parent, parent[a]);
    }
    void insert(vector<int> &rank, vector<int> &parent, int a, int b)
    {
        int p_a = find_parent(parent, a), p_b = find_parent(parent, b);
        if (rank[p_a] > rank[p_b])
            parent[p_b] = p_a;
        else if (rank[p_a] < rank[p_b])
            parent[p_a] = p_b;
        else
            parent[p_a] = p_b, rank[p_b]++;
    }

public:
    bool equationsPossible(vector<string> &equations)
    {
        vector<int> parent(26), rank(26, 0);
        iota(parent.begin(), parent.end(), 0);
        for (auto it : equations)
            if (it[1] == '=')
                insert(rank, parent, it[0] - 'a', it[3] - 'a');
        for (auto it : equations)
            if (it[1] == '!' && find_parent(parent, it[0] - 'a') == find_parent(parent, it[3] - 'a'))
                return false;

        return true;
    }
};
int main()
{

    vector<int> v = {4, 2, 0, 3, 2, 5};
    cout << trap(v);
    return 0;
}