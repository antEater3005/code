
// Given a number (as string) and two integers a and b, divide the string in two non-empty parts such that the first part is divisible by a and the second part is divisible by b. In case multiple answers exist, return the string such that the first non-empty part has minimum length.
// Link:https://practice.geeksforgeeks.org/problems/partition-a-number-into-two-divisible-parts3605/1#
#include <bits/stdc++.h>
using namespace std;
string stringPartition(string S, int a, int b)
{
    int left = S[0] - '0';
    for (int i = 1; i < S.length(); i++)
    {

        if (left % a == 0)
        {
            int right = 0, j = i;
            while (j < S.length())
            {
                right = right * 10 + S[j] - '0';
                j++;
            }
            if (right % b == 0)
                return S.substr(0, i) + " " + S.substr(i, j);
        }
        left = left * 10 + S[i] - '0';
    }
    return "-1";
}
int main()
{
    string s = "5010";
    cout << stringPartition(s, 10, 10);

    return 0;
}