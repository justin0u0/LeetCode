/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-good-triplets-in-an-array/
 * Runtime: 23ms (83.03%)
 */

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

    void reset() {
      fill(arr.begin(), arr.end(), 0);
    }
  };
public:
  long long goodTriplets(const vector<int>& nums1, const vector<int>& nums2) {
    const int n = nums2.size();
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
      pos[nums2[i]] = i;
    }

    BIT tree(n + 1);

    vector<int> left(n);
    for (int i = 0; i < n; ++i) {
      const int p = pos[nums1[i]] + 1;
      left[i] = tree.sum(p);
      tree.add(p);
    }

    tree.reset();

    long long good = 0;
    for (int i = n - 1; i >= 0; --i) {
      const int p = pos[nums1[i]] + 1;
      const int right = (n - i - 1) - tree.sum(p);
      tree.add(p);
      good += 1LL * right * left[i];
    }
    return good;
  }
};
