#include <bits/stdc++.h>
using namespace std;
void subset(int arr[], int n)
{
  for (int i = 0; i < (1 << n); i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {

        cout << arr[j] << " ";
      }
    }
    cout << endl;
  }
}
int main()
{
  int n = 4;
  int arr[4] = {1, 2, 3, 4};
  subset(arr, n);

  return 0;
}

class Solution
{
public:
  int countTrapezoids(vector<vector<int>> &points)
  {
    unordered_map<int, int> map;
    for (auto p : points)
    {
      int x = p[0], y = p[1];
      map[y]++;
    }
    long ans = 0, mod = 1e9 + 7;
    long long sum = 0;
    for (auto it = map.cbegin(); it != map.cend(); it++)
    {
      int num = it->second * (it->second - 1) / 2;
      ans = (ans + sum * it->second) % mod;
      sum += it->second;
    }
    return ans;
  }
};

  