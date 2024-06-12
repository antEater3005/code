// In this code the output is generated in a specific space. 
// The "cout.width(no_of_spaces_to_be_printed)".
#include "bits/stdc++.h"
using namespace std;
int main()
{
    int items[4] = {10, 8, 12, 15};
    int cost[4] = {75, 100, 60, 99};
    cout.width(5);
    cout << "ITEMS";
    cout.width(8);
    cout << "COST";
    cout.width(15);
    cout << "TOTAL VALUE" << endl;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        cout.width(5);
        cout << items[i];
        cout.width(8);
        cout << cost[i];
        cout.width(15);
        int val = items[i] * cost[i];
        cout << val << endl;
        sum += val;
    }
    cout << "Grand Total=";
    cout.width(2);
    cout << sum << endl;
    return 0;
}