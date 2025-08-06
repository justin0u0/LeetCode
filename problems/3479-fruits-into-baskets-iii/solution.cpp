/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/fruits-into-baskets-iii/
 * Runtime: 440ms (30.64%)
 */

class Solution {
public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    const int n = fruits.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < baskets.size(); ++i) {
      arr[i] = {baskets[i], i};
    }
    sort(arr.begin(), arr.end());

    vector<int> indexer(n);
    for (int i = 0; i < n; ++i) {
      indexer[arr[i].second] = i;
    }

    vector<int> seg(n << 2, INT_MAX);

    function<void(int, int, int)> build = [&](int l, int r, int o) {
      if (l == r) {
        seg[o] = arr[l].second;
        return;
      }

      const int mid = (l + r) >> 1;
      build(l, mid, o << 1);
      build(mid + 1, r, (o << 1) + 1);
      seg[o] = min(seg[o << 1], seg[(o << 1) + 1]);
    };
    build(0, n - 1, 1);

    int ql;
    int qr;
    function<void(int, int, int)> update = [&](int l, int r, int o) {
      if (l == r) {
        seg[o] = INT_MAX;
        return;
      }
      
      const int mid = (l + r) >> 1;
      if (ql <= mid) {
        update(l, mid, o << 1);
      } else {
        update(mid + 1, r, (o << 1) + 1);
      }
      seg[o] = min(seg[o << 1], seg[(o << 1) + 1]);
    };
    
    function<int(int, int, int)> query = [&](int l, int r, int o) {
      if (ql <= l && r <= qr) {
        return seg[o];
      }

      const int mid = (l + r) >> 1;
      int res = INT_MAX;
      if (ql <= mid) {
        res = min(res, query(l, mid, o << 1));
      }
      if (qr > mid) {
        res = min(res, query(mid + 1, r, (o << 1) + 1));
      }
      return res;
    };

    int unplaced = 0;
    for (int f : fruits) {
      ql = lower_bound(arr.begin(), arr.end(), pair<int, int>{f, 0}) - arr.begin();
      qr = n - 1;

      const int q = query(0, n - 1, 1);
      if (q == INT_MAX) {
        ++unplaced;
      } else {
        ql = indexer[q];
        update(0, n - 1, 1);
      }
    }
    return unplaced;
  }
};
