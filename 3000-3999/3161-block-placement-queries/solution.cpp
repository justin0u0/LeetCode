/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/block-placement-queries/
 * Runtime: 1125ms (5.94%)
 */

class Solution {
  #define N 50001
private:
  bool obs[N];
  int left[N << 2];
  int right[N << 2];
  int whole[N << 2];

  void pull(int l, int r, int mid, int o) {
    const auto lo = (o << 1);
    const auto ro = (o << 1) | 1;
    left[o] = left[lo];
    right[o] = right[ro];
    whole[o] = max(whole[lo], whole[ro]);
    if (!obs[mid]) {
      whole[o] = max(whole[o], right[lo] + left[ro]);
      if (whole[lo] == mid - l) {
        left[o] += left[ro];
      }
      if (whole[ro] == r - mid) {
        right[o] += right[lo];
      }
    }
  }

  void build(int l, int r, int o) {
    if (r - l <= 1) {
      left[o] = 1;
      right[o] = 1;
      whole[o] = 1;
      return;
    }

    const int mid = (l + r) >> 1;
    build(l, mid, o << 1);
    build(mid, r, (o << 1) | 1);
    pull(l, r, mid, o);
  }

  void update(int l, int r, int o, int pos) {
    if (r - l <= 1) {
      return;
    }

    const int mid = (l + r) >> 1;
    if (pos <= mid) {
      update(l, mid, (o << 1), pos);
    } else {
      update(mid, r, (o << 1) | 1, pos);
    }
    pull(l, r, mid, o);
  }

  tuple<int, int, int> query(int l, int r, int o, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return {left[o], right[o], whole[o]};
    }
    const int mid = (l + r) >> 1;

    if (qr <= mid) {
      return query(l, mid, (o << 1), ql, qr);
    }
    if (ql >= mid) {
      return query(mid, r, (o << 1) | 1, ql, qr);
    }

    const auto [ll, lr, lw] = query(l, mid, (o << 1), ql, qr);
    const auto [rl, rr, rw] = query(mid, r, (o << 1) | 1, ql, qr);
    if (obs[mid]) {
      return {ll, rr, max(lw, rw)};
    }
    return {
      lw == mid - l ? lw + rl : ll,
      rw == r - mid ? rw + lr : rr,
      max(max(lw, rw), lr + rl)
    };
  }
public:
  vector<bool> getResults(vector<vector<int>>& queries) {
    memset(obs, 0, sizeof(obs));
    build(0, N, 1);

    vector<bool> res;
    for (const auto& q : queries) {
      if (q[0] == 1) {
        obs[q[1]] = true;
        update(0, N, 1, q[1]);
        continue;
      }

      const int result = get<2>(query(0, N, 1, 0, q[1]));
      // println("x={}, sz={}, query={}", q[1], q[2], result);
      res.emplace_back(result >= q[2]);
    }

    return res;
  }
};
