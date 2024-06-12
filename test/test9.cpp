#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     bool isPossible(int n, long long averageTime, vector<int> Batteries)
//     {
//         long long duration = 0;
//         for (int ele : Batteries)
//         {
//             if (ele <= averageTime)
//                 duration += ele;
//             else
//                 duration += averageTime;
//         }
//         return duration >= averageTime * n;
//     }
//     long long maxRunTime(int n, vector<int> &batteries)
//     {
//         long long sum = 0, startTime = 0, endTime, averageTime;
//         for (int ele : batteries)
//             sum += ele;
//         endTime = sum;
//         while (startTime <= endTime)
//         {
//             averageTime = startTime + (endTime - startTime) / 2;
//             if (isPossible(n, averageTime, batteries))
//                 startTime = averageTime + 1;
//             else
//                 endTime = averageTime - 1;
//         }
//         return endTime;
//     }
// };

// class Solution3
// {
// public:
//     int solve(int N, string S, int C[])
//     {
//         int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
//         for (int i = 0; i < N; i++)
//         {
//             if (S[i] == '0')
//                 a += C[i];
//             else
//                 b += C[i];
//             if (i % 2 == 0)
//             {
//                 string a = S.substr(i, 2);
//                 if (a == "00")
//                     c += C[i] + C[i + 1];
//                 else if (a == "11")
//                     d += C[i] + C[i + 1];
//                 if (a == "01")
//                     e += C[i];
//                 else
//                     f += C[i + 1];
//                 if (a == "10")
//                     g += C[i + 1];
//                 else
//                     h += C[i];
//             }
//         }
//         return min(a, min(b, min(c, min(d, min(e, min(f, min(g, h)))))));
//     }
// };

// int kar98(vector<int> piles, int s, int e, int a, vector<vector<int>> &memo)
// {
//     if (s > e)
//         return 0;
//     if (memo[s][e] != -1)
//         return memo[s][e];

//     int left = a + piles[s] + kar98(piles, s + 2, e, a, memo);
//     int right = a + piles[s] + kar98(piles, s + 1, e - 1, a, memo);
//     int left2 = a + piles[e] + kar98(piles, s, e - 2, a, memo);
//     int right2 = a + piles[e] + kar98(piles, s + 1, e - 1, a, memo);
//     return memo[s][e] = max(a, max(left, max(right, max(left2, right2))));
// }
// bool stoneGame(vector<int> &piles)
// {

//     int alice = 0, bob = 0, end = piles.size() - 1, start = 0;

//     vector<vector<int>> memo(end, vector<int>(piles.size(), -1));
//     kar98(piles, start, end, alice, memo);
//     bob = accumulate(piles.begin(), piles.end(), 0) - alice;

//     return alice > bob - alice ? true : false;
// }

// class Solution
// {
// public:
//     int minimumCost(vector<int> &cost)
//     {
//         sort(cost.begin(), cost.end());
//         int a = 0;

//         for (int cnt = 0, i = cost.size(); i > 0; i--)
//         {
//             a += cost[i];
//             if (cnt == 2)
//             {
//                 cnt = 0;
//                 continue;
//             }
//         }

//         return a;
//     }
// };

