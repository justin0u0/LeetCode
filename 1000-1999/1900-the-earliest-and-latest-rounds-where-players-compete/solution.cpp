/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/
 * Runtime: 2311ms (6.25%)
 */

class Solution {
public:
  vector<int> earliestAndLatest(int n, int fp, int sp) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      arr[i] = i + 1;
    }

    int ear = INT_MAX;
    int lat = INT_MIN;
    function<void(vector<int>, int)> dfs = [&](vector<int> arr, int r) {
      const int m = arr.size();
      if (m == 1) {
        return;
      }

      int f = 0;
      int s = 0;
      for (int i = 0; i < m; ++i) {
        if (arr[i] == fp) {
          f = i;
        } else if (arr[i] == sp) {
          s = i;
        }
      }

      if (f + s + 1 == m) {
        ear = min(ear, r);
        lat = max(lat, r);
        return;
      }

      for (int i = 0; i < (1 << (m / 2)); ++i) {
        bool fok = ((m & 1) != 0) && (f == m / 2);
        bool sok = ((m & 1) != 0) && (s == m / 2);
        if (!fok && f < m / 2 && (i & (1 << f)) != 0) {
          continue;
        }
        if (!fok && f >= m / 2 && (i & (1 << (m - f - 1))) == 0) {
          continue;
        }
        if (!sok && s < m / 2 && (i & (1 << s)) != 0) {
          continue;
        }
        if (!sok && s >= m / 2 && (i & (1 << (m - s - 1))) == 0) {
          continue;
        }

        vector<int> copy = arr;
        for (int j = 0; j < m / 2; ++j) {
          if (i & (1 << j)) {
            arr[j] = 0;
          } else {
            arr[m - j - 1] = 0;
          }
        }

        int k = 0;
        for (int j = 0; j < m; ++j) {
          if (arr[j] != 0) {
            arr[k++] = arr[j];
          }
        }
        arr.resize(k);
        dfs(arr, r + 1);

        arr = copy;
      }
    };
    dfs(arr, 1);

    return {ear, lat};
  }
};
