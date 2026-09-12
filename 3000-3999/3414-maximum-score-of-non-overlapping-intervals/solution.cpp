/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/
 * Runtime: 857ms (55.43%)
 */

class Solution {
private:
  class Intv {
  public:
    int w;
    int id;

    Intv() : w(0), id(INT_MAX) {}
    Intv(int w, int id) : w(w), id(id) {}

    bool operator<(const Intv& rhs) const {
      return w < rhs.w || (w == rhs.w && id > rhs.id);
    }
  };

  class IntvPair {
  public:
    int w;
    vector<int> ids;

    IntvPair() : w(0), ids(2, INT_MAX) {}

    IntvPair(Intv i1, Intv i2) : w(i1.w + i2.w), ids{i1.id, i2.id} {}

    bool operator<(const IntvPair& rhs) const {
      return w < rhs.w || (w == rhs.w && ids > rhs.ids);
    }
  };

  class SegmentTree {
  private:
    int n;
    vector<Intv> maxv;

    void add(int l, int r, int o, int pos, Intv intv) {
      if (l == r) {
        maxv[o] = max(maxv[o], intv);
        return;
      }

      const int mid = (l + r) >> 1;
      if (pos <= mid) {
        add(l, mid, o << 1, pos, intv);
      } else {
        add(mid + 1, r, o << 1 | 1, pos, intv);
      }
      maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
    }

    Intv query(int l, int r, int o, int ql, int qr) {
      if (ql <= l && r <= qr) {
        return maxv[o];
      }
      
      const int mid = (l + r) >> 1;
      Intv res;
      if (ql <= mid) {
        res = max(res, query(l, mid, o << 1, ql, qr));
      }
      if (qr > mid) {
        res = max(res, query(mid + 1, r, o << 1 | 1, ql, qr));
      }
      return res;
    }
  public:
    SegmentTree(int n) : n(n), maxv(n << 2) {}

    void add(int pos, Intv w) {
      return add(0, n - 1, 1, pos, w);
    }

    Intv query(int ql, int qr) {
      if (ql > qr) {
        return Intv();
      }
      return query(0, n - 1, 1, ql, qr);
    }

    void clear() {
      ranges::fill(maxv, Intv());
    }
  };
public:
  vector<int> maximumWeight(vector<vector<int>>& intervals) {
    const int n = intervals.size();

    vector<int> points;
    points.reserve(n << 1);

    for (int i = 0; i < n; ++i) {
      auto& intv = intervals[i];
      points.emplace_back(intv[0]);
      points.emplace_back(intv[1]);
      intv.emplace_back(i);
    }
    ranges::sort(points);
    auto [first, last] = ranges::unique(points);
    points.erase(first, last);

    const int m = points.size();

    SegmentTree sg(m + 1);
    IntvPair best;

    vector<IntvPair> left(m);
    int j = 0;

    ranges::sort(intervals, {}, [](const auto& intv) {
      return intv[1];
    });

    for (int i = 0; i < m; ++i) {
      while (j < n && intervals[j][1] <= points[i]) {
        const auto& intv = intervals[j];
        Intv curr(intv[2], intv[3]);
  
        const auto l = ranges::lower_bound(points, intv[0]) - points.begin();
        const auto r = ranges::lower_bound(points, intv[1]) - points.begin();
  
        auto q = sg.query(0, l - 1);
        best = max(best, IntvPair(sg.query(0, l - 1), curr));
        sg.add(r, curr);

        ++j;
      }

      left[i] = best;
    }

    best = IntvPair();
    sg.clear();
    j = n - 1;
    ranges::sort(intervals, less<int>(), [](const auto& intv) {
      return intv[0];
    });

    vector<int> ans;
    unsigned int maxw = 0;

    for (int i = m - 1; i >= 0; --i) {
      while (j >= 0 && intervals[j][0] > points[i]) {
        const auto& intv = intervals[j];
        Intv curr(intv[2], intv[3]);

        const auto l = ranges::lower_bound(points, intv[0]) - points.begin();
        const auto r = ranges::lower_bound(points, intv[1]) - points.begin();

        best = max(best, IntvPair(curr, sg.query(r + 1, m - 1)));
        sg.add(l, curr);

        --j;
      }

      const unsigned int w = (unsigned int)left[i].w + best.w;
      vector<int> ids{left[i].ids[0], left[i].ids[1], best.ids[0], best.ids[1]};
      ranges::sort(ids);
      if (w > maxw) {
        maxw = w;
        ans = ids;
      } else if (w == maxw && ans > ids) {
        ans = ids;
      }
    }

    erase(ans, INT_MAX);
    if (ans.empty()) {
      return {0};
    }

    return ans;
  }
};
