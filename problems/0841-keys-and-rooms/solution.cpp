/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/keys-and-rooms/
 * Runtime: 12ms (81.17%)
 */

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> unlock(n, false);
    unlock[0] = true;
    int locks = n - 1;

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (const int& v : rooms[u]) {
        if (!unlock[v]) {
          unlock[v] = true;
          q.push(v);
          --locks;
        }
      }
    }

    return (locks == 0);
  }
};
