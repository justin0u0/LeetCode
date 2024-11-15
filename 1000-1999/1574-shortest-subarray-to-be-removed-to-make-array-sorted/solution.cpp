/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    const int n = arr.size();

    arr.emplace_back(-1);

    int l = 0;
    while (arr[l] <= arr[l + 1]) {
      ++l;
    }
    if (l + 1 == n) {
      return 0;
    }

    arr.back() = INT_MAX;
    int r = n;

    int answer = INT_MAX;
    for (; l >= 0; --l) {
      while (r > l && arr[r - 1] <= arr[r] && arr[r - 1] >= arr[l]) {
        --r;
      }
      answer = min(answer, r - l - 1);
    }

    while (r > 0 && arr[r - 1] <= arr[r]) {
      --r;
    }

    return min(answer, r);
  }
};
