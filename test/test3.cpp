#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int sum(string s, int plus, int i, int j)
    {
        int ans;
        string a = s.substr(i + 1, plus - i + 1);
        string b = s.substr(plus + 1, j - plus - 1);
        string c = s.substr(1, i - 1);
        string d = s.substr(j, s.size() - j);
        ans = (stoi(a) + stoi(b)) * c.empty() ? 1 : stoi(c) * d.empty() ? 1
                                                                        : stoi(d);
        return ans;
    }

private:
    void ans(string s, int i, int j, int &ai, int &aj, int plus)
    {
        if (i == plus || j == plus)
            return;
    }

public:
    string minimizeResult(string expression)
    {
    }
};
int sum(string s, int plus, int i, int j)
{
    int ans;
    string a = s.substr(i, plus - i + 1);
    string b = s.substr(plus, j - plus - 1);
    string c = s.substr(1, i - 1);
    string d = s.substr(j, s.size() - j);
    ans = (stoi(a) + stoi(b)) * c.empty() ? 1 : stoi(c) * d.empty() ? 1
                                                                    : stoi(d);
    return ans;
}
int main()
{
    string s = "e247+38e";
    cout << sum(s, 3, 1, 5);

    // cout << a;
    return 0;
}
class Solution
{
public:
    string minimizeResult(string expression)
    {
        int plus = 0;
        for (char ch : expression)
            if (ch == '+')
                break;
            else
                plus++;
        string a = expression.substr(0, plus + 1), b = expression.substr(plus + 1, expression.size() - plus - 1);
        int left = 0, leftmax = stoi(a);
        for (int i = 1; i < a.size() - 1; i++)
        {
            int t = stoi(a.substr(0, i)) * stoi(a.substr(i, a.size() - i - 1));
            if (t < leftmax)
            {
                left = i;
                leftmax = t;
            }
        }
        int right = plus, rightmax = stoi(b);
        for (int i = 1; i < b.size() - 1; i++)
        {
            int t = stoi(b.substr(0, i)) * stoi(b.substr(i, b.size() - i - 1));
            if (t < rightmax)
            {
                left = i;
                rightmax = t;
            }
        }
        expression.insert(expression.begin() + left, '(');
        expression.insert(expression.begin() + plus + right, ')');
        return expression;
    }
};