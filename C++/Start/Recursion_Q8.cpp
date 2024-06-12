//REVERSING A STRING USING RECURSION.
#include <iostream>
using namespace std;
void reverse(string s)
{
    if (s.length() == 0) //BASE CASE.
    {
        return;
    }
    string ros = s.substr(1);
    reverse(ros);
    cout << s[0];
}
int main()
{
    reverse("Rishitosh");
    return 0;
}