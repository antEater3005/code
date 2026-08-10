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
   * This approach has a time complexity of O(m*n*log(n)) due to the sorting step for each row, where m is the number of rows and n is the number of
   * columns in the matrix.
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

class Solution7 {
  /**
   * LC 3070. Count Submatrices with Top-Left Element and Sum Less Than k
   * The idea is to compute the prefix sum of the matrix, which allows us to quickly calculate the sum of any submatrix. We iterate through each cell
   * in the matrix and calculate the prefix sum up to that cell. If the prefix sum is less than or equal to k, we increment our result count. If it
   * exceeds k, we break out of the inner loop since any larger submatrix starting from that cell will also exceed k. This approach has a time
   * complexity of O(m*n) for computing the prefix sums and O(m*n) for counting the valid submatrices, resulting in an overall time complexity of
   * O(m*n).
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

class Solution8 {
 public:
  int maxProductPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size(), mod = 1e9 + 7;
    vector<long> dpMin(m), dpMax(m);
    for (int i = 0; i < n; i++) {
      vector<long> currMin(m), currMax(m);
      for (int j = 0; j < m; j++) {
        long curr = grid[i][j];
        if (i == 0 && j == 0) {
          currMax[j] = curr;
          currMin[j] = curr;
        } else {
          long bestMin = LONG_MAX, bestMax = LONG_MIN;
          if (i > 0) {
            bestMax = max({bestMax, dpMax[j] * curr, dpMin[j] * curr});
            bestMin = min({bestMin, dpMin[j] * curr, dpMax[j] * curr});
          }
          if (j > 0) {
            bestMax = max({bestMax, currMax[j - 1] * curr, currMin[j - 1] * curr});
            bestMin = min({bestMin, currMin[j - 1] * curr, currMax[j - 1] * curr});
          }

          currMin[j] = bestMin;
          currMax[j] = bestMax;
        }
      }
      swap(currMax, dpMax);
      swap(currMin, dpMin);
    }
    return dpMax[m - 1] < 0 ? -1 : (dpMax[m - 1] % mod);
  }
};

class Solution9 {
 public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size(), prefix = 1, suffix = 1, mod = 12345;
    vector<vector<int>> ans(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans[i][j] = (prefix * ans[i][j]) % mod;
        ans[n - i - 1][m - j - 1] = (suffix * ans[n - i - 1][m - j - 1]) % mod;
        prefix = (1L * prefix * grid[i][j]) % mod;
        suffix = (1L * suffix * grid[n - i - 1][m - j - 1]) % mod;
      }
    }
    return ans;
  }
};

class Solution10 {
 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    long n = grid.size(), m = grid[0].size(), totalSum = 0;
    vector<long> colSum(m, 0), rowSum(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        colSum[j] += grid[i][j];
        rowSum[i] += grid[i][j];
        totalSum += grid[i][j];
      }
    }
    long sum = 0;
    for (int i = 0; i < n - 1; i++) {
      sum += rowSum[i];
      if (sum * 2 == totalSum) return true;
    }
    sum = 0;

    for (int j = 0; j < m - 1; j++) {
      sum += colSum[j];
      if (sum * 2 == totalSum) return true;
    }
    return false;
  }
};

class Solution11 {
 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    long totalSum = 0;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        totalSum += grid[i][j];
        freq[grid[i][j]]++;
      }
    }

    unordered_map<int, int> prefixFreq, suffixFreq = freq;

    // cut along rows
    long sum = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        prefixFreq[grid[i][j]]++;
        suffixFreq[grid[i][j]]--;
        sum += grid[i][j];
      }

      long diff = abs(2 * sum - totalSum);
      if (diff == 0)
        return true;
      else if (m == 1) {
        if (diff == grid[0][0] || diff == grid[i][0] || diff == grid[i + 1][0] || diff == grid[n - 1][0]) return true;
      } else if ((i == 0 && i == n - 2)) {
        if (diff == grid[i][0] || diff == grid[i][m - 1] || diff == grid[i + 1][0] || diff == grid[i + 1][m - 1]) return true;
      } else if (i > 0 && i < n - 2) {
        return suffixFreq[diff] > 0 || prefixFreq[diff] > 0;
      } else {
        if (i == 0) {
          if (grid[i][0] == diff || grid[i][m - 1] == diff || suffixFreq[diff] > 0) return true;
        } else if (i == n - 1) {
          if (grid[i + 1][0] == diff || grid[i + 1][m - 1] == diff || prefixFreq[diff] > 0) return true;
        }
      }
    }

    prefixFreq.clear();
    suffixFreq = freq;

    sum = 0;
    for (int j = 0; j < m - 1; j++) {
      for (int i = 0; i < n; i++) {
        prefixFreq[grid[i][j]]++;
        suffixFreq[grid[i][j]]--;
        sum += grid[i][j];
      }

      long diff = abs(2 * sum - totalSum);
      if (diff == 0)
        return true;
      else if (n == 1) {
        if (diff == grid[0][0] || diff == grid[0][j] || diff == grid[0][j + 1] || diff == grid[0][m - 1]) return true;
      } else if ((j == 0 && j == m - 2)) {
        if (diff == grid[0][j] || diff == grid[n - 1][j] || diff == grid[0][j + 1] || diff == grid[n - 1][j + 1]) return true;
      } else if (j > 0 || j < m - 2) {
        return suffixFreq[diff] > 0 || prefixFreq[diff] > 0;
      } else {
        if (j == 0) {
          if (grid[0][j] == diff || grid[n - 1][j] == diff || suffixFreq[diff] > 0) return true;
        } else if (j == m - 1) {
          if (grid[0][j + 1] == diff || grid[n - 1][j + 1] == diff || prefixFreq[diff] > 0) return true;
        }
      }
    }
    return false;
  }
};

class Solution12 {
 public:
  string generateString(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    string result(n + m - 1, 'a');
    vector<bool> canChange(n + m - 1, true);
    for (int i = 0; i < n; i++) {
      if (str1[i] == 'T') {
        for (int j = i; j < i + m; j++) {
          if (!canChange[j] && result[j] != str2[j - i]) return "";
          canChange[j] = false;
          result[j] = str2[j - i];
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (str1[i] == 'F') {
        bool needChange = true;
        for (int j = i; j < i + m; j++) {
          if (result[j] != str2[j - i]) {
            needChange = false;
            break;
          }
        }

        if (needChange) {
          for (int j = i + m - 1; j >= i; j--) {
            if (canChange[j]) {
              result[j] = 'b';
              needChange = false;
              break;
            }
          }
        }
        if (needChange) return "";
      }
    }
    return result;
  }
};

class Solution13 {
  int n, m;
  int dp[501][501][3];
  int solve(vector<vector<int>>& coins, int i, int j, int neu) {
    if (i == n - 1 && j == m - 1) {
      if (coins[i][j] < 0 && neu > 0) {
        return 0;
      }
      return coins[i][j];
    }

    if (i >= n || j >= m) return INT_MIN;

    if (dp[i][j][neu] != INT_MIN) return dp[i][j][neu];

    int take = coins[i][j] + max(solve(coins, i + 1, j, neu), solve(coins, i, j + 1, neu));

    if (coins[i][j] < 0 && neu > 0) take = max({take, solve(coins, i + 1, j, neu - 1), solve(coins, i, j + 1, neu - 1)});
    return dp[i][j][neu] = take;
  }

 public:
  int maximumAmount(vector<vector<int>>& coins) {
    n = coins.size(), m = coins[0].size();
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++)
        for (int k = 0; k < 3; k++) dp[i][j][k] = INT_MIN;
    return solve(coins, 0, 0, 2);
  }
};

class Solution14 {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    pair<int, int> directionMult[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    set<pair<int, int>> obs;
    for (vector<int>& ob : obstacles) obs.insert({ob[0], ob[1]});
    int x = 0, y = 0, direction = 0;
    for (int move : commands) {
      if (move == -1) {
        direction = (direction - 1 + 4) % 4;
      } else if (move == -2) {
        direction = (direction + 1) % 4;
      } else {
        pair<int, int> directionalMul = directionMult[direction];
        while (move > 0) {
          int nx = x + directionalMul.first;
          int ny = y + directionalMul.second;
          if (obs.find({nx, ny}) == obs.end()) {
            nx = x;
            ny = y;
          } else {
            break;
          }
        }
      }
    }
    return x * x + y * y;
  }
};

class Robot {
  pair<int, int> directionMult[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  string directions[4] = {"North", "East", "South", "West"};
  int direction = 1;
  int x = 0, y = 0;
  int top, right;

 public:
  Robot(int width, int height) {
    top = height - 1;
    right = width - 1;
  }

  void changeDirection() { direction = (direction + 3) % 4; }

  void move(int steps) {
    x = x + steps * directionMult[direction].first;
    y = y + steps * directionMult[direction].second;
  }

  int maxStepCanTake(int steps) {
    switch (direction) {
      case 0:
        return min(top, y + steps) - y;
        break;
      case 1:
        return min(right, x + steps) - x;
        break;
      case 2:
        return y - max(0, y - steps);
        break;
      case 3:
        return x - max(0, x - steps);
        break;
    }
    return steps;
  }

  void step(int num) {
    int perimeterMoves = 2 * (top + right);
    num %= perimeterMoves;

    if (num == 0 && x == 0 && y == 0) {
      direction = 2;
      return;
    }

    while (num) {
      int maxsteps = maxStepCanTake(num);
      move(maxsteps);
      num -= maxsteps;
      if (num > 0) {
        changeDirection();
      }
    }
  }

  vector<int> getPos() { return {x, y}; }

  string getDir() { return directions[direction]; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

typedef long long ll;
class Solution15 {
  int mod = 1e9 + 7;
  ll power(ll a, ll b) {
    if (b == 0) return 1;

    ll half = power(a, b / 2);
    ll result = (half * half) % mod;

    if (b % 2 == 1) {
      result = (result * a) % mod;
    }
    return result;
  }

 public:
  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int blockSize = ceil(sqrt(n));
    unordered_map<int, vector<vector<int>>> smallKMap;

    for (auto& q : queries) {
      int l = q[0], r = q[1], k = q[2], v = q[3];

      if (k >= blockSize) {
        for (int i = l; i <= r; i += k) {
          nums[i] = (1ll * nums[i] * v) % mod;
        }
      } else {
        smallKMap[k].push_back(q);
      }
    }

    for (auto& [k, allQueries] : smallKMap) {
      vector<ll> diff(n, 1);
      for (auto& q : allQueries) {
        int l = q[0], r = q[1], k = q[2], v = q[3];
        diff[l] = (diff[l] * v) % mod;
        int steps = (r - l) / k;
        int next = l + (steps + 1) * k;
        if (next < n) diff[next] = (diff[next] * power(v, mod - 2)) % mod;
      }

      // Calculate cumulative product
      for (int i = 0; i < n; i++) {
        if (i - k >= 0) {
          diff[i] = (diff[i] * diff[i - k]) % mod;
        }
      }

      // Apply Cumulative product to nums
      for (int i = 0; i < n; i++) {
        nums[i] = (1LL * nums[i] * diff[i]) % mod;
      }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
      result = result ^ nums[i];
    }
  }
};

class DisjointSet {
  vector<int> parent;
  vector<int> rank;

 public:
  DisjointSet(int n) {
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i, rank[i] = 0;
  }

  int find_parent(int n) {
    if (n == parent[n]) return n;
    return parent[n] = find_parent(parent[n]);  // Path compression
  }
  void union_nodes(int u, int v)  // Union by rank
  {
    int parent_of_u = find_parent(u);
    int parent_of_v = find_parent(v);
    if (rank[parent_of_u] > rank[parent_of_v])
      parent[parent_of_v] = parent_of_u;
    else if (rank[parent_of_u] < rank[parent_of_v])
      parent[parent_of_u] = parent_of_v;
    else {
      parent[parent_of_u] = parent_of_v;
      rank[parent_of_v] += 1;
    }
  }
};

class Solution16 {
 public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    DisjointSet ds(source.size());

    for (auto& swap : allowedSwaps) ds.union_nodes(swap[0], swap[1]);

    unordered_map<int, unordered_map<int, int>> groups;

    for (int i = 0; i < source.size(); i++) {
      groups[ds.find_parent(i)][source[i]]++;
    }

    int distance = source.size();

    for (int i = 0; i < source.size(); i++) {
      int parent = ds.find_parent(i);
      if (groups[parent][target[i]] > 0) {
        groups[parent][target[i]]--;
        distance--;
      }
    }
    return distance;
  }
};

class Solution17 {
 public:
  vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> result;
    for (string& s : queries)
      for (string& str : dictionary) {
        int dist = 0;
        for (int i = 0; i < s.size() && dist < 3; i++)
          if (str[i] != s[i]) dist++;

        if (dist <= 2) {
          result.push_back(s);
          break;
        }
      }
    return result;
  }
};

class Solution18 {
 public:
  vector<long long> distance(vector<int>& nums) {
    vector<long long> result(nums.size());
    unordered_map<int, pair<long, int>> front, back;
    for (int i = 0; i < nums.size(); i++) {
      if (front.find(nums[i]) == front.end()) {
        front[nums[i]] = {0, 0};
      }
      auto p = front[nums[i]];
      front[nums[i]] = {p.first + i, p.second + 1};
    }

    for (int i = 0; i < nums.size(); i++) {
      auto pf = front[nums[i]], pb = back[nums[i]];

      long long distance = pf.first - 1LL * i * pf.second + 1LL * i * pb.second - pb.first;
      long long distance = (1LL * i * pf.second - pf.first) + (pb.first - 1LL * i * pb.second);

      result[i] = distance;

      // Update front and back maps
      front[nums[i]] = {pf.first - i, pf.second - 1};
      back[nums[i]] = {pb.first + i, pb.second + 1};
    }
    return result;
  }
};

class Solution19 {
  typedef long long ll;
  int n;
  ll dp[2][101][101] = {};

 private:
  ll solve(bool isPrevTaken, int prevHeight, int col, vector<vector<int>>& grid, vector<vector<ll>>& colPrefixSum) {
    if (col == n) return 0;

    ll result = 0;

    if (dp[isPrevTaken][prevHeight][col] != -1) return dp[isPrevTaken][prevHeight][col];

    for (int h = 0; h <= n; h++) {
      ll prevColScore = 0;
      ll currColScore = 0;

      if (!isPrevTaken && col > 0 && h > prevHeight) {
        prevColScore += colPrefixSum[h][col] - colPrefixSum[prevHeight][col];
      }

      if (prevHeight > h) {
        currColScore += colPrefixSum[prevHeight][col + 1] - colPrefixSum[h][col + 1];
      }

      ll currColScoreTaken = currColScore + prevColScore + solve(true, h, col + 1, grid, colPrefixSum);
      ll currColScoreNotTaken = prevColScore + solve(false, h, col + 1, grid, colPrefixSum);

      result = max({result, currColScoreNotTaken, currColScoreTaken});
    }
    return dp[isPrevTaken][prevHeight][col] = result;
  }

 public:
  ll maximumScore(vector<vector<int>>& grid) {
    n = grid.size();
    vector<vector<ll>> columnPrefixSum(n + 1, vector<ll>(n + 1, 0));
    memset(dp, -1, sizeof dp);

    for (int col = 1; col <= n; col++)
      for (int row = 1; row <= n; row++) {
        columnPrefixSum[row][col] = columnPrefixSum[row - 1][col] + grid[row - 1][col - 1];
      }

    return solve(false, 0, 0, grid, columnPrefixSum);
  }
};

class Solution20 {
  static int dp[201][201][1001];

 public:
  int maxPathScore(vector<vector<int>>& grid, int k) {
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        int creditRequired = grid[i][j] != 0;
        for (int c = creditRequired; c <= k; c++) {
          if (i == 0 && j == 0) {
            dp[i][j][c] = grid[i][j];
          } else {
            int prevMax = -1;
            if (i > 0) prevMax = max(prevMax, dp[i - 1][j][c - creditRequired]);
            if (j > 0) prevMax = max(prevMax, dp[i][j - 1][c - creditRequired]);

            if (prevMax > -1) dp[i][j][c] = grid[i][j] + prevMax;
          }
        }
      }
    }
    int result = -1;
    for (int c = 0; c <= k; c++) result = max(result, dp[grid.size() - 1][grid[0].size() - 1][c]);
    return result;
  }
};

class Solution21 {
 public:
  vector<int> maxValue(vector<int>& nums) {
    vector<int> result(nums.size());
    int maxSoFar = INT_MIN;
    vector<int> leftMax(nums.size()), rightMin(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      maxSoFar = max(maxSoFar, nums[i]);
      leftMax[i] = maxSoFar;
    }
    int minSoFar = INT_MAX;
    for (int i = nums.size() - 1; i >= 0; i--) {
      minSoFar = min(minSoFar, nums[i]);
      rightMin[i] = minSoFar;
    }

    result[nums.size() - 1] = leftMax.back();
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (leftMax[i] <= rightMin[i + 1])
        result[i] = leftMax[i];
      else
        result[i] = result[i + 1];
    }
    return result;
  }
};

class Solution22 {
 public:
  int minMoves(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<int> diff(limit * 2 + 1, 0);

    for (int i = 0; i < n / 2; i++) {
      int mini = nums[i], maxi = nums[n - 1 - i];
      if (mini > maxi) swap(mini, maxi);

      int minVal = mini + 1;
      int maxVal = maxi + limit;

      diff[2] += 2;
      diff[minVal] += (-1);
      diff[maxVal + 1] += 1;
      diff[mini + maxi] += -1;
      diff[mini + maxi + 1] += 1;
    }

    int result = INT_MAX, currMoves = 0;
    for (int sum = 2; sum <= limit * 2; sum++) {
      currMoves += diff[sum];
      result = min(currMoves, result);
    }
    return result;
  }
};

class Solution23 {
 public:
  bool isGood(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int freq[201] = {0}, count = 0;
    for (int num : nums) {
      if (num > nums.size()) continue;
      if (freq[num - 1] == 0) count++;
      freq[num - 1]++;
    }
    return count == (nums.size() - 1) && freq[nums.size() - 2] == 2;
  }
};

class Solution24 {
 public:
  int minJumps(vector<int>& arr) {
    int n = arr.size();
    vector<bool> visited(n, false);
    unordered_map<int, vector<int>> adjList;
    for (int i = 0; i < n; i++) {
      adjList[arr[i]].push_back(i);
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;
    int jumps = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int node = q.front();
        q.pop();

        if (node == n - 1) return jumps;

        // Add i+1
        if (node + 1 < n && !visited[node + 1]) {
          visited[node + 1] = true;
          q.push(node + 1);
        }

        // Add i-1
        if (node - 1 >= 0 && !visited[node - 1]) {
          visited[node - 1] = true;
          q.push(node - 1);
        }

        // Add Equal indices
        for (int i : adjList[arr[node]]) {
          if (i == n - 1) return jumps;
          if (!visited[i]) {
            visited[i] = true;
            q.push(i);
          }
        }
      }
      jumps++;
    }
    return -1;
  }
};

class Solution25 {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vector<int> m1(51, 0), m2(51, 0);
    vector<int> ans;
    for (int i = 0; i < A.size(); i++) {
      int x = 0;
      if (m1[B[i]] > 0) x++;
      ++m2[B[i]];
      if (m2[A[i]] > 0) x++;
      ++m1[A[i]];

      ans.push_back((ans.empty() ? 0 : ans.back()) + x);
    }
    return ans;
  }
};

class Solution26 {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int scanned = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();

      if (x == n - 1) return true;

      int temp = max(x + minJump, scanned + 1);
      for (int i = temp; i <= x + maxJump && i < n; i++) {
        if (!visited[i] && s[i] == '0') {
          q.push(i);
          visited[i] = true;
        }
      }
      scanned = x + maxJump;
    }
    return false;
  }
};

class Solution27 {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    vector<bool> dp(s.size(), false);
    dp[0] = 1;
    int activeSources = 0;
    for (int i = 1; i < s.size(); i++) {
      if (i > maxJump && dp[i - maxJump - 1]) activeSources--;

      if (i >= minJump && dp[i - minJump]) activeSources++;

      dp[i] = s[i] == '0' && activeSources > 0;
    }
    return dp[s.size() - 1];
  }
};

class Solution28 {
 public:
  int numberOfSpecialChars(string word) {
    bool lowercase[26] = {0}, uppercase[26] = {0}, count[26] = {};
    memset(count, 1, sizeof count);
    for (char c : word) {
      if (c >= 'a' && c <= 'z') {
        lowercase[c - 'a'] = true;
        if (uppercase[c - 'a']) count[c - 'a'] = false;
      } else
        uppercase[c - 'A'] = true;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      ans += (lowercase[i] && uppercase[i] && count[i]);
    }
    return ans;
  }
};

class Solution29 {
 public:
  int numberOfSpecialChars(string word) {
    int lowercase[27] = {0}, uppercase[27] = {0};
    for (int i = 0; i < word.size(); i++) {
      char c = word[i];
      if (c >= 'a' && c <= 'z') {
        lowercase[c - 'a' + 1] = i + 1;
      } else if (!uppercase[c - 'A' + 1])
        uppercase[c - 'A' + 1] = i + 1;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      ans += (uppercase[i + 1] && lowercase[i + 1] && lowercase[i + 1] < uppercase[i + 1]);
    }
    return ans;
  }
};
class TrieNode {
 public:
  TrieNode* childs[26];
  int smallestIndex;
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      childs[i] = NULL;
    }
    smallestIndex = -1;
  }
  ~TrieNode() {
    for (int i = 0; i < 26; i++) delete childs[i];
  }
};

class Solution30 {
  typedef pair<string, int> pr;

 private:
  bool shouldUpdate(int oldIdx, int newIdx, const vector<string>& wordsContainer) {
    if (oldIdx == -1) return true;
    if (wordsContainer[newIdx].length() < wordsContainer[oldIdx].length()) return true;
    if (wordsContainer[newIdx].length() > wordsContainer[oldIdx].length()) return false;
    return newIdx < oldIdx;  // Tie-breaker: earliest original index
  }

  void addWord(int wordIdx, const vector<string>& wordsContainer, TrieNode* root) {
    TrieNode* parentNode = root;
    const string& word = wordsContainer[wordIdx];

    if (shouldUpdate(parentNode->smallestIndex, wordIdx, wordsContainer)) {
      parentNode->smallestIndex = wordIdx;
    }

    for (int i = word.size() - 1; i >= 0; i--) {
      char ch = word[i];
      if (parentNode->childs[ch - 'a'] == NULL) parentNode->childs[ch - 'a'] = new TrieNode();
      parentNode = parentNode->childs[ch - 'a'];
      if (shouldUpdate(parentNode->smallestIndex, wordIdx, wordsContainer)) parentNode->smallestIndex = wordIdx;
    }
  }

  int find_lcs_index(string& s, TrieNode* root) {
    int idx = root->smallestIndex;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (root->childs[s[i] - 'a'] == NULL) return idx;
      root = root->childs[s[i] - 'a'];
      idx = root->smallestIndex;
    }
    return idx;
  }

 public:
  vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    TrieNode* root = new TrieNode();
    for (int i = 0; i < wordsContainer.size(); i++) {
      addWord(i, wordsContainer, root);
    }

    // for (auto& p : wordsContainerWithIndex) cout << p.first << " " << p.second << endl;

    vector<int> result(wordsQuery.size());
    for (int i = 0; i < wordsQuery.size(); i++) {
      auto x = find_lcs_index(wordsQuery[i], root);
      result[i] = x;
    }

    delete root;

    return result;
  }
};

class Solution31 {
  // A lightweight structure using internal tracking indexes instead of raw heap pointers.
  // This layout avoids memory fragmentation and eliminates Memory Limit Exceeded (MLE) issues.
  struct Node {
    int childs[26];
    int smallestIndex;
    Node() {
      smallestIndex = -1;
      // Initialize all child transitions to -1 (indicating no valid path exists)
      fill(begin(childs), end(childs), -1);
    }
  };

 public:
  vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    // Flat continuous memory pool to store Trie nodes. Node 0 acts as the root node.
    vector<Node> trie;
    trie.emplace_back();

    // Lambda helper function to handle character insertions into the vector-managed Trie
    auto addWord = [&](int idx) {
      string& word = wordsContainer[idx];
      int currNodeIndex = 0;  // Always start traversal from the root node index (0)

      // Lambda comparator to execute tie-breaking priority mechanics on the fly
      auto shouldUpdate = [&](int oldIdx, int newIdx) {
        if (oldIdx == -1) return true;
        // Metric 1: Shorter overall word length wins
        if (wordsContainer[newIdx].length() < wordsContainer[oldIdx].length()) return true;
        if (wordsContainer[newIdx].length() > wordsContainer[oldIdx].length()) return false;
        // Metric 2: Earliest original source index breaks the length tie
        return newIdx < oldIdx;
      };

      // Explicitly update the global fallback choice stored at the root level node
      if (shouldUpdate(trie[currNodeIndex].smallestIndex, idx)) {
        trie[currNodeIndex].smallestIndex = idx;
      }

      // Loop over characters in reverse order to seamlessly support suffix pattern paths
      for (int j = word.size() - 1; j >= 0; j--) {
        int charIdx = word[j] - 'a';

        // Dynamically scale the vector pool size when a character branch has not been allocated
        if (trie[currNodeIndex].childs[charIdx] == -1) {
          trie[currNodeIndex].childs[charIdx] = trie.size();
          trie.emplace_back();
        }

        // Progress downwards to the matching child node index position
        currNodeIndex = trie[currNodeIndex].childs[charIdx];

        // Evaluate and update the node optimal mapping choice at this depth layer
        if (shouldUpdate(trie[currNodeIndex].smallestIndex, idx)) {
          trie[currNodeIndex].smallestIndex = idx;  // vectors / arrays can relocate in memory when growing, but relative indices remain valid.
        }
      }
    };

    // Lambda helper function to query the Trie structure and return the longest common suffix index
    auto find_lcs_index = [&](int idx) {
      string& query = wordsQuery[idx];
      int currNodeIndex = 0;
      int ans = trie[0].smallestIndex;  // Default lookup fallback to the root tracking index

      // Traverse character matches backwards from the string query input
      for (int j = query.size() - 1; j >= 0; j--) {
        int charIdx = query[j] - 'a';
        // If the character path breaks, immediately terminate search and return current best match
        if (trie[currNodeIndex].childs[charIdx] == -1) return ans;

        currNodeIndex = trie[currNodeIndex].childs[charIdx];
        ans = trie[currNodeIndex].smallestIndex;
      }
      return ans;
    };

    // Stage 1: Build the complete indexed suffix map within the Trie allocation framework
    for (int i = 0; i < wordsContainer.size(); i++) addWord(i);

    // Stage 2: Initialize result space and resolve matching logic across all queries
    vector<int> result(wordsQuery.size());
    for (int i = 0; i < wordsQuery.size(); i++) result[i] = find_lcs_index(i);

    return result;
  }
};

class Solution32 {
 public:
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int result = INT_MAX;
    for (int i = 0; i < landDuration.size(); i++) {
      int landStart = landStartTime[i], landEndTime = landStart + landDuration[i];
      for (int j = 0; j < waterDuration.size(); j++) {
        int waterStart = waterStartTime[j], waterEndTime = waterStart + waterDuration[j];
        result = min(result, max(landEndTime, waterStart) + waterDuration[j]);
        result = min(result, max(waterEndTime, landStart) + landDuration[i]);
      }
    }
    return result;
  }
};

class Solution33 {
 public:
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int min_land_ride_end_time = INT_MAX;
    int min_water_ride_end_time = INT_MAX;
    for (int i = 0; i < landStartTime.size(); i++) {
      min_land_ride_end_time = min(min_land_ride_end_time, landStartTime[i] + landDuration[i]);
    }
    for (int i = 0; i < waterStartTime.size(); i++) {
      min_water_ride_end_time = min(min_water_ride_end_time, waterStartTime[i] + waterDuration[i]);
    }

    int take_land_ride_first = INT_MAX;
    int take_water_ride_first = INT_MAX;

    for (int i = 0; i < waterStartTime.size(); i++) {
      take_land_ride_first = min(take_land_ride_first, max(min_land_ride_end_time, waterStartTime[i]) + waterDuration[i]);
    }

    for (int i = 0; i < landStartTime.size(); i++) {
      take_water_ride_first = min(take_water_ride_first, max(min_water_ride_end_time, landStartTime[i]) + landDuration[i]);
    }

    return min(take_water_ride_first, take_land_ride_first);
  }
};

class Solution34 {
 public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> result;
    for (int num : nums) {
      if (num < pivot) result.push_back(num);
    }
    for (int num : nums) {
      if (num == pivot) result.push_back(num);
    }
    for (int num : nums) {
      if (num > pivot) result.push_back(num);
    }
    return result;
  }
};

class Solution35 {
 public:
  long long maxTotalValue(vector<int>& nums, int k) {
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i : nums) {
      mini = min(mini, i);
      maxi = max(maxi, i);
    }
    return 1LL * (maxi - mini) * k;
  }
};

typedef long long ll;

class SegmentTree {
  bool isMinTree;
  vector<int> segmentTree;

  void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
    if (l == r) {
      segmentTree[i] = nums[r];
      return;
    }
    int mid = l + (r - l) / 2;
    buildSegmentTree(i * 2 + 1, l, mid, nums);
    buildSegmentTree(i * 2 + 2, mid + 1, r, nums);
    if (this->isMinTree)
      segmentTree[i] = min(segmentTree[i * 2 + 1], segmentTree[i * 2 + 2]);
    else
      segmentTree[i] = max(segmentTree[i * 2 + 1], segmentTree[i * 2 + 2]);
  }

 public:
  SegmentTree(vector<int>& nums, bool isMinTree) {
    int n = nums.size();
    this->isMinTree = isMinTree;
    this->segmentTree.resize(4 * n);
    buildSegmentTree(0, 0, n - 1, nums);
  }

  int query(int start, int end, int i, int l, int r) {
    // No-Overlap
    if (l > end || r < start) return this->isMinTree ? INT_MAX : INT_MIN;

    // Complete OverLap
    if (l >= start && r <= end) return segmentTree[i];

    int mid = l + (r - l) / 2;

    int left = query(start, end, i * 2 + 1, l, mid);
    int right = query(start, end, i * 2 + 2, mid + 1, r);
    return this->isMinTree ? min(left, right) : max(left, right);
  }
};
class Solution36 {
 private:
  ll getValue(int l, int r, SegmentTree& minSegTree, SegmentTree& maxSegTree, int n) {
    int minEle = minSegTree.query(l, r, 0, 0, n - 1);
    int maxEle = maxSegTree.query(l, r, 0, 0, n - 1);
    return (ll)maxEle - minEle;
  }

 public:
  long long maxTotalValue(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<tuple<ll, int, int>> pq;

    SegmentTree minSegTree(nums, true), maxSegTree(nums, false);

    for (int l = 0; l < n; l++) {
      ll value = getValue(l, n - 1, minSegTree, maxSegTree, n);
      pq.push({value, l, n - 1});
    }

    ll result = 0;
    while (k--) {
      auto [val, l, r] = pq.top();
      result += val;
      pq.pop();
      if (l < r) {
        ll nextBestValue = getValue(l, r - 1, minSegTree, maxSegTree, n);
        pq.push({nextBestValue, l, r - 1});
      }
    }
    return result;
  }
};

// Binary Lifting

class Solution37 {
  int LOG = 20;
  vector<vector<int>> ancestorTable;
  vector<int> depthTable;

 private:
  void buildAncestorTable(vector<vector<int>>& adj, int node, int parent = -1) {
    ancestorTable[node][0] = parent;
    for (int j = 1; j < LOG; j++) {
      if (ancestorTable[ancestorTable[node][j - 1]][j - 1] != -1) {
        ancestorTable[node][j] = ancestorTable[ancestorTable[node][j - 1]][j - 1];
      }
    }
    for (int child : adj[node]) {
      if (child != parent) {
        depthTable[child] = depthTable[node] + 1;
        buildAncestorTable(adj, child, node);
      }
    }
  }

  int getLCA(int u, int v) {
    if (depthTable[u] < depthTable[v]) swap(u, v);

    int diff = depthTable[u] - depthTable[v];

    for (int i = 0; i < LOG; i++)
      if (diff & (1 << i)) {
        u = ancestorTable[u][i];
      }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
      if (ancestorTable[u] != ancestorTable[v]) {
        u = ancestorTable[u][i];
        v = ancestorTable[v][i];
      }
    }
    return ancestorTable[u][0];
  }

  int distanceBetweenNodes(int u, int v) {
    int lca = getLCA(u, v);

    int distance = depthTable[v] + depthTable[u] - 2 * depthTable[lca];
    return distance;
  }

  long binaryModularExponentiation(int n, int exp) {
    long result = 1;
    int MOD = 1e9 + 7;
    while (exp) {
      if (exp & 1) result = (result * n) % MOD;
      n = 1L * (n * n) % MOD;
      exp >>= 1;
    }
    return result;
  }

 public:
  vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    int n = edges.size() + 1;
    ancestorTable.assign(n, vector<int>(LOG));
    depthTable.assign(n, -1);
    vector<vector<int>> adj(n + 1);

    buildAncestorTable(adj, 1);
    vector<int> result;
    for (auto& query : queries) {
      int distance = distanceBetweenNodes(query[0], query[1]);
      result.push_back(binaryModularExponentiation(2, distance - 1));
    }
    return result;
  }
};

class Solution {
 public:
  string processStr(string s) {
    string result = "";
    for (char c : s) {
      if (c >= 'a' & c <= 'z') {
        result.push_back(c);
        continue;
      }
      if (result.empty()) continue;
      if (c == '*')
        result.pop_back();
      else if (c == '#')
        result += result;
      else if (c == '%')
        reverse(begin(result), end(result));
    }
    return result;
  }
};

class Solution {
  int dp[2001][2001][2];
  int K;
  const int MOD = 1e9 + 7;
  long recurse(int direction, int n, int prev) {
    if (n == 0) return 1;
    if (prev < 1 || prev > K) return 0;
    if (dp[n][prev][direction] != -1) {
      return dp[n][prev][direction];
    }
    long number_of_ways = 0;

    if (direction == 1 && prev + 1 <= K) {
      // Take this number
      number_of_ways = (number_of_ways + recurse(0, n - 1, prev + 1)) % MOD;
      number_of_ways = (number_of_ways + recurse(1, n, prev + 1)) % MOD;
    } else if (direction == 0 && prev - 1 >= 1) {
      number_of_ways = (number_of_ways + recurse(1, n - 1, prev - 1)) % MOD;
      number_of_ways = (number_of_ways + recurse(0, n, prev - 1)) % MOD;
    }

    return dp[n][prev][direction] = number_of_ways % MOD;
  };

 public:
  int zigZagArrays(int n, int l, int r) {
    K = r - l + 1;
    memset(dp, -1, sizeof dp);
    long total_ways = 0;

    for (int i = 1; i <= K; i++) {
      total_ways = (total_ways + recurse(1, n - 1, i)) % MOD;
      total_ways = (total_ways + recurse(0, n - 1, i)) % MOD;
    }

    return total_ways;
  }
};
class Solution {
  int K;
  const int MOD = 1e9 + 7;

 public:
  int zigZagArrays(int n, int l, int r) {
    K = r - l + 1;
    vector<long> upDP(K + 2, 0), downDP(K + 2, 0);

    for (int i = 1; i <= K; i++) {
      upDP[i] = 1;
      downDP[i] = 1;
    }
    long total_ways = 0;

    for (int len = 1; len < n; len++) {
      vector<long> currUpDP(K + 2), currDownDP(K + 2);
      // Direction 1
      for (int prev = K; prev >= 1; prev--) {
        long number_of_ways = 0;
        number_of_ways = (number_of_ways + currUpDP[prev + 1]) % MOD;
        number_of_ways = (number_of_ways + downDP[prev + 1]) % MOD;
        currUpDP[prev] = number_of_ways;
      }

      // Direction 0
      for (int prev = 1; prev <= K; prev++) {
        long number_of_ways = 0;
        number_of_ways = (number_of_ways + currDownDP[prev - 1]) % MOD;
        number_of_ways = (number_of_ways + upDP[prev - 1]) % MOD;
        currDownDP[prev] = number_of_ways;
      }
      upDP = currUpDP;
      downDP = currDownDP;
    }

    for (int i = 1; i <= K; i++) {
      total_ways = (total_ways + upDP[i] + downDP[i]) % MOD;
    }

    return total_ways;
  }
};

class Solution {
  int dp[2001][2001][2];

  const int MOD = 1e9 + 7;
  long recurse(int l, int r, int direction, int n, int prev) {
    if (n == 0) return 1;
    if (prev < l || prev > r) return 0;
    if (dp[n][prev][direction] != -1) {
      return dp[n][prev][direction];
    }
    long number_of_ways = 0;

    if (direction == 1 && prev <= r) {
      // Take this number
      number_of_ways = (number_of_ways + recurse(l, r, 0, n - 1, prev + 1)) % MOD;
      number_of_ways = (number_of_ways + recurse(l, r, 1, n, prev + 1)) % MOD;
    } else if (direction == 0 && prev - 1 >= l) {
      number_of_ways = (number_of_ways + recurse(l, r, 1, n - 1, prev - 1)) % MOD;
      number_of_ways = (number_of_ways + recurse(l, r, 0, n, prev - 1)) % MOD;
    }

    return dp[n][prev][direction] = number_of_ways % MOD;
  };

 public:
  int zigZagArrays(int n, int l, int r) {
    memset(dp, -1, sizeof dp);
    long total_ways = 0;

    for (int i = l; i <= r; i++) {
      total_ways = (total_ways + recurse(l, r, 1, n - 1, i)) % MOD;
      total_ways = (total_ways + recurse(l, r, 0, n - 1, i)) % MOD;
    }

    return total_ways;
  }
};

/**
 * LC: 3700. Number of ZigZag Arrays II
 */

class Solution {
  typedef vector<vector<long>> matrix;
  typedef long long ll;
  int MOD = 1e9 + 7;

