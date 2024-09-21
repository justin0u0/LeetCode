/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lexicographical-numbers/
 * Runtime: 3ms (94.22%)
 */

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> nums;
    
    function<void(int)> dfs = [&](int x) {
      int y = x * 10;
      for (int i = 0; i < 10; ++i) {
        if (y != 0 && y <= n) {
          nums.emplace_back(y);
          dfs(y);
        }
        ++y;
      }
    };
    dfs(0);
    
    return nums;
  }
};
