#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// day3
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{

    unordered_map<int, int> set1;
    for (int a : nums1)
        for (int s : nums2)
        {
            set1[a + s]++;
        }
    int ans = 0;
    for (int a : nums3)
        for (int s : nums4)
        {
            ans += set1[(a + s) * -1];
        }

    return ans;
}
// day4
int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> firstIdx;
    int preSum = 0, maxLength = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        preSum += nums[i] == 0 ? -1 : 1;
        if (preSum == 0)
        {
            maxLength = max(maxLength, i + 1);
        }
        if (firstIdx.find(preSum) != firstIdx.end())
        {
            maxLength = max(maxLength, i - firstIdx[preSum]);
        }
        else
            firstIdx[preSum] = i;
    }
    return maxLength;
}
/**Day::5 23. Merge k Sorted Lists      https://leetcode.com/problems/merge-k-sorted-lists/ */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode *head = l1->val > l2->val ? l2 : l1;
    head->next = l1->val <= l2->val ? mergeTwoLists(l1->next, l2) : mergeTwoLists(l1, l2->next);
    return head;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    ListNode *head = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        head = mergeTwoLists(head, lists[i]);
    }
    return head;
}
/**DAY::6   80. Remove Duplicates from Sorted Array II  https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/ */
int removeDuplicates(vector<int> &nums)
{
    int k = nums.size(), i = 0;
    for (i; i < nums.size();)
    {
        int t = nums[i], counter = 0;
        while (i < nums.size() && t == nums[i])
        {
            counter++;
            if (counter > 2)
            {
                nums.erase(nums.begin() + i - 1);
                k--;
            }
            else
                i++;
        }
    }
    return k;
}
/**methode2*/
int removeDuplicates(vector<int> &nums)
{
    int change = 2, curr = 2;
    while (curr < nums.size())
    {
        if (nums[change - 2] != nums[curr])
            swap(nums[change++], nums[curr]);
        curr++;
    }
    return change;
}
/**DAY::7 */
int findPairs(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int ans = 0;
    unordered_map<int, int> ma;
    for (int a : nums)
    {
        if (k == 0 && ma[a] == 1)

            ans++;
        else if (!ma[a])
        {
            if (ma[a - k])
                ans++;
            if (ma[a + k])
                ans++;
        }

        ma[a]++;
    }
    return ans;
}
/**DAY::10 subarray sum equal k TC=O(N^2)*/
int subarraySum(vector<int> &nums, int k)
{
    int count = 0, i = 0, j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = nums[i];
        if (sum == k)
            count++;
        for (int j = i + 1; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

/**DAY::12 127. Word Ladder    https://leetcode.com/problems/word-ladder/ */

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    set<string> words; // to store words
    for (string s : wordList)
        words.insert(s);
    if (words.count(endWord) == 0) // if the wordlist doesn't contains the endword return 0;
        return 0;
    // BFS
    queue<string> q;
    int depth = 0, qSize;
    q.push(beginWord);
    while (!q.empty())
    {
        depth += 1;
        qSize = q.size();
        while (qSize--)
        {
            string curr = q.front();
            q.pop();
            for (int i = 0; i < curr.size(); i++)
            {
                char original = curr[i];
                for (char j = 'a'; j <= 'z'; j++) // check all possible words
                {
                    curr[i] = j;         // replace the character to form new possible words
                    if (curr == endWord) // here if we found the word we return
                        return depth + 1;
                    if (words.find(curr) != words.end()) // here if the word formed is present in the given wordlist, we push it into queue and erase from the list
                    {
                        q.push(curr);
                        words.erase(curr);
                    }
                    curr[i] = original; // after each process we replace the character with the original character
                }
            }
        }
    }
    return 0; // if we are here that means the word cannot be formed so we return 0;
}

int main()
{

    return 0;
}
