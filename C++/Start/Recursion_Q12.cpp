//MOVE ALL X TO END OF THE STRING.
#include <iostream>
using namespace std;
string endX(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = endX(s.substr(1));
    if (ch == 'x')
    {
        return ans + ch;
    }
    else
    {
        return ch + ans;
    }
}
int main()
{
    string s1;
    cin >> s1;
    cout << endX(s1);

    return 0;
}