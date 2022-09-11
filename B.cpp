#include <iostream>

int main() {
  int n, u;
  std::cin >> n;
  int* array_of_sdvig = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> u;
    array_of_sdvig[i] = u;
  }
  int left = 0;
  int right = n - 1;
  if (array_of_sdvig[left] < array_of_sdvig[right]) {
    std::cout << 0;
  } else {
    while (right - left > 1) {
      u = (right + left) / 2;
      if (array_of_sdvig[u] > array_of_sdvig[left]) {
        left = u;
      } else {
        right = u;
      }
    }
    std::cout << right;
  }
  delete[] array_of_sdvig;
  return 0;
}
