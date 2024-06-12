#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s = "dghaggasjhdh";
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;
    string str = "GSHDAGDHAGHDAH";
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << endl;
    return 0;
}