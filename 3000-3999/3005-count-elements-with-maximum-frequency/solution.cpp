/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-elements-with-maximum-frequency/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int freq[101];
public:
  int maxFrequencyElements(const vector<int>& nums) {
    memset(freq, 0, sizeof(freq));
    int maxFreq = 0;
    for (int num : nums) {
      maxFreq = max(maxFreq, ++freq[num]);
    }
    return count(freq, freq + 101, maxFreq) * maxFreq;
  }
};
