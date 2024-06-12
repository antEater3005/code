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

// string decodeString(string s)
// {
//     stack<pair<string, int>> st;

//     string ans = "";
//     int a = 0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (isdigit(s[i]))
//         {
//             a =( a * 10) + (s[i] - 48);
//         }
//         else if (isalpha(s[i]))
//         {
//             ans += s[i];
//         }
//         else if (s[i] == '[')
//         {
//             st.push({ans, a});
//             ans = "";
//             a = 0;
//         }
//         else if (s[i] == ']')
//         {
//             string temp = ans;
//             for (int j = 1; j < st.top().second ; j++)
//                 temp += ans;
//             ans = st.top().first + temp;
//             st.pop();
//         }
//     }
//     return ans;
// }
// // kadane's algorithm to find maximum sum of subarray
// int Kadane(int arr[], int n)
// {
//     int curr_sum = 0, max_sum = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//        if(curr_sum<=0)
//            curr_sum = arr[i];
//        else
//            curr_sum += arr[i];
//        max_sum = max(max_sum, curr_sum);
//     }
//     return max_sum;
// }
// // function to check the first repeating number in array of size n having elemets ranging from 1 to n;
// int first_repeating_number(int arr[], int n)
// {
//     unordered_set<int> set; // it stores the occurrences of each number: set stores unique values
//     for (int i = 0; i < n; i++)
//     {
//         if (set.find(arr[i]) != set.end()) // it find wheather the element is present or not;
//             return arr[i];
//         set.insert(arr[i]);
//     }
//     return -1;
// }
// // The above solution has linear time and space complexity:The following solution is optimized to make the space complexity O(1);
// int first_repeating_number2(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[abs(arr[i]) - 1] < 0)
//             return arr[i];
//         arr[abs(arr[i]) - 1] *= -1;
//     }
//     return -1;
// }
// //Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// string reverseWords(string s)
// { string ans="";
//     int i=0,j=0;
//     while(j<s.length())
//     {
//         string str = "";
//         while (s[j] != ' '&&j<s.length())
//         {
//            str+=s[j];
//            j++;
//         }
//         reverse(str.begin(),str.end());
//         ans+=(str+' ');
//         j++;
//         i = j;
//     }
//     ans.pop_back();
//     return ans;
// }

// reverse an integer
int reverse_int(int n)
{
    int new_number = 0;
    while (n)
    {
        new_number = new_number * 10 + n % 10;
        n /= 10;
    }
    return new_number;
}
string intToRoman(int num)
{
    vector<pair<int, string>> roman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    int i = 0;
    string ans = "";
    while (num)
    {
        if (int a = num / roman[i].first)
        {
            while (a--)
                ans += roman[i].second;
            num = num % roman[i].first;
        }
        i++;
    }
    return ans;
}
int romanToInt(string s)
{
    vector<pair<int, string>> roman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    int ans = 0, idx = 0, i = 0;
    while (i < roman.size())
    {
        if (idx == s.size())
            return ans;
        int size = roman[i].second.length();
        if (s.substr(idx, size) == roman[i].second)
        {
            ans += roman[i].first;
            idx += size;
            i--;
        }
        i++;
    }
    return ans;
}
int romanToInt2(string s)
{
    map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (roman[s[i]] < roman[s[i]])
            ans -= roman[s[i]];
        else
            ans += roman[s[i]];
    }
    return ans;
}
int romanToInt3(string s)
{
    int ans = 0, num;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        switch (s[i])
        {
        case 'I':
            num = 1;
            break;
        case 'V':
            num = 5;
            break;
        case 'X':
            num = 10;
            break;
        case 'L':
            num = 50;
            break;
        case 'C':
            num = 100;
            break;
        case 'D':
            num = 500;
            break;
        case 'M':
            num = 1000;
            break;
        }
        if (num * 4 < ans)
            ans -= num;
        else
            ans += num;
    }
    return ans;
}
int stairs(int n)
{
    if (n <= 1)
        return 1;
    return stairs(n - 1) + stairs(n - 2);
}
// Stairs problem using Memoization
class solution
{
    // private:
    map<int, int> memo;

public:
    int stairs(int n)
    {
        if (n <= 1)
            return 1;
        if (memo.find(n) != memo.end())
            return memo[n];
        int ans = stairs(n - 1) + stairs(n - 2);
        memo.insert({n, ans});
        return ans;
    }
};
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans = {-1, -1};
    int start = 0, end = nums.size() - 1;
    while (start != end + 1)
    {
        int mid = start + (end - start) / 2;
        cout << mid << "\n";
        if (nums[mid] == target)
        {
            ans[0] = mid;
            end = mid - 1;
        }
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    start = 0, end = nums.size() - 1;
    while (start != end + 1)
    {
        int mid = start + (end - start) / 2;
        cout << mid << "\n";
        if (nums[mid] == target)
        {
            ans[1] = mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
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
    //  string  s = "God Ding";
    // string ans= reverseWords(s);
    //  cout<<ans;
    // int a = 120;
    // cout << intToRoman(a);
    // string ans = "MCMXCIV";
    // cout << romanToInt3(ans); // output:1994
    //  cout<<stairs(5);
    vector<int> nums = {5, 5, 5, 5, 5, 5, 7, 7, 8, 8, 10, 10};
    vector<int> ans = searchRange(nums, 5);
    cout << ans[0] << " " << ans[1];
    return 0;
}