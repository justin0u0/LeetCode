/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/majority-element-ii/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> majorityElement(const vector<int>& nums) {
    int n1 = INT_MAX, c1 = 0;
    int n2 = INT_MAX, c2 = 0;
    for (const int num : nums) {
      if (num == n1) {
        ++c1;
      } else if (num == n2) {
        ++c2;
      } else if (c1 == 0) {
        n1 = num;
        c1 = 1;
      } else if (c2 == 0) {
        n2 = num;
        c2 = 1;
      } else {
        --c1;
        --c2;
      }
    }

    c1 = 0;
    c2 = 0;
    for (const int num : nums) {
      if (num == n1) {
        ++c1;
      } else if (num == n2) {
        ++c2;
      }
    }

    vector<int> answer;
    int n = nums.size() / 3;
    if (c1 > n) {
      answer.emplace_back(n1);
    }
    if (c2 > n) {
      answer.emplace_back(n2);
    }
    return answer;
  }
};
