#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target) {
  int start = 0, end = n - 1;
  while (start <= end) {
    // Here we find the mid element in the array.
    // int mid=(start+end)/2; // this is not a good method to find the middle
    // element because (start+end) can have a value greater then the max element
    // that it can store (Overflow occurs); Instead we should use
    int mid = start + (end - start) / 2;

    if (target < arr[mid])
      end = mid - 1;
    else if (target > arr[mid])
      start = mid + 1;
    else
      return mid;
  }
  return -1;
}
int main() {
  int arr[] = {1, 5, 8, 9, 14, 16, 19, 23, 56, 78, 89, 98, 100};
  int n = 13;
  int a = binarySearch(arr, n, 1236);
  if (a == -1)
    cout << "Element is not present.";
  else {
    cout << "The index of the element: " << a << endl;
  }
  return 0;
}

typedef long long ll;
typedef pair<ll, ll> P;

ll minimumCost(vector<int> &nums, int k, int dist) {
  int n = nums.size();
  set<P> kMin;
  set<P> remaining;

  ll sum = 0;
  int i = 0;
  while (dist - i < 1) {
    kMin.insert({nums[i], i});
    sum += nums[i];
    if (kMin.size() > k - 1) {
      P temp = *kMin.rbegin();
      sum -= temp.first;
      remaining.insert(temp);
      kMin.erase(temp);
    }
    i++;
  }

  ll result = sum;

  while (i < n) { //[10,8,18,9]
    kMin.insert({nums[i], i});
    sum += nums[i];
    if (kMin.size() > k - 1) {
      P temp = *kMin.rbegin();
      sum -= temp.first;
      remaining.insert(temp);
      kMin.erase(temp);
    }
    result = min(result, sum);

    // Shift window
    P remove = {nums[i - dist], i - dist};

    if (kMin.count(remove)) {
      kMin.erase(remove);
      sum -= remove.first;
      if (remaining.size() != 0) {
        P smallest = *remaining.cbegin();
        kMin.insert(smallest);
        sum += smallest.first;
        remaining.erase(smallest);
      }
    } else {
      remaining.erase(remove);
    }
    i++;
  }
  return nums[0] + result;
}

bool isTrionic(vector<int> &nums) {
  int n = nums.size();
  int i = 1;
  while (i < n && nums[i - 1] < nums[i])
    i++;

  int p = i - 1;

  while (i < n && nums[i - 1] > nums[i])
    i++;

  int q = i - 1;
  while (i < n && nums[i - 1] < nums[i])
    i++;

  int flag = i - 1;
  return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
}

static const long long INF = -1e15;
typedef long long ll;

long long maxSumTrionic(vector<int> &nums) {
  ll result = INF, a = INF, b = INF, c = INF;
  ll prev = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    ll na = INF, nb = INF, nc = INF;
    ll curr = nums[i];
    if (curr > prev) {
      na = max(a, prev) + curr;
      nc = max(b, c) + curr;
    } else if (curr < prev) {
      nb = max(a, b) + curr;
    }
    a = na, b = nb, c = nc;
    result = max(result, c);
    prev = curr;
  }
  return result;
}

vector<int> constructTransformedArray(vector<int> &nums) {
  vector<int> result(nums.size());
  int n = nums.size();
  /**Method:1 */
  // for (int i = 0; i < n; i++)
  // {
  //     if (nums[i] < 0)
  //     {
  //         int idx = (i + (nums[i] % n) + n) % n;
  //         result[i] = nums[idx];
  //     }
  //     else if (nums[i] > 0)
  //     {
  //         result[i] = nums[(i + nums[i]) % n];
  //     }
  //     else
  //     {
  //         result[i] = nums[i];
  //     }
  // }

  /**Method:2 */
  for (int i = 0; i < n; i++) {
    int j = (i + nums[i]) % n;
    result[i] = nums[j + (-(j < 0) & n)];
  }

  return result;
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution1 {
private:
  void getAllNodeValues(TreeNode *root, vector<int> &array) {
    if (!root)
      return;
    getAllNodeValues(root->left, array);
    array.push_back(root->val);
    getAllNodeValues(root->right, array);
  }

  TreeNode *build(int l, int r, vector<int> &array) {
    if (l < r)
      return NULL;
    int mid = l + (r - l) / 2;
    return new TreeNode(array[mid], build(l, mid - 1, array),
                        build(mid + 1, r, array));
  }

public:
  TreeNode *balanceBST(TreeNode *root) {
    vector<int> array;
    getAllNodeValues(root, array);
    return build(0, array.size() - 1, array);
  }
};

class Solution2 {

public:
  int longestBalanced(vector<int> &nums) {
    unordered_set<int> set;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      int odd = 0, even = 0;
      for (int j = 0; j < nums.size(); j++) {
        if (!set.count(nums[j])) {
          set.insert(nums[j]);
          odd += (nums[j] & 1);
          even += !(nums[j] & 1);
        }
        if (odd == even)
          ans = max(ans, j - i);
      }
      set.clear();
    }
    return ans;
  }
};

class Solution3 {
  vector<int> segMin, segMax, lazy;

