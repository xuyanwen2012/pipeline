int k_CountUnique(unsigned int *keys, const int n) {
  if (n == 0) {
    return 0;
  }

  int j = 0;
  for (auto i = 1; i < n; ++i) {
    if (keys[i] != keys[j]) {
      ++j;
      keys[j] = keys[i];
    }
  }

  return j + 1;
}