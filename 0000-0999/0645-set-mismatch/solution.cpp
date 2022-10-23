/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/set-mismatch/
 * Runtime: 35ms (90.78%)
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * Description:
 *  Suppose we change a -> b:
 *  1. Let X = 1 + 2 + ... + n = n * (n + 1) / 2
 *  2. So X - sum(nums) = a - b
 *  3. Let Y = 1^2 + 2^2 + ... + n^2 = n * (n + 1) * (2n + 1) / 6
 *  4. So Y - sum(square of nums) = a^2 - b^2 = (a + b)(a - b)
 *
 *  Let x = (a - b), y = (a + b)(a - b), we get:
 *  1. a = (y / x + x) / 2
 *  2. b = (y / x - x) / 2
 */
class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();

    long long X = n * (n + 1) / 2;
    long long Y = 1LL * n * (n + 1) * (2 * n + 1) / 6;
    for (const int val : nums) {
      X -= val;
      Y -= val * val;
    }

    int a = (Y / X + X) / 2;
    int b = (Y / X - X) / 2;
    return vector<int>{b, a};
  }
};
