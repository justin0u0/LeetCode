/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/cinema-seat-allocation/
 * Runtime: 11ms (95.27%)
 */

class Solution {
public:
  int maxNumberOfFamilies(const int n, const vector<vector<int>>& reservedSeats) {
    const bitset<8> g1("11110000");
    const bitset<8> g2("00111100");
    const bitset<8> g3("00001111");

    unordered_map<int, bitset<8>> seats;
    for (const auto& seat : reservedSeats) {
      if (seat[1] >= 2 && seat[1] < 10) {
        seats[seat[0]].set(seat[1] - 2);
      }
    }

    int total = n * 2;
    for (const auto [row, seat] : seats) {
      if ((seat & g1) == 0 || (seat & g2) == 0 || (seat & g3) == 0) {
        total -= 1;
      } else {
        total -= 2;
      }
    }
    return total;
  }
};