  void propagate(int i, int l, int r) {
    if (lazy[i] != 0) {
      segMin[i] += lazy[i];
      segMax[i] += lazy[i];

      if (l != r) {
        lazy[i * 2 + 1] += lazy[i];
        lazy[i * 2 + 2] += lazy[i];
      }
      lazy[i] = 0;
    }
  }

  void updateRange(int start, int end, int i, int l, int r, int val) {
    propagate(i, l, r);
    if (l > end || r < start)
      return;
    if (l >= start && r <= end) {
      lazy[i] += val;
      propagate(i, l, r);
      return;
    }
    int mid = l + (r - l) / 2;
    updateRange(start, end, 2 * i + 1, l, mid, val);
    updateRange(start, end, 2 * i + 2, mid + 1, r, val);

    segMin[i] = min(segMin[2 * i + 1], segMin[2 * i + 2]);
    segMax[i] = max(segMax[2 * i + 1], segMax[2 * i + 2]);
  }

  int findLeftMostZero(int i, int l, int r) {
    propagate(i, l, r);

    if (segMax[i] < 0 || segMin[i] > 0)
      return -1;
    if (l == r)
      return l;
    int mid = l + (r - l) / 2;

    int leftRes = findLeftMostZero(2 * i + 1, l, mid);

    if (leftRes != -1)
      return leftRes;

    return findLeftMostZero(2 * i + 2, mid + 1, r);
  }

public:
  int longestBalanced(vector<int> &nums) {
    int n = nums.size();
    segMin.assign(4 * n, 0);
    segMax.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    vector<int> cumSum(nums.size(), 0);
    int maxL = 0;
    unordered_map<int, int> map;

    for (int r = 0; r < nums.size(); r++) {
      int val = (nums[r] % 2 == 0) ? -1 : 1;
      int prev = -1;
      if (map.count(nums[r]))
        prev = map[nums[r]];

      if (prev != -1)
        updateRange(0, prev, 0, 0, n - 1, -val);

      updateRange(0, r, 0, 0, n - 1, val);

      int l = findLeftMostZero(0, 0, n - 1);
      if (l != -1) {
        maxL = max(maxL, r - l + 1);
      }
      map[nums[r]] = r;
    }
    return maxL;
  }
};

class Solution4 {
private:
  bool check(vector<int> &freq) {
    int common = -1;
    for (int x = 0; x < 26; x++) {
      if (freq[x] == 0)
        continue;
      if (common == -1)
        common = freq[x];
      else if (common != freq[x])
        return false;
    }
    return true;
  }

public:
  int longestBalanced(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
      vector<int> freq(26, 0);
      for (int j = i; j < s.length(); j++) {
        freq[s[i] - 'a']++;
        if (check(freq)) {
          ans = max(ans, j - i + 1);
          break;
        }
      }
    }
    return ans;
  }
};

class Solution5 {
  int freq[1002][26] = {};

private:
  bool check(int j, int i) {
    int currFreq[26] = {0};
    for (int x = 0; x < 26; x++) {
      currFreq[x] = freq[i][x] - (j > 0 ? freq[j - 1][x] : 0);
    }

    int f = -1;
    for (int x = 0; x < 26; x++) {
      if (f == -1 && currFreq[x] != 0)
        f = currFreq[x];

      if (f != -1 && currFreq[x] != 0 && currFreq[x] != f)
        return false;
    }
    return true;
  }

public:
  int longestBalanced(string s) {
    int ans = 0;

    for (int i = 0; i < s.length(); i++) {
      if (i > 0)
        for (int c = 0; c < 26; c++)
          freq[i][c] = freq[i - 1][c];
      freq[i][s[i] - 'a']++;
    }

    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j <= i; j++)
        if (check(j, i)) {
          ans = max(ans, i - j + 1);
          break;
        }
    }
    return ans;
  }
};

class Solution6 {
private:
  int countSetBits(int n) {
    int cnt = 0;
    while (n) {
      cnt += (n & 1);
      n /= 2;
    }
    return cnt;
  }

public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;
    for (int hour = 0; hour < 12; hour++) {
      int bitsLeft = turnedOn - countSetBits(hour);
      string temp = to_string(hour);
      for (int minute = 0; minute < 60; minute++) {
        if (countSetBits(minute) != bitsLeft)
          continue;
        string t2 = temp + ":" + (minute > 9 ? "" : "0") + to_string(minute);
        ans.push_back(t2);
      }
    }
    return ans;
  }
};

class Solution7 {
public:
  bool hasAlternatingBits(int n) {
    bool flag = n & 1;
    n = n >> 1;
    while (n) {
      bool lastBit = n & 1;
      if (lastBit == flag)
        return false;
      flag = lastBit;
      n = n >> 1;
    }
    return true;
  }
};

class Solution {
public:

/**
 *Question: LC-696  
 * Count consecutive same bits and check for pairing 0001111 it can make 3 possible pairs
 */
  int countBinarySubstrings(string s) {
    int ans = 0, prev = 0, curr = 0;
    for (int i = 0; i < s.length(); i++) {
      if (i > 0 && s[i] == s[i - 1]) {
        curr++;
        continue;
      } else {
        ans += min(prev, curr);
        prev = curr;
        curr = 1;
      }
    }
    ans += min(prev, curr);
    return ans;
  }
};