/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 * Runtime: 222ms (99.12%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  struct Pair {
    int i, j;
    int x, y;

    bool operator<(const Pair& rhs) const {
      return x + y > rhs.x + rhs.y;
    }
  };

  inline long long hash(long long i, int j) {
    return (i << 17) + j;
  }
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<Pair> pq;
    pq.push({0, 0, nums1[0], nums2[0]});

    unordered_set<long long> box;
    box.emplace(0);

    vector<vector<int>> answer;
    answer.reserve(k);
    for (int i = 0; i < k && !pq.empty(); ++i) {
      const Pair p = pq.top();
      pq.pop();

      answer.emplace_back(vector<int>{p.x, p.y});

      int nextI = p.i + 1;
      if (nextI < nums1.size()) {
        int h = hash(nextI, p.j);
        if (box.find(h) == box.end()) {
          box.emplace(h);
          pq.push({nextI, p.j, nums1[nextI], p.y});
        }
      }
      int nextJ = p.j + 1;
      if (nextJ < nums2.size()) {
        int h = hash(p.i, nextJ);
        if (box.find(h) == box.end()) {
          box.emplace(h);
          pq.push({p.i, nextJ, p.x, nums2[nextJ]});
        }
      }
    }

    return answer;
  }
};
