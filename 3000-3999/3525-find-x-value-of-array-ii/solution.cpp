/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-x-value-of-array-ii/
 * Runtime: 1513ms (14.54%)
 */

class Solution {
private:
  class SegmentTree {
  private:
    int n;
    int k;
    // pre[o][i]: number of subarrays starting at the left endpoint of the
    //  interval o (i.e. o=[l, r], subarray=[l, ?]) whose product of elements
    //  has remainder i divided by k.
    //
    // pre[o][k]: product of elements of the interval o
    vector<vector<int>> pre;

    void make(int o, int val) {
      ranges::fill(pre[o], 0);
      val %= k;
      pre[o][k] = val;
      pre[o][val] = 1;
    }

    void mergePre(const vector<int>& left, const vector<int>& right, vector<int>& result) {
      result[k] = left[k] * right[k] % k;
      for (int i = 0; i < k; ++i) {
        result[i] = left[i];
      }
      for (int i = 0; i < k; ++i) {
        result[i * left[k] % k] += right[i];
      }
    }

    void pull(int o) {
      mergePre(pre[o << 1], pre[o << 1 | 1], pre[o]);
    }
  public:
    SegmentTree(int n, int k) : n(n), k(k), pre(n << 2, vector<int>(k + 1, 0)) {}

    void build(const vector<int>& nums, int l, int r, int o) {
      if (l == r) {
        make(o, nums[l]);
        return;
      }
      const int mid = (l + r) >> 1;
      build(nums, l, mid, o << 1);
      build(nums, mid + 1, r, o << 1 | 1);
      pull(o);
    }

    void update(int l, int r, int o, int pos, int val) {
      if (l == r) {
        make(o, val);
        return;
      }

      const int mid = (l + r) >> 1;
      if (pos <= mid) {
        update(l, mid, o << 1, pos, val);
      } else {
        update(mid + 1, r, o << 1 | 1, pos, val);
      }
      pull(o);
    }

    vector<int> query(int l, int r, int o, int ql, int qr) {
      if (ql <= l && r <= qr) {
        return pre[o];
      }

      const int mid = (l + r) >> 1;
      if (qr <= mid) {
        return query(l, mid, o << 1, ql, qr);
      }
      if (ql > mid) {
        return query(mid + 1, r, o << 1 | 1, ql, qr);
      }
      const auto left = query(l, mid, o << 1, ql, qr);
      const auto right = query(mid + 1, r, o << 1 | 1, ql, qr);
      vector<int> result(k + 1, 0);
      mergePre(left, right, result);
      return result;
    }
  };
public:
  vector<int> resultArray(const vector<int>& nums, const int k, const vector<vector<int>>& queries) {
    const int n = nums.size();

    SegmentTree st(n, k);
    st.build(nums, 0, n - 1, 1);

    vector<int> ans;
    ans.reserve(queries.size());
    for (const auto& query : queries) {
      st.update(0, n - 1, 1, query[0], query[1] % k);
      ans.emplace_back(st.query(0, n - 1, 1, query[2], n - 1)[query[3]]);
    }
    return ans;
  }
};
