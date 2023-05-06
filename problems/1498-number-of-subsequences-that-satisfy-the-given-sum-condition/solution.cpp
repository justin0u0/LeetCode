/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
 * Runtime: 105ms (98.80%)
 */

const int mod = 1e9 + 7;
int pow2[100001];

const static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pow2[0] = 1;
  for (int i = 1; i <= 100000; ++i) {
    pow2[i] = pow2[i - 1] << 1;
    if (pow2[i] >= mod) {
      pow2[i] -= mod;
    }
  }
  return nullptr;
}();

class Solution {
public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int i = 0;
    int j = nums.size() - 1;
    int answer = 0;
    while (i <= j) {
      if (nums[i] + nums[j] <= target) {
        answer += pow2[j - i];
        if (answer >= mod) {
          answer -= mod;
        }
        ++i;
      } else {
        --j;
      }
    }
    return answer;
  }
};
