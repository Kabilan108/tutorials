#include <iostream>

// this prorgam produces a seg fault. why?
int main() {
  std::string x;
  std::string y;
  std::string z;
  std::cin >> x >> y >> z;
  std::cout << "you said " << x << '\n';
  std::cout << "she said " << y << '\n';
}

