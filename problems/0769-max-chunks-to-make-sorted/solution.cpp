/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/max-chunks-to-make-sorted/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxChunksToSorted(const vector<int>& arr) {
    const int n = arr.size();
    vector<int> line(n);
    for (int i = 0; i < n; ++i) {
      if (arr[i] >= i) {
        ++line[i];
        --line[arr[i]];
      } else {
        ++line[arr[i]];
        --line[i];
      }
    }

    int chunks = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += line[i];
      if (sum == 0) {
        ++chunks;
      }
    }
    return chunks;
  }
};