// class Solution
// {
// public:
//     int countElements(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int max = nums[nums.size() - 1], min = nums[0], ans = 0;
//         for (int i = 1; i < nums.size() - 1; i++)
//         {
//             if (nums[i] > min && nums[i] < max)
//                 ans++;
//         }
//         ans++;
//     }
// };
// class Solution
// {
// public:
//     vector<int> rearrangeArray(vector<int> &nums)
//     {
//         vector<int> ans;
//         int p = 0, n = 0;
//         while (p < nums.size() || n < nums.size())
//         {
//             while (p < nums.size() && nums[p] > 0)
//                 p++;
//             while (n < nums.size() && nums[n] > 0)
//                 n++;
//             if (n < nums.size() && p < nums.size())
//             {
//                 ans.push_back(nums[p]);
//                 ans.push_back(nums[n]);
//             }
//             n++;
//             p++;
//         }
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     vector<int> findLonely(vector<int> &nums)
//     {
//         unordered_map<int, int> map;
//         vector<int> ans;
//         for (auto a : nums)
//             map[a]++;
//         for (auto n : map)
//         {
//             cout << n.first << " ";
//             if (n.second == 0 && map[n.first + 1] == 0 && map[n.first - 1] == 0)
//                 ans.push_back(n.first);
//         }
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     vector<int> findLonely(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int a = nums[0];
//         for (int i = 0; i < nums.size() - 1; i++)
//         {

//             if (a == nums[i + 1] || a == nums[i + 1] - 1)
//             {
//                 a = nums[i];
//                 nums.erase(nums.begin() + i);
//             }
//         }
//         if (a == nums[nums.size() - 1] || a == nums[nums.size() - 1] - 1)
//         {
//             nums.pop_back();
//         }
//         return nums;
//     }
// };
// vector<int> findLonely(vector<int> &nums)
// {
//     nums.push_back(-10);
//     nums.push_back(10e6 + 10);
//     sort(nums.begin(), nums.end());
//     vector<int> ans;
//     for (int i = 1; i < nums.size() - 1; i++)
//         if (abs(nums[i + 1] - nums[i]) > 1 && abs(nums[i - 1] - nums[i]) > 1)
//             ans.push_back(nums[i]);
//     return ans;
// }
// vector<int> findLonely(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     for (int a : nums)
//         cout << a << " ";
//     int a = nums[nums.size() - 1];
//     bool flag = true;
//     for (int i = nums.size() - 2; i >= 0; i--)
//     {
//         int t = nums[i];
//         if (a == nums[i] || a == nums[i] + 1)
//         {
//             if (nums[i + 1] == a && flag)
//                 nums.erase(nums.begin() + i + 1);
//             a = nums[i];
//             nums.erase(nums.begin() + i);
//             flag = false;
//         }
//         else
//         {
//             a = nums[i];
//             flag = true;
//             cout << "no";
//         }
//     }
//     return nums;
// }

// vector<int> sequentialDigits(int low, int high)
// {
//     vector<int> ans;
//     for (int i = 1; i <= 9; i++)
//     {
//         int temp = 0;
//         for (int j = i; j<= 9; j++)
//         {
//             temp = temp * 10 + j;
//             if (temp <= high && temp >= low)
//                 ans.push_back(temp);
//             if (temp > high)
//                 j = 10;
//         }
//     }
//     return ans;
// }

// class Solution
// {
// public:
//     string capitalizeTitle(string title)
//     {
//         int itr = 0;
//         bool flag = true;
//         while (itr < title.length())
//         {
//             if (title[itr] == ' ')
//             {
//                 flag = true;
//                 itr++;
//                 continue;
//             }
//             if (flag)
//             {
//                 if (  itr + 1 == title.length() || title[itr + 1] == ' ')
//                     title[itr] = tolower(title[itr]);
//                 else if (itr + 2 == title.length() || title[itr + 2] == ' ')
//                 {
//                     title[itr] = tolower(title[itr]);
//                     title[itr + 1] = tolower(title[itr + 1]);
//                     itr++;
//                 }
//                 else
//                     title[itr] = toupper(title[itr]);
//                 flag = false;
//             }
//             else
//                 title[itr] = tolower(title[itr]);
//             itr++;
//         }
//         return title;
//     }
// };

string capitalizeTitle(string title)
{
    int itr = 0;
    bool flag = true;
    while (itr < title.length())
    {
        if (title[itr] == ' ')
        {
            flag = true;
            itr++;
            continue;
        }
        if (flag)
        {
            if (itr + 1 == title.length() || title[itr + 1] == ' ')
                title[itr] = tolower(title[itr]);
            else if (itr + 2 == title.length() || title[itr + 2] == ' ')
            {
                title[itr] = tolower(title[itr]);
                title[itr + 1] = tolower(title[itr + 1]);
                itr++;
            }
            else
                title[itr] = toupper(title[itr]);
            flag = false;
        }
        else
            title[itr] = tolower(title[itr]);
        itr++;
    }
    return title;
}

bool isPalindrome(string s)
{
    for (int i = 0; i < s.length();)
    {
        if (isalnum(s[i]))
            s[i++] = tolower(s[i]);
        else
            s.erase(i, 1);
    }
    cout << s << "\n";
    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - i - 1])
            return false;
    return true;
}
bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i++ < j--)
    {
        while (!isalnum(s[i]))
            i++;
        while (!isalnum(s[j]))
            j--;
        if (tolower(s[i]) != towlower(s[j]))
            return false;
    }
    return true;
}

int main()
{
    string a = "A man a plan a canal panama";
    cout << isPalindrome(a);
    return 0;
}