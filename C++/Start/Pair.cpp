// Pair is an STL container which allow us to store a pair of values.
#include <iostream>
using namespace std;
int main()
{
    pair<int, char> p; // In pair the data type can be different.
    p.first = 4;
    p.second = 'd';
    cout<<p.first<<","<<p.second;
    return 0;
}