/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-sortable-integers/
 * Runtime: 183ms (38.97%)
 */

class Solution {
private:
  class SegmentTree {
  private:
    const vector<int>& nums;
    vector<int> segMin;
    vector<int> segMax;
  public:
    SegmentTree(const vector<int>& nums) : nums(nums), segMin(nums.size() << 2), segMax(nums.size() << 2) {}

    void build(int l, int r, int o) {
      if (l == r) {
        segMin[o] = nums[l];
        segMax[o] = nums[l];
        return;
      }
      const int mid = (l + r) >> 1;
      build(l, mid, o << 1);
      build(mid + 1, r, o << 1 | 1);
      segMin[o] = min(segMin[o << 1], segMin[o << 1 | 1]);
      segMax[o] = max(segMax[o << 1], segMax[o << 1 | 1]);
    }

    pair<int, int> query(int l, int r, int o, int ql, int qr) {
      if (ql <= l && r <= qr) {
        return {segMin[o], segMax[o]};
      }
      const int mid = (l + r) >> 1;
      pair<int, int> res = {INT_MAX, INT_MIN};
      if (ql <= mid) {
        const auto [mn, mx] = query(l, mid, o << 1, ql, qr);
        res.first = min(res.first, mn);
        res.second = max(res.second, mx);
      }
      if (qr > mid) {
        const auto [mn, mx] = query(mid + 1, r, o << 1 | 1, ql, qr);
        res.first = min(res.first, mn);
        res.second = max(res.second, mx);
      }
      return res;
    }
  };
public:
  int sortableIntegers(const vector<int>& nums) {
    const int n = nums.size();
    SegmentTree st(nums);
    st.build(0, n - 1, 1);

    auto check = [&](int l, int r) -> bool {
      const int m = r - l + 1;
      int cont = 0;
      int prev = INT_MIN;
      for (int j = 0; j < 2; ++j) {
        for (int i = l; i <= r; ++i) {
          if (nums[i] >= prev) {
            ++cont;
            if (cont >= m) {
              return true;
            }
          } else {
            cont = 1;
          }
          prev = nums[i];
        }
      }
      return false;
    };

    int res = 0;
    auto test = [&](int k) {
      int prevMax = INT_MIN;
      for (int i = 0; i < n / k; ++i) {
        const auto l = i * k;
        const auto r = l + k - 1;
        if (!check(l, r)) {
          return;
        }
        const auto [mn, mx] = st.query(0, n - 1, 1, l, r);
        if (mn < prevMax) {
          return;
        }
        prevMax = mx;
      }
      res += k;
    };

    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        test(i);
        if (n / i != i) {
          test(n / i);
        }
      }
    }
    return res;
  }
};
