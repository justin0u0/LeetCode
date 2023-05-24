/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-subsequence-score/
 * Runtime: 221ms (99.26%)
 */

const static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<pair<int, int>> box(n);
    for (int i = 0; i < n; ++i) {
      box[i] = {nums2[i], nums1[i]};
    }
    sort(box.begin(), box.end(), greater<pair<int, int>>());

    long long sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
      sum += box[i].second;
      pq.push(box[i].second);
      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }

      if (i + 1 >= k) {
        answer = max(answer, sum * box[i].first);
      }
    }
    return answer;
  }
};
