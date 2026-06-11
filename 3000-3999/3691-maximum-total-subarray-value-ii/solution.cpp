/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-total-subarray-value-ii/
 * Runtime: 372ms (77.27%)
 */

class Solution {
private:
  class SegTree {
  private:
    const vector<int>& nums;
    vector<int> maxv;
    vector<int> minv;
  public:
    SegTree(const vector<int>& nums) : nums(nums),
      maxv(nums.size() << 2),
      minv(nums.size() << 2) {}
  
    void build(int l, int r, int o) {
      if (l == r) {
        maxv[o] = nums[l];
        minv[o] = nums[l];
        return;
      }
  
      const int mid = (l + r) >> 1;
      build(l, mid, o << 1);
      build(mid + 1, r, o << 1 | 1);
      maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
      minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
    }
  
    pair<int, int> query(int l, int r, int o, int ql, int qr) {
      if (ql <= l && r <= qr) {
        return {maxv[o], minv[o]};
      }
  
      const int mid = (l + r) >> 1;
      pair<int, int> res{INT_MIN, INT_MAX};
  
      if (ql <= mid) {
        auto [qmax, qmin] = query(l, mid, o << 1, ql, qr);
        res.first = max(res.first, qmax);
        res.second = min(res.second, qmin);
      }
      if (qr > mid) {
        auto [qmax, qmin] = query(mid + 1, r, o << 1 | 1, ql, qr);
        res.first = max(res.first, qmax);
        res.second = min(res.second, qmin);
      }
  
      return res;
    }
  };

  struct Node {
    int v;
    int l;
    int r;
  
    bool operator<(const Node& rhs) const {
      return v < rhs.v;
    }
  };
public:
  long long maxTotalValue(const vector<int>& nums, int k) {
    const int n = nums.size();

    SegTree t(nums);
    t.build(0, n - 1, 1);

    auto build = [&](int l, int r) -> Node {
      auto [maxv, minv] = t.query(0, n - 1, 1, l, r);
      return {maxv - minv, l, r};
    };

    priority_queue<Node> pq;
    for (int i = 0; i < n; ++i) {
      pq.push(build(i, n - 1));
    }

    long long sum = 0;
    while (k--) {
      const auto [v, l, r] = pq.top();
      pq.pop();
      sum += v;

      if (l < r) {
        pq.push(build(l, r - 1));
      }
    }

    return sum;
  }
};
