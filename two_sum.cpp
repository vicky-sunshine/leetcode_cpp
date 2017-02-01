/* Copyright: vicky-sunshine */
#include <iostream>
#include <unordered_map>
#include <vector>
// hash map, find in O(1)
// map, find in O(log(n))

class Solution {
public:
  // beats 33.53%
  std::vector<int> twoSumBruteForce(const std::vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {0, 0};
  }
  // beats 61.70%
  std::vector<int> twoSumTwoPass(const std::vector<int> &nums, int target) {
    std::unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
      hash.insert({nums[i], i});
    }
    for (int i = 0; i < nums.size(); i++) {
      int clmt = target - nums[i];
      auto search = hash.find(clmt);
      if (search != hash.end() && i != search->second) {
        return {i, search->second};
      }
    }
    return {0, 0};
  }
  // beats 89.38%
  std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
      int clmt = target - nums[i];
      auto search = hash.find(clmt);
      if (search != hash.end() && i != search->second) {
        return {i, search->second};
      }
      hash.insert({nums[i], i});
    }
    return {0, 0};
  }
};

int main() {
  // Create a vector containing integers
  std::vector<int> v = {2, 1, 9, 4, 4, 56, 90, 3};
  std::vector<int> r;
  int target = 8;

  Solution sol;
  r = sol.twoSum(v, target);
  std::cout << r[0] << ", " << r[1];

  return 0;
}