  matrix multiply(matrix& A, matrix& B, int size) {
    matrix res(size, vector<long>(size, 0));
    for (int i = 0; i < size; i++) {
      for (int k = 0; k < size; k++) {
        if (A[i][k] == 0) continue;
        for (int j = 0; j < size; j++) {
          res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
        }
      }
    }
    return res;
  }

  matrix powerMatrix(matrix& base, long exp, int size) {
    matrix res(size, vector<long>(size, 0));

    for (int i = 0; i < size; i++) {
      res[i][i] = 1;
    }

    // Binary exponentiation
    while (exp > 0) {
      if (exp % 2 == 1) {
        res = multiply(res, base, size);
      }
      base = multiply(base, base, size);
      exp >>= 1;
    }
    return res;
  }

 public:
  int zigZagArrays(int n, int l, int r) {
    int k = r - l + 1;
    int states = k * 2;
    matrix T(states, vector<long>(states, 0));

    for (int val_u = 1; val_u <= k; val_u++) {
      for (int val_v = 1; val_v <= k; val_v++) {
        // Moving up
        if (val_u < val_v) {
          int u = val_u + k;
          int v = val_v;

          T[u][v] = 1;
        }  // Moving Down
        else if (val_u > val_v) {
          int u = val_u;
          int v = val_v + k;
          T[u][v] = 1;
        }

        // for val_u==val_v do nothing-->0
      }
    }

    // Power Transition matrix
    matrix M_pow = powerMatrix(T, n - 1, states);

    long total_ways = 0;

    for (int i = 0; i < states; i++)
      for (int j = 0; j < states; j++) {
        total_ways = (total_ways + M_pow[i][j]) % MOD;
      }
    return total_ways;
  }
};

class Solution {
 public:
  int countMajoritySubarrays(vector<int>& nums, int target) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      int count = 0;
      for (int j = i; j < nums.size(); j++) {
        if (nums[j] == target) count++;
        if ((j - i + 1) / 2 < count) res++;
      }
    }
    return res;
  }
};

