#include <bits/stdc++.h>
using namespace std;

int main() { return 0; }

class Solution1 {
public:
  int minFlips(string s) {
    int ans = s.length(), n = s.length();
    vector<int> pre(2 * n + 1, 0);
    vector<int> pre2(2 * n + 1, 0);
    for (int i = 0; i < n * 2; i++) {
      char c = s[i % n];
      pre[i + 1] = pre[i] + (c != ((i & 1) ? '1' : '0'));
      pre2[i + 1] = pre2[i] + (c != ((i & 1) ? '0' : '1'));
      if (i >= n - 1) {
        ans = min(ans, pre[i + 1] - pre[i + 1 - n]);
        ans = min(ans, pre2[i + 1] - pre2[i + 1 - n]);
      }
    }
    return ans;
  }
};

class Solution2 {
  int dp[401][401][2][401] = {0};
  int mod = 1e9 + 7;
  int precious(int zero, int one, int prev, int streak, int limit) {
    if (zero == 0 && one == 0) {
      return 1;
    }

    if (dp[zero][one][prev][streak] != -1) {
      return dp[zero][one][prev][streak];
    }

    long ans = 0;

    // Try to append zero
    if (zero && streak < limit) {
      ans = (ans + precious(zero - 1, one, 0, !prev ? streak + 1 : 1, limit)) %
            mod;
    }
    // Try to append one
    if (one && streak < limit) {
      ans = (ans + precious(zero, one - 1, 1, prev ? streak + 1 : 1, limit)) %
            mod;
    }
    return dp[zero][one][prev][streak] = ans;
  }

public:
  int numberOfStableArrays(int zero, int one, int limit) {
    memset(dp, -1, sizeof dp);
    return precious(zero, one, -1, 0, limit);
  }
};