/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-in-mountain-array/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int getPeak(MountainArray& mountainArr, int n) {
    int l = 1;
    int r = n - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      int pre = mountainArr.get(mid - 1);
      int val = mountainArr.get(mid);
      int nxt = mountainArr.get(mid + 1);
      if (pre < val && val > nxt) {
        return mid;
      }
      if (pre < val && val < nxt) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return -1;
  }
public:
  int findInMountainArray(int target, MountainArray& mountainArr) {
    const int n = mountainArr.length();

    int peak = getPeak(mountainArr, n);
    int l = 0;
    int r = peak;
    
    while (l < r) {
      int mid = (l + r) >> 1;
      int val = mountainArr.get(mid);
      if (val == target) {
        return mid;
      }
      if (val < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    l = peak;
    r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      int val = mountainArr.get(mid);
      if (val == target) {
        return mid;
      }
      if (val < target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return -1;
  }
};
