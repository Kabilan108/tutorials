#include <iostream>

int main() {
  std::cout << "enter three numbers: ";

  int x{};
  int y{};
  int z{};
  std::cin >> x >> y >> z;

  std::cout << "you entered " << x << ", " << y << ", " << z << ".\n";
}
