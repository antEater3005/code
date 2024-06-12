#include <bits/stdc++.h>
using namespace std;
void rev(string &s)
{
    int i = 0, j = 0;
    while (j <= s.size())
    {
        if (j == s.size() || s[j] == ' ')
        {
            if ((j - i) & 1)
                reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        j++;
    }
}
int main()
{

    string x = "I Lover Your";
    rev(x);
    cout << x;
    return 0;
}