/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-number-of-teams/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  class BIT {
  private:
    int n;
    vector<int> arr;
  public:
    BIT(int n) : n(n), arr(n, 0) {}

    void add(int x) {
      for (int i = x; i < n; i += (i & -i)) {
        ++arr[i];
      }
    }

    int sum(int x) {
      int res = 0;
      for (int i = x; i > 0; i -= (i & -i)) {
        res += arr[i];
      }
      return res;
    }
  };
public:
  int numTeams(vector<int>& rating) {
    const int n = rating.size();

    vector<int> sorted(rating.begin(), rating.end());
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; ++i) {
      rating[i] = lower_bound(sorted.begin(), sorted.end(), rating[i]) - sorted.begin() + 1;
    }

    // lc[j]: number of rating[i] with i < j && rating[i] < rating[j].
    vector<int> lc(n);
    BIT lb(n + 1);
    for (int i = 0; i < n; ++i) {
      lc[i] = lb.sum(rating[i] - 1);
      lb.add(rating[i]);
    }

    int answer = 0;
    BIT rb(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      // rc[j]: number of rating[k] with j < k && rating[j] > rating[k].
      // Note that we can save it as an vector for readability.
      int rc = rb.sum(rating[i] - 1);
      answer += lc[i] * (n - i - 1 - rc) + (i - lc[i]) * rc;
      rb.add(rating[i]);
    }
    return answer;
  }
};
