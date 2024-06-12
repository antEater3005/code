
#include "bits/stdc++.h"
using namespace std;

void count(int n)
{
    if (!n)
        return;  

    count(n - 1);
    cout << n << " ";
}
long long int fact(int n)
{
    if (!n)
        return 1;
    return n * fact(n - 1);
}
void fibbN(int n, int a, int b)
{
    if (!(n))
        return;
    cout << b << " ";
    fibbN(n - 1, b, a + b);
}
int nthFibb(int n, int &count)
{
    if (n == 0 || n == 1)
        return n;
    count++;
    return nthFibb(n - 1, count) + nthFibb(n - 2, count);
}
// fibb Iterative solution
int fibIter(int n, int &count)
{
    if (n < 2)
        return n;

    int f1 = 0, f2 = 1;
    for (int i = 2; i <= n; i++)
    {
        count++;
        int to = f1 + f2;
        f1 = f2;
        f2 = to;
    }
    return f2;
}
void num(int n){ 
    static vector<string>name={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    if(!n)
    return ;
    num(n/10);
    int a = n % 10;
    cout<<name[a]<<" ";
    // switch (a)
    // {
    // case 1:
    //     cout << "One"
    //          << " ";
    //     return;
    // case 2:
    //     cout << "Two"
    //          << " ";
    //     return;
    // case 3:
    //     cout << "Three"
    //          << " ";
    //     return;
    // case 4:
    //     cout << "Four"
    //          << " ";
    //     return;
    // case 5:
    //     cout << "Five"
    //          << " ";
    //     return;
    // case 6:
    //     cout << "Six"
    //          << " ";
    //     return;
    // case 7:
    //     cout << "Seven"
    //          << " ";
    //     return;
    // case 8:
    //     cout << "Eight"
    //          << " ";
    //     return;
    // case 9:
    //     cout << "Nine"
    //          << " ";
    //     return;
    // case 0:
    //     cout << "Zero"
    //          << " ";
    //     return;
    // default:
    //     cout << "invalid input";
    //     break;
    // }
}
int expo(int pow, int base = 2)
{
    if (!pow)
        return 1;
    return expo(pow - 1, base) * base;
}
int total=0;
int expo2(int pow,int base=2){
    if(!pow)
    return 1;
    if(pow%2==1){
        return 2*expo2(pow/2 )*expo2(pow/2);
    }
    else
    return expo2(pow/2 )*expo2(pow/2);
}
bool sorted(int arr[],int n){
    if(n==1)
        return true;
    if (arr[n - 1] < arr[n - 2])
        return false;
    return sorted(arr, n - 1);
}
void subset(vector<int> input, vector<int> output, int index)
{
    if (index >= input.size())
    {
        for (auto a : output)
            cout << a << " ";
        cout << endl;
        total++;
        return;
    }
    subset(input, output, index+1);
    output.push_back(input[index]);
    subset(input, output, index + 1);
}
int NthStair(int n)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;

    return NthStair(n - 1) + NthStair(n - 2) + NthStair(n - 3);
}
void printSubSeq(string in, string out, int idx)
{
    if (idx >= in.size())
    {
        cout << out << endl;
        return;
    }
    printSubSeq(in, out, idx + 1);
    out.push_back(in[idx]);
    printSubSeq(in, out, idx + 1);
}
void swap(){
     
}
void permutation(string in, int idx = 0)
{
    if (idx >= in.size()){
        cout << in << endl;
        return;
    }
    for (int i = idx; i < in.size(); i++)
    {
        swap(in[idx], in[i]);
        permutation(in, idx + 1);
        swap(in[idx], in[i]);
    }
}
int main()
{
    // int n;
    // cin >> n;
    // count(n);
    // cout << endl;
    // cout << fact(n) << endl;
    // cout << nthFibb(10);
    // num(325612342 );
    // cout << expo(5);
    // int arr[]={1,4,5,6, 78,9};
    // if (sorted(arr , 6))
    // {
    //     cout << "Yes";
    // }
    // else
    //     cout << "No";
    // vector<int>i={1,2,3,4,5,6};
    // vector<int>o={};
    // subset(i,o,0);
    // cout<<endl<<total;
    // cout << NthStair(8);
    // string a = "abc", ou = "";
    // permutation(a, 0);
    int count1 = 0;
    cout<<nthFibb(40, count1)<<endl;
    cout<<count1<<endl;
    int count2= 0;
    cout<<fibIter(40, count2)<<endl;
    cout<<count2;
    return 0;
}