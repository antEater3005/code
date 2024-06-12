#include <bits/stdc++.h>
using namespace std;
// class Solution1
// {
// public:
//     vector<int> plusOne(vector<int> &digits)
//     {
//         int carry = 1;
//         for (int i = digits.size() - 1; i >= 0; i--)
//         {
//             carry += digits[i];
//             digits[i] = carry % 10;
//             carry /= 10;
//         }
//         if (carry)
//         {
//             digits.push_back(carry);
//             for (int i = digits.size() - 1; i >= 1; i--)
//             {
//                 swap(digits[i], digits[i - 1]);
//             }
//         }
//         return digits;
//     }
// };

// class Solution
// {
// public:
//     string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//     vector<string> letterCombinations(string digits)
//     {
//         vector<string> result;
//         int n = digits.length();
//         string ans = "";
//         if (n >= 1)
//         {
//             string a = map[digits[0] - '0'];
//             for (int i = 0; i < a.length(); i++)
//             {
//                 ans += a[i];
//                 if (n >= 2)
//                 {
//                     string b = map[digits[1] - '0'];
//                     for (int k = 0; k < b.length(); k++)
//                     {
//                         ans += b[k];
//                         if (n >= 3)
//                         {

//                             string c = map[digits[2] - '0'];
//                             for (int l = 0; l < c.length(); l++)
//                             {
//                                 ans += c[l];
//                                 if (n == 4)
//                                 {
//                                     string d = map[digits[3] - '0'];
//                                     for (int m = 0; m < d.length(); m++)
//                                     {
//                                         ans += d[m];
//                                         result.push_back(ans);
//                                         ans.pop_back();
//                                     }
//                                 }
//                                 else
//                                     result.push_back(ans);
//                                 ans.pop_back();
//                             }
//                         }
//                         else
//                             result.push_back(ans);
//                         ans.pop_back();
//                     }
//                 }
//                 else
//                     result.push_back(ans);
//                 ans.pop_back();
//             }
//         }
//         return result;
//     }
// };

// void dfs(int node, int destination, unordered_map<int, vector<pair<int, int>>> paths, vector<bool> visited, int weight, int &minWeight, int &ans)
// {
//     vector<pair<int, int>> next = paths[node];
//     visited[node] = true;

//     for (auto j : next)
//     {
//         if (j.first == destination)
//         {
//             if (weight < minWeight)
//             {
//                 ans = 1;
//                 minWeight = weight;
//             }
//             else if (minWeight == weight)
//                 ans += 1;
//         }
//         if (!visited[j.first] && j.first < destination)
//         {
//             dfs(j.first, destination, paths, visited, weight + j.second, minWeight, ans);
//         }
//     }
// }
// int countPaths(int n, vector<vector<int>> &roads)
// {
//     unordered_map<int, vector<pair<int, int>>> paths; //unordered_map<from, vector<pair<to, time>>>
//     for (int i = 0; i < n; i++)
//     {
//         if (roads[i][0] != n - 1)
//             paths[roads[i][0]].push_back({roads[i][1], roads[i][2]});
//         if (roads[i][1] != n - 1)
//             paths[roads[i][1]].push_back({roads[i][0], roads[i][2]});
//     }
//     int ans = 0, minwight = INT_MIN;
//     vector<bool> visited(n, false);
//     dfs(0, n - 1, paths, visited, 0, minwight, ans);
//     return ans;
// }
// int square(int n)
// {
//     int a = 0;
//     while (n)
//     {
//         a += (n % 10) * (n % 10);
//         n /= 10;
//     }
//     return a;
// }
// // normal method
// bool isHappy(int n)
// {
//     set<int> seen;
//     while (n != 1 && seen.count(n) == 0)
//     {
//         seen.insert(n);
//         n = square(n);
//         cout << n << "->";
//     }
//     return n == 1;
// }
// // using Floyd  Floyd's Cycle-Finding Algorithm
// bool isHappy(int n)
// {
//     int slow_runner = n;
//     int fast_runner = square(n);
//     while (fast_runner != 1 && fast_runner != slow_runner)
//     {
//         slow_runner = square(slow_runner);
//         fast_runner = square(square(fast_runner));
//     }
//     return fast_runner == 1;
// }
// bool isUgly(int n)
// {
//     if (n > 0)
//     {
//         for (int i = 2; i < 6; i++)
//             while (n % i == 0)
//                 n = n / i;
//     }
//     return n == 1;
// }
// int getMaximumConsecutive(vector<int> &coins)
// {
//     sort(coins.begin(), coins.end());
//     for (int i = 1; i < coins.size(); i++)
//     {
//         if (coins[i] <= coins[i - 1] + 1)
//         {
//             coins[i] += coins[i - 1];
//         }
//         else
//             return coins[i - 1]+1;
//     }
//     return coins[0]==1?coins[coins.size()-1]+1:1;
// }

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
int main()
{
    string a = "A man, a plan, a canal: Panama";
    cout << isPalindrome(a);
    return 0;
}