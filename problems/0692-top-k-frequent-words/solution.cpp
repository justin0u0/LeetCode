/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/top-k-frequent-words/
 * Runtime: 15ms (85.73%)
 */

class Solution {
private:
  class Data {
  public:
    string key;
    int value;

    bool operator < (const Data& rhs) const {
      if (value == rhs.value) {
        return key < rhs.key;
      }
      return value > rhs.value;
    }
  };
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> m;
    for (const string& word : words) {
      m[word]++;
    }

    priority_queue<Data> pq;
    for (const auto& it : m) {
      pq.push(Data{it.first, it.second});
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<string> answer;
    answer.reserve(k);
    while (!pq.empty()) {
      const Data& d = pq.top();
      answer.emplace_back(d.key);
      pq.pop();
    }

    reverse(answer.begin(), answer.end());
    return answer;
  }
};
