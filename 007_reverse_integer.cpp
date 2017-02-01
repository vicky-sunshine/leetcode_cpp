/* Copyright: vicky-sunshine */
#include <iostream>

class Solution {
public:
  int reverse(int x) {
    int r = 0, temp = 0;

    while (x) {
      temp = r * 10 + x % 10;
      if (temp / 10 != r) {
        return 0;
      }
      r = temp;
      x /= 10;
    }

    return r;
  }
};

int main() {
  Solution sol;

  int a = -12343000;
  std::cout << sol.reverse(a) << std::endl;

  int b = 1534236469;
  std::cout << sol.reverse(b) << std::endl;

  return 0;
}
