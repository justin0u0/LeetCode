/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 * Time Complexity: O(N)
 */
class Solution {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int box[60] = {0};
   
    int answer = 0;
    for (int& val : time) {
      int mod = val % 60;

      answer += box[(60 - mod) % 60];
      ++box[mod];
    }
    
    return answer;
  }
};

