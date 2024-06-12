#include <iostream>
using namespace std;
void substr(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    substr(ros, ans);
    substr(ros, ans + ch);
    substr(ros, ans + to_string(code));
}
int main()
{
    substr("AB", "");
    cout << endl;
    return 0;
}