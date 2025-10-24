/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/next-greater-numerically-balanced-number/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  static vector<int> numbers;
public:
  int nextBeautifulNumber(int n) {
    return *upper_bound(numbers.begin(), numbers.end(), n);
  }
};

vector<int> Solution::numbers = []() {
  const int N = 1e6;

  vector<int> nums;
  for (int i = 1; ; ++i) {
    int cnt[10] = {0};
    for (int j = i; j != 0; j /= 10) {
      ++cnt[j % 10];
    }
    bool ok = true;
    for (int j = 0; ok && j < 10; ++j) {
      if (cnt[j] != 0 && cnt[j] != j) {
        ok = false;
      }
    }
    if (ok) {
      nums.emplace_back(i);
      if (i > N) {
        break;
      }
    }
  }
  return nums;
}();
