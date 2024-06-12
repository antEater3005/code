// Strings are a type of dynamic character array.
// No need to define the size of a string as in case of character array.
// The size of a string can be changed.
// String has a special terminating caharacter '\0', Which denote the end of string.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "abc";
    string s2 = "adsbc";
    if (s1.compare(s2))
        cout << "string is equal";
    else
        cout << "strings are not equal";
    //string abc = "dsfdfsgsdgshfkshgyfhsjgf";
    //abc.clear();
    //cout << abc;

    // string s1 = "Fam";
    // string s2 = "ily";
    //s1.append(s2);
    //cout << s1+s2;
    // cout << s1[2];
    return 0;
}