#include <algorithm>

#include <iostream>

bool CheckOfDistance(const long long inpmass[], long long current_l,
                     long long num_of_lumoses, long long n) {
  bool flag = false;
  long long first = inpmass[0];
  int count = 1;
  for (int j = 0; j < n; ++j) {
    if (inpmass[j] - first > current_l) {
      ++count;
      first = inpmass[j];
    }
  }
  if (count <= num_of_lumoses) {
    flag = true;
  }
  return flag;
}

int main() {
  long long n, mid, x;
  long long numoflumoses;
  std::cin >> n >> numoflumoses;
  long long* array_of_distances = new long long[n];
  for (long long i = 0; i < n; ++i) {
    std::cin >> x;
    array_of_distances[i] = x;
  }
  std::sort(array_of_distances, array_of_distances + n);
  long long left = 0;
  long long right = array_of_distances[n - 1] - array_of_distances[0];
  if (n == 1) {
    std::cout << 0;
  } else {
    while (left < right) {
      mid = (left + right) / 2;
      if (CheckOfDistance(array_of_distances, mid, numoflumoses, n)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    std::cout << left << std::endl;
  }
  delete[] array_of_distances;
  return 0;
}
