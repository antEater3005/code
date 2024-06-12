#include <bits/stdc++.h>
using namespace std;
// Primality check:: to check wether a number is prime or not
// basic method
bool is_prime(long long n) // only gives possible for numbers upto 10^16 in a reasonable amount of time
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

// 2:: Sieve of Eratosthenes:: It's a simple algorithm used to find all the prime numbers from 2 to N;
void prime_SE(vector<bool> &ans, long long n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (ans[i] == 0) // here we check is the i is prime or not if its not prime that means all its multiples are already marked as composite; its just reduces the number of operations performed;
        {
            for (int j = i * 2; j < n; j += i)
                ans[j] = 1; // marking all the multiples of i as composite
        }
    }
    // ans[i]=0, means i is prime number else if 1 means composite number;
}

// 3:: Fermat Primality Testing:: this test is based on the Fermat's Little Theorem, this theorem states that given a prime number P, and any number A such that 0<A<P then  ' (A^(P-1))%P=1 ';
// it's only feasible for a single number;

// modular exponentiation
int power(int a, int n, int p)
{
    int res = 1;
    while (n > 0)
    {
        // if n is odd then multiply res by a
        if (n & 1)
            res = (res * a) % p;
        // here the n must be even
        n >>= 1; // n=n/2
        a = (a * a) % p;
    }
    return res;
}

bool is_prime_FPT(long long n)
{
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
    int k = 10; // the value of k is randomly taken  //not too less. not too high.
    while (k--)
    {
        int a = 2 + rand() % (n - 4);
        if (power(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
int minimumMoves(int A, int B)
{
    int a = A, b = B, steps = 0;
    while (a && b)
    {
        steps++;
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return steps;
}
int main()
{

    double x = 21.929;
    cout << fixed << setprecision(2) << x << endl;
    if (x < 15)
        cout << "FAIL";
    else
        cout << "PASS";
    return 0;
}

class Solution
{
public:
    vector<int> res;

    void helper(int i, vector<int> &people_skill, int m, int mask, vector<int> &ans, vector<vector<int>> &dp)
    {
        if (i == people_skill.size()) // Base Case
        {
            if (mask == ((1 << m) - 1)) // Check for all req_skills included
            {
                if (res.size() == 0 || (ans.size() < res.size()))
                    res = ans; // better ans then update
            }
            return;
        }

        if (dp[i][mask] != -1) // Memoization Part
        {
            if (dp[i][mask] <= ans.size())
                return;
        }

        helper(i + 1, people_skill, m, mask, ans, dp); // Non-Pick / Ignore Case

        ans.push_back(i); // Pick Case

        helper(i + 1, people_skill, m, (mask | people_skill[i]), ans, dp); // Next Call

        ans.pop_back(); // Undo the change in Pick

        if (ans.size() > 0)
            dp[i][mask] = ans.size(); // if found and answer then update DP
    }

    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {

        int n = people.size();
        int m = req_skills.size();

        unordered_map<string, int> mpp; // for hashing skill v/s bit

        for (int i = 0; i < m; ++i)
            mpp[req_skills[i]] = (1 << i); // setting ith bit, for req_skill[i] skill

        vector<int> people_skill; // vector of mask for peoples

        for (auto it : people)
        {
            int mask = 0;
            for (int j = 0; j < it.size(); ++j)
            {
                if (mpp.count(it[j]))
                    mask |= mpp[it[j]]; // if it[j] is a required skill then set that bit for that people's mask
            }
            people_skill.push_back(mask); // store the mask
        }

        vector<vector<int>> dp(n, vector<int>((1 << m), -1)); // n=number of people, and (1<<m) to express all value mask of size m can take
        vector<int> ans;

        helper(0, people_skill, m, 0, ans, dp);
        return res;
    }
};
