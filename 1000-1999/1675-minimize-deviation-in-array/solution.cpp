/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimize-deviation-in-array/
 * Runtime: 188ms
 * Description:
 *  First, we change all odd number X -> X*2 to make all numbers even.
 *
 *  We can observe that all numbers X can turn to X, X/2, X/4 ... until
 *  it becomes an odd number. That is, X cannot become larger.
 *
 *  So if we want to get "minimum deviation", we need to decrease the
 *  maximum values we have, and keep track of the deviation with the
 *  numbers we have now.
 *
 *  Until the maximum number becomes an odd number, then we cannot improve
 *  the answer anynore.
 */

class Solution {
public:
  int minimumDeviation(vector<int>& nums) {
    int answer = 0x3f3f3f3f;
    int minVal = 0x3f3f3f3f;

    priority_queue<int> pq;
    for (int num : nums) {
      if (num & 1) {
        num <<= 1;
      }

      pq.push(num);
      minVal = min(minVal, num);
    }

    while (true) {
      answer = min(answer, pq.top() - minVal);

      int val = pq.top();
      if (val & 1) {
        break;
      }
      pq.pop();

      val >>= 1;
      minVal = min(minVal, val);
      pq.push(val);
    }

    return answer;
  }
};
