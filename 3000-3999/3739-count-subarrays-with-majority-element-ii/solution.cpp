/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-subarrays-with-majority-element-ii/
 * Runtime: 27ms (72.18%)
 */

class Solution {
private:
  class Fenwick {
  private:
    const int n;
    vector<int> fw;
  public:
    Fenwick(const int n) : n(n), fw(n) {}

    void add(int x) {
      for (int i = x; i < n; i += (i & -i)) {
        ++fw[i];
      }
    }

    int sum(int x) {
      int res = 0;
      for (int i = x; i > 0; i -= (i & -i)) {
        res += fw[i];
      }
      return res;
    }
  };
public:
  long long countMajoritySubarrays(const vector<int>& nums, const int target) {
    const auto n = nums.size();

    vector<int> sum(n + 1, 0);
    vector<int> seq(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + (nums[i - 1] == target);
      seq[i] = 2 * sum[i] - i;
    }

    // find how many j with sum[i + 1] - sum[j] > (i - j + 1) / 2
    //  -> sum[j] < sum[i + 1] - (i - j + 1) / 2
    //  -> 2 * sum[j] < 2 * sum[i + 1] - (i - j + 1)
    //  -> 2 * sum[j] - j < 2 * sum[i + 1] - (i + 1)
    //
    // => Find ordered pair of sequence `2 * sum[i] - i`

    Fenwick fw(n * 3 + 1);
    long long res = 0;

    for (auto num : seq) {
      num += n + 1; // ensure positive

      res += fw.sum(num - 1);
      fw.add(num);
    }
    return res;
  }
};
