#include <iostream>

#include <tuple>
#include <vector>

#include "matrix.h"

int main(int argc, char *argv[]) {
  std::cout << "Hello, World!\n";

  size_t x{10000}, y{10000};
  OtusHW::Matrix<int, -1> matrix;
  matrix[x][y] = 42;

  auto i = matrix[x];
  int k = i[1000];

  std::cout << x << y << matrix[x][y] << std::endl;
  x++;
  y++;
  std::cout << x << y << matrix[x][y] << std::endl;

  // std::vector<std::tuple<size_t, size_t, int>> v;

  // v.push_back(std::make_tuple(10000, 10000, 42));
  // v.push_back(std::make_tuple(1000, 1000, 12));

  // for (auto c : v)
  // {
  //   int x;
  //   int y;
  //   int v;
  //   std::tie(x, y, v) = c;
  //   std::cout << x << y << v << std::endl;
  // }

  return 0;
}
