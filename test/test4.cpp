#include "bits/stdc++.h"
using namespace std;
// int MaxPowerof2(int n)
// {
//     int x = 0;
//     while ((x << 1) <= n)
//         x++;
//     return x;
// }
// int NumberOfSetbits(int n)
// {
//     if (n == 0)
//         return 0;
//     int x = MaxPowerof2(n);
//     int bU2Rx = x * (1 << (x - 1)); // bU2Rx is equal to the number of setbits upto 2 raise to x-1;

//     int msbFrom2RxToN = (n - (1 << x) + 1); // its equal to the number of msb setbits from 2^(x-1) to n;
//     int rest = n - (1 << x);
//     int ans = bU2Rx + msbFrom2RxToN + NumberOfSetbits(rest);
//     return ans;
// }
// int prec(char a)
// {
//     if (a == '^')
//         return 3;
//     else if (a == '/' || a == '*')
//         return 2;
//     else if (a == '+' || a == '-')
//         return 1;
//     else
//         return -1;
// }
// string infixToPostfix(string s)
// {
//     string res;
//     stack<char> st;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
//         {
//             res += s[i];
//         }
//         else
//         {

//             if (prec(s[i]) <= prec(st.top()))
//             {
//                 while (prec(s[i]) <= prec(st.top()) && !st.empty())
//                 {
//                     res += to_string(st.top());
//                     st.pop();
//                 }
//             }
//             st.push(s[i]);
//         }
//     }
//     while (!st.empty())
//     {
//         res += st.top();
//         st.pop();
//     }
//     return res;
// }
// // GFG QUESTION LINK-> https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1/?company[]=Google&company[]=Google&problemStatus=unsolved&page=3&query=company[]GoogleproblemStatusunsolvedpage3company[]Google#
// // Given a array of N strings, find the longest common prefix among all strings present in the array.
// string longestCommonPrefix(string arr[], int N)
// {
//     bool flag = true;
//     int count = 0;
//     for (int i = 0; i < 1000; i++)
//     {
//         if (!flag)
//             break;
//         for (int j = 0; j < N; j++)
//         {
//             if (arr[j][i] != arr[0][i])
//             {
//                 flag = false;
//                 break;
//             }
//             else if (j == (N - 1))
//             {
//                 count += 1;
//             }
//         }
//     }
//     if (count == 0)
//         return "-1";
//     else
//         return arr[0].substr(0, count);
// }
// bool isValid(string s)
// {
//     if (s.length() % 2 != 0)
//         return false;
//     stack<char> st;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '[' || s[i] == '(' || s[i] == '{')
//             st.push(s[i]);
//         else if (((st.top() == '{' && s[i] == '}') || (st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']')) && !st.empty())
//         {
//             st.pop();
//             int n = st.size();
//             continue;
//         }
//         else
//             return false;
//     }
//     if (st.empty())
//         return true;
//     return false;
// }
// bool isVal(char a)
// {
//     if (a <= '9' && a >= '0')
//         return true;
//     return false;
// }
// int calculate(string s)
// {
//     int currSum = 0, sign = 1;
//     stack<int> st;
//     for (int i = 0; i < s.length(); i++)
//     {
//         char ch = s[i];
//         if (isVal(ch))
//         {
//             int val = 0;
//             while (i < s.length() && isVal(s[i]))
//             {
//                 val = val * 10 + (s[i] - '0');
//                 i++;
//             }
//             i--;
//             val *= sign;
//             currSum += val;
//             sign = +1;
//         }
//         else if (ch == '(')
//         {
//             st.push(currSum);
//             st.push(sign);
//             currSum = 0;
//             sign = +1;
//         }
//         else if (ch == ')')
//         {
//             currSum *= st.top();
//             st.pop();
//             currSum += st.top();
//             st.pop();
//         }
//         else if (ch == '-')
//         {
//             sign *= -1;
//         }
//     }
//     return currSum;
// }
// vector<int> canSeePersonsCount(vector<int> &heights)
// {
//     int n = heights.size();
//     vector<int> result(n, 0);
//     stack<int> st;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         while (st.size() && st.top() < heights[i])
//         {
//             st.pop();
//             result[i]++;
//         }
//         if (st.size())
//             result[i]++;
//         st.push(heights[i]);
//     }
//     return result;
// }

