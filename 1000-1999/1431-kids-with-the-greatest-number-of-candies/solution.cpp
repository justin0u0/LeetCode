/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int greatest = *max_element(candies.begin(), candies.end());    
    vector<bool> answer(candies.size(), false);
    for (int i = 0; i < candies.size(); ++i) {
      if (candies[i] + extraCandies >= greatest) {
        answer[i] = true;
      }
    }
    return answer;
  }
};
