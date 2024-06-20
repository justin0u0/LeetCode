/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/magnetic-force-between-two-balls/
 * Runtime: 82ms (99.25%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  bool ok(const vector<int>& arr, const int dist, int target) {
    int last = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] - last >= dist) {
        last = arr[i];
        if (--target == 0) {
          return true;
        }
      }
    }
    return false;
  }
public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    const int n = position.size();
    int l = 0;
    int r = 1e9;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (ok(position, mid, m - 1)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l - 1;
  }
};
