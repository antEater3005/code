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
class Solution4 {
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

class Solution5 {
 private:
  int getSum(int x, int y, int d, vector<vector<int>>& grid) {
    if (d == 0) return grid[x][y];

    int sum = 0;
    // We traverse 4 sides. Each side has 'd' elements if we don't double-count corners.
    for (int i = 0; i < d; ++i) {
      sum += grid[x - d + i][y + i];  // Top-corner to Right-corner
      sum += grid[x + i][y + d - i];  // Right-corner to Bottom-corner
      sum += grid[x + d - i][y - i];  // Bottom-corner to Left-corner
      sum += grid[x - i][y - d + i];  // Left-corner to Top-corner
    }
    return sum;
  }

  bool isValidIndex(int i, int j, int m, int n, int d) { return (i - d >= 0) && (i + d < m) && (j - d >= 0) && (j + d < n); }

 public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    // vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> seen;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        for (int d = 0; isValidIndex(i, j, m, n, d); d++) {
          int sum = getSum(i, j, d, grid);
          if (seen.count(sum)) continue;
          seen.insert(sum);
          pq.push(sum);
          if (pq.size() > 3) pq.pop();
        }
      }
    }
    vector<int> ans;
    while (!pq.empty()) {
      ans.insert(ans.begin(), pq.top());
      pq.pop();
    }
    return ans;
  }
};

class Solution6 {
  /**
   * LC 1727. Largest Submatrix With Rearrangements
   * The idea is to compute the prefix sum of the matrix column-wise, which gives us the height of consecutive 1's for each cell. Then, for each row,
   * we sort the heights and calculate the area of the largest rectangle that can be formed with those heights. The area is given by height * width,
   * where width is determined by the position in the sorted array. We keep track of the maximum area found across all rows and return it as the
   * answer.
   * This approach has a time complexity of O(m*n*log(n)) due to the sorting step for each row, where m is the number of rows and n is the number of columns in the matrix.
   */
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> prefixSum(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0)
          prefixSum[i][j] = matrix[i][j];
        else
          prefixSum[i][j] += (matrix[i][j] ? prefixSum[i - 1][j] + 1 : 0);
      }
    }
    int ans = 0;
    for (auto& it : prefixSum) {
      sort(it.begin(), it.end());
      for (int i = 0; i < n; i++) {
        ans = max(ans, it[i] * (n - i));
      }
    }
    return ans;
  }
};

class Solution {

  /**
   * LC 3070. Count Submatrices with Top-Left Element and Sum Less Than k
   * The idea is to compute the prefix sum of the matrix, which allows us to quickly calculate the sum of any submatrix. We iterate through each cell in the matrix and calculate the prefix sum up to that cell. If the prefix sum is less than or equal to k, we increment our result count. If it exceeds k, we break out of the inner loop since any larger submatrix starting from that cell will also exceed k.
   * This approach has a time complexity of O(m*n) for computing the prefix sums and O(m*n) for counting the valid submatrices, resulting in an overall time complexity of O(m*n).
   */
  
 public:
  // int countSubmatrices(vector<vector<int>>& grid, int k) {
  //   int result = 0;
  //   vector<vector<int>> sum(grid.size(), vector<int>(grid[0].size(), 0));
  //   for (int i = 0; i < grid.size(); i++) {
  //     for (int j = 0; j < grid[0].size(); j++) {
  //       if (i == 0 && j == 0)
  //         sum[i][j] = grid[i][j];
  //       else if (i == 0)
  //         sum[i][j] = grid[i][j] + sum[i][j - 1];
  //       else if (j == 0)
  //         sum[i][j] = grid[i][j] + sum[i - 1][j];
  //       else
  //         sum[i][j] = grid[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  //       if (sum[i][j] <= k)
  //         result++;
  //       else
  //         break;
  //     }
  //   }
  //   return result;
  // }

  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (i == 0 && j == 0)
          grid[i][j] = grid[i][j];
        else if (i == 0)
          grid[i][j] = grid[i][j] + grid[i][j - 1];
        else if (j == 0)
          grid[i][j] = grid[i][j] + grid[i - 1][j];
        else
          grid[i][j] = grid[i][j] + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        if (grid[i][j] <= k)
          result++;
        else
          break;
      }
    }
    return result;
  }
};