class Solution {
  long long nCr(int n, int r, int k) {
    long long result = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++) {
      result = result * (n - r + i) / i;
      if (result >= k) return k;
    }
    return result;
  }

 public:
  string smallestPalindrome(string s, int k) {
    int n = s.size();
    string result = "";
    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;

    int middleChar = -1;
    for (int i = 0; i < 26; i++) {
      if (freq[i] & 1) middleChar = i;
      freq[i] /= 2;
    }

    for (int i = 0; i < n / 2; i++) {
      bool isCharPicked = false;
      for (int j = 0; j < 26; j++) {
        if (freq[j] > 0) {
          freq[j] -= 1;
          long long ways = 1;
          int letters = 0;
          for (int c = 0; c < 26; c++) letters += freq[c];

          for (int c = 0; c < 26; c++) {
            if (freq[c] > 0) {
              ways *= nCr(letters, freq[c], k);
              letters -= freq[c];
            }
            if (ways >= k) break;
          }
          if (ways >= k) {
            result.push_back(j + 'a');
            isCharPicked = true;
            break;
          }
          k -= ways;
          freq[j] += 1;
        }
      }
      if (!isCharPicked) {
        return "";
      }
    }

    string rev = result;
    reverse(begin(rev), end(rev));
    cout << result;
    if (middleChar != -1) {
      result += (middleChar + 'a');
    }
    return result + rev;
  }
};

class Solution {
 public:
  bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1, false);
    dp[1] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = sqrt(i); j >= 1; j--) {
        if (!dp[i - j * j]) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};

class Solution {
 public:
  bool kar98(int n, vector<int>& dp) {
    if (n <= 0) return false;
    if (dp[n] != -1) return dp[n];
    for (int i = sqrt(n); i >= 1; i--) {
      if (!(kar98(n - i * i, dp))) return dp[n] = 1;
    }
    return dp[n] = 0;
  }
  bool winnerSquareGame(int n) {
    vector<int> dp(n + 1, -1);
    return kar98(n, dp);
  }
};