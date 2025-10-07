#include <iostream>

int main() {
  int x = 5;
  if (x > 0) {
    std::cout << "positive\n";
  } else if (x == 0) {
    std::cout << "zero\n";
  } else {
    std::cout << "negative\n";
  }
  // inline else if in same line example
  if (x < 10) std::cout << "small\n"; else std::cout << "big\n";
  return 0;
}
