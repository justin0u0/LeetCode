/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  static vector<int> numbers;
public:
  int punishmentNumber(int n) {
    int sum = 0;
    for (int num : numbers) {
      if (num <= n) {
        sum += num * num;
      } else {
        break;
      }
    }
    return sum;
  }
};

bool check(int num, int target) {
  if (num < target) {
    return false;
  }

  if (num == target) {
    return true;
  }

  for (int i = 10; i < num; i *= 10) {
    if (check(num / i, target - num % i)) {
      return true;
    }
  }

  return false;
}

vector<int> Solution::numbers = []() {
  vector<int> result;
  for (int i = 1; i <= 1000; ++i) {
    if (check(i * i, i)) {
      result.emplace_back(i);
    }
  }
  return result;
}();
