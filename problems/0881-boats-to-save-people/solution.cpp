/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/boats-to-save-people/
 * Runtime: 91ms
 */

class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());

    int n = (int)people.size();
    int j = 0;
    int answer = 0;
    for (int i = n - 1; i >= j; --i) {
      if (people[i] + people[j] <= limit) {
        ++j;
      }
      ++answer;
    }

    return answer;
  }
};