string decodeString(string s)
{
    string ans = "";
    int num = 0;
    stack<pair<string, int>> stk; //
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
            num = (num * 10) + (s[i] - 48); //S
        else if (isalpha(s[i]))             //IF g
            ans += s[i];
        else if (s[i] == '[') //The
        {
            stk.push({ans, num});
            ans = ""; // making
            num = 0;
        }
        else if (s[i] == ']') //
        {
            string tmp = ans;
            for (int i = 1; i < stk.top().second; i++)
                tmp += ans;
            ans = stk.top().first + tmp;
            stk.pop();
        }
    }

    return ans;
}
int partition(vector<int> arr, int sum)
{
    int n = arr.size();
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 1;
            else
            {
                if (dp[i - 1][j])
                    dp[i][j] = 1;
                else
                {
                    int val = arr[i - 1];
                    if (j >= val && dp[i - 1][j - val])
                        dp[i][j] = 1;
                }
            }
        }
    }
    return dp[sum][n];
}
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int low = i + 1, high = nums.size() - 1, sum = 0 - nums[i];
            while (low < high)
            {
                if (nums[low] + nums[high] == sum)
                {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (high > low && nums[high] == nums[high - 1])
                        high--;
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] > sum)
                    high--;
                else
                    low++;
            }
        }
    }
    return ans;
}
vector<vector<int>> threeSum(vector<int> &nums, int target = 0)
{
    if (nums.size() == 0 || (nums.size() == 1 && nums[0] == 0) || nums[0] == 1)
        return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        unordered_set<int> set;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (set.find(target - (nums[j] + nums[i])) != set.end())
            {
                vector<int> temp = {nums[i], nums[j], target - nums[j] - nums[i]};
                ans.push_back(temp);
            }
            else
                set.insert(nums[j]);
            while (j < nums.size() && nums[j] == nums[j + 1])
                j++;
        }
        while (i < nums.size() && nums[i] == nums[i + 1])
            i++;
    }

    return ans;
}
int search(vector<int> &nums, int target)
{
    int last = nums.size(), start = 0;
    while (start <= last)
    {
        int mid = start + (last - start) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            start = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}
vector<int> sortedSquares(vector<int> &nums)
{
    int pos_ptr = 0, neg_ptr, n = nums.size();
    while (pos_ptr < n && nums[pos_ptr] < 0)
        pos_ptr++;
    neg_ptr = pos_ptr - 1;
    vector<int> ans;
    while (neg_ptr >= 0 && pos_ptr < n)
    {
        if (nums[neg_ptr] * nums[neg_ptr] < nums[pos_ptr] * nums[pos_ptr])
        {
            ans.push_back(nums[neg_ptr] * nums[neg_ptr]);
            neg_ptr--;
        }
        else
        {
            ans.push_back(nums[pos_ptr] * nums[pos_ptr]);
            pos_ptr++;
        }
    }
    while (neg_ptr >= 0)
    {
        ans.push_back(nums[neg_ptr] * nums[neg_ptr]);
        neg_ptr--;
    }
    while (pos_ptr < n)
    {
        ans.push_back(nums[pos_ptr] * nums[pos_ptr]);
        pos_ptr++;
    }
    return ans;
}
vector<int> sortedSquares2(vector<int> &nums)
{
    int n = nums.size(), left = 0, right = n - 1;
    vector<int> ans(n, 0);
    int square;
    for (int i = n - 1; i >= 0; i--)
    {
        if (abs(nums[left]) > abs(nums[right]))
        {
            square = nums[left];
            left++;
        }
        else
        {
            square = nums[right];
            right--;
        }
        ans[i] = square * square;
    }
    return ans;
}
int main()
{
    //     int n = 17;
    //     // cout<<NumberOfSetbits(n);

    //     string arr[] = {"geeksforgeeks", "geeks", "geek",
    //                     "geezer"};
    //     string ans = longestCommonPrefix(arr, 4);
    //     cout << ans;
    // vector<vector<int>> mat;
    //  int a=mat.size();
    // int a=6;
    // cout<<8+(a++)<<"\t"<<a;
    // vector<int> arr = {10, 6, 8, 5, 11, 9};
    // vector<int> ans = canSeePersonsCount(arr);
    // for (auto s : ans)
    //     cout << s << " ";
    // string str = "3[a]2[bc]";
    // string ans = decodeString(str);
    // cout << ans;
    vector<int> as = {-4, -1, 0, 3, 10};
    vector<int> ans = sortedSquares(as);
    for (auto a : ans)
        cout << a << " ";
    return 0;
}