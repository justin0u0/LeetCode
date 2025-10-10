/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/
 * Runtime: 132ms (81.34%)
 */

class Solution {
public:
  int maximumEnergy(vector<int>& energy, int k) {
    for (int i = k; i < energy.size(); ++i) {
      if (energy[i - k] < 0) {
        continue;
      }
      energy[i] += energy[i - k];
    }
    return *max_element(energy.rbegin(), energy.rbegin() + k);
  }
};
