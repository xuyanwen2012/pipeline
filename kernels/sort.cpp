#include <algorithm>
#include <execution>

void k_SortKeysInplace(unsigned int *keys, const int n) {
  std::sort(std::execution::par, keys, keys + n);
}