/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/car-pooling/
 * Runtime: 3ms
 * Description: Line Sweep
 */

class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<pair<int, int>> changes;
    changes.resize(trips.size() * 2);

    for (vector<int>& trip : trips) {
      changes.push_back({trip[1], trip[0]});
      changes.push_back({trip[2], -trip[0]});
    }
    sort(changes.begin(), changes.end());

    int total = 0;
    for (pair<int, int> change : changes) {
      total += change.second;
      if (total > capacity) {
        return false;
      }
    }
    
    return true;
  }
};

