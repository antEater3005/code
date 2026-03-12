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
  int dp[201][201][3];
  int mod = 1e9 + 7;
  int precious(int zero, int one, int prev, int limit) {
    if (zero == 0 && one == 0) {
      return 1;
    }

    if (dp[zero][one][prev] != -1) {
      return dp[zero][one][prev];
    }

    long ans = 0;

    // Try to append zero
    if (prev == 1) {
      for (int x = 1; x <= min(zero, limit); x++) ans = (ans + precious(zero - x, one, 0, limit)) % mod;
    }
    // Try to append one
    else {
      for (int x = 1; x <= min(one, limit); x++) ans = (ans + precious(zero, one - x, 1, limit)) % mod;
    }
    return dp[zero][one][prev] = ans;
  }

 public:
  //   int numberOfStableArrays(int zero, int one, int limit) {
  //     memset(dp, -1, sizeof(dp));
  //     return precious(zero, one, 0, limit) + precious(zero, one, 1, limit);
  //   }

  int numberOfStableArrays(int zero, int one, int limit) {
    int memo[201][201][2] = {};
    memo[0][0][0] = memo[0][0][1] = 1;

    for (int i = 0; i <= zero; i++) {
      for (int j = 0; j <= one; j++) {
        if (i == 0 && j == 0) continue;

        int result = 0;

        // Try zeroes
        for (int len = 1; len <= min(i, limit); len++) result = (result + memo[i - len][j][0]) % mod;
        memo[i][j][1] = result;
        // Try Ones
        result = 0;
        for (int len = 1; len <= min(j, limit); len++) result = (result + memo[i][j - len][1]) % mod;
        memo[i][j][0] = result;
      }
    }
    return (0L + memo[zero][one][0] + memo[zero][one][1]) % mod;
  }
};

class Solution3 {
  int mod = 1e9 + 7;

 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    int dp[1001][1001][2] = {};
    dp[0][0][0] = dp[0][0][1] = 1;

    for (int i = 0; i <= zero; i++) {
      for (int j = 0; j <= one; j++) {
        if (i == 0 && j == 0) continue;
        // Try Zeroes
        int prevIdx0 = i - min(i, limit);
        long sum1 = 1L * (dp[i][j][0] - (prevIdx0 == 0 ? 0 : dp[prevIdx0 - 1][j][0])) % mod;
        dp[i][j][1] = (sum1 + (j > 0 ? dp[i][j - 1][1] : 0)) % mod;

        // Try Ones
        int prevIdx1 = j - min(j, limit);
        long sum2 = 1L * (dp[i][j][1] - (prevIdx1 == 0 ? 0 : dp[i][prevIdx1 - 1][1])) % mod;
        dp[i][j][0] = (sum2 + (i > 0 ? dp[i - 1][j][0] : 0)) % mod;
      }
    }

    cout << dp[zero][one][0] << " " << dp[zero][one][1] << endl;

    long sum1 = 1L * (dp[zero][one][1] - (min(limit, zero) - 1 == 0 ? 0 : dp[zero - min(zero, limit) - 1][one][1])) % mod;
    long sum2 = 1L * (dp[zero][one][0] - (min(limit, one) - 1 == 0 ? 0 : dp[zero][one - min(one, limit) - 1][0])) % mod;
    return (sum1 + sum2 + mod) % mod;
  }
};
class Solution {
  int mod = 1e9 + 7;

 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));

    for (int i = 0; i <= min(limit, zero); i++) dp[i][0][0] = 1;
    for (int j = 0; j <= min(limit, one); j++) dp[0][j][1] = 1;

    for (int i = 0; i < zero + 1; i++) {
      for (int j = 0; j < one + 1; j++) {
        if (i == 0 || j == 0) continue;

        dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % mod;
        if (j - 1 >= limit) {
          dp[i][j][1] = (dp[i][j][1] - dp[i][j - limit - 1][0] + mod) % mod;
        }

        dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
        if (i - 1 >= limit) {
          dp[i][j][0] = (dp[i][j][0] - dp[i - limit - 1][j][1] + mod) % mod;
        }
      }
    }
    return (dp[zero][one][0] + dp[zero][one][1]) % mod;
  }
};