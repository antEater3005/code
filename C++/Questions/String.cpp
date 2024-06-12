#include "bits/stdc++.h"
using namespace std;
bool isIsogram(string s)
{
    priority_queue<char> q;
    for (auto a : s)
        q.push(a);
    char a = q.top();
    q.pop();
    while (!q.empty())
    {
        if (q.top() == a)
        {
            return false;
        }
        a = q.top();
        q.pop();
    }
    return true;
}
// Isogram means the string does not have any repeating letter.
bool isIsogram2(string s)
{
    int arr[26] = {};
    for (int i = 0; i < s.length(); i++)
    {
        if (arr[(int)(s[i]) - 97] == 1)
        {
            return false;
        }
        arr[(int)(s[i]) - 97] = 1;
    }
    return true;
}
// Pangram means a string have all the letters of alphabet.
bool isPangram(string &s)
{

    int arr[26] = {0};
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (arr[s[i] - 'a'] == 0)
                n++;
            arr[s[i] - 'a'] = 1;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (arr[s[i] - 'A'] == 0)
                n++;
            arr[s[i] - 'A'] = 1;
        }
        if (n == 26)
            return true;
    }

    return false;
}
//Function to count the number of substrings that start and end with 1.
long binarySubstring(int n, string a)
{

    int count = 0;
    for (auto s : a)
        if (s == '1')
            count++;
    return (count * (count - 1) / 2);
}

int main()
{
    string s = "Bawds jog, fawdddalick quartz, vex nymph";
    if (isPangram(s))
    {
        cout << "True";
    }
    else
        cout << "False";

    return 0;
}