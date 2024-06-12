#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string str = "JHSDGSHADJHSGHJAHD";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    cout << str;
    return 0;
}