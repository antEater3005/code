// Vector are dynamic arrays.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> r;
    r.push_back(4); // name of the vector .push_back(element u want to add);
    r.push_back(5);
    r.push_back(2);
    r.push_back(7);
    r.push_back(8);
    // Following are the ways by which you can take output from the vector.
    // 1.
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << " ";
    }
    cout << endl; //output 45278
    // 2.
    vector<int>::iterator it; //Here the iterator is a pointer;
    for (it = r.begin(); it != r.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    // 3.
    r.pop_back(); //THE POP BACK FUNCTION  used To take out the last element from a vector.
    // (nameofthevector).pop_back();
    for (auto element : r)
    {
        cout << element << " ";
    } //output 4527
    cout << endl;

    vector<int> r2(3, 50);

    vector<int>::iterator a;
    for (a = r2.begin(); a != r2.end(); a++)
    {
        cout << *a << " ";
    }
    cout << endl;
    //SWAP function is used to swap the elements of two vectors.
    swap(r, r2);
    for (auto element : r)
    {
        cout << element << " ";
    } // Output is 50 50 50.

    cout << endl;
    for (auto element : r2)
    {
        cout << element << " ";
    }
    cout << endl; //Output is  4 5 2 7.
    // SORT: its an inbuilt sorting algorithm.
    sort(r2.begin(), r2.end());
    for (auto element : r2)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
