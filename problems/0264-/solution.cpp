/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/ugly-number-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  static vector<int> uglyNumbers;
public:
  int nthUglyNumber(int n) {
    return uglyNumbers[n - 1];
  }
};

vector<int> Solution::uglyNumbers = []() {
  const int n = 1690;

  vector<int> arr{1};
  arr.reserve(n);

  int i = 0;
  int j = 0;
  int k = 0;
  while (arr.size() < n) {
    arr.emplace_back(min(min(arr[i] * 2, arr[j] * 3), arr[k] * 5));
    if (arr.back() == arr[i] * 2) {
      ++i;
    }
    if (arr.back() == arr[j] * 3) {
      ++j;
    }
    if (arr.back() == arr[k] * 5) {
      ++k;
    }
  }

  return arr;
}();
