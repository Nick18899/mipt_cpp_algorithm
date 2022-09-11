#include <iostream>

bool BinarySearch(const int* begin, const int* end, int target) {
  int left = 0;
  int right = end - begin;
  bool flag = false;
  int mid;
  while ((right - left > 1) && (!flag)) {
    mid = (left + right) / 2;
    if (begin[mid] == target) {
      flag = true;
    }
    if (begin[mid] > target) {
      right = mid;
    } else {
      left = mid;
    }
  }
  if (begin[left] == target) {
    flag = true;
  }
  return flag;
}

int main() {
  int n, x, z, m;
  std::cin >> n;
  int* array_of_numbers = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    array_of_numbers[i] = x;
  }
  std::cin >> m;
  int** array_of_commands = new int*[m];
  for (int i = 0; i < m; ++i) {
    array_of_commands[i] = new int[3];
    std::cin >> n >> x >> z;
    array_of_commands[i][0] = n;
    array_of_commands[i][1] = x;
    array_of_commands[i][2] = z;
  }
  for (int i = 0; i < m; ++i) {
    if (BinarySearch(&array_of_numbers[array_of_commands[i][0]],
                     &array_of_numbers[array_of_commands[i][1]],
                     array_of_commands[i][2])) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
    delete[] array_of_commands[i];
  }
  delete[] array_of_numbers;
  delete[] array_of_commands;
  return 0;
}
