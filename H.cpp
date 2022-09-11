#include <iostream>

#include <cmath>

#include <iomanip>

void PrintOfRes(std::pair<int, int>* array_of_requests,
                long double* array_of_mandrag, int i, int n) {
  std::cout << std::setprecision(7)
            << pow(array_of_mandrag[array_of_requests[i].second],
                   (long double)n /
                       (long double)(array_of_requests[i].second + 1))
            << std::endl;
}

void PrintOfRes2(std::pair<int, int>* array_of_requests,
                 const long double* array_of_mandrag, int i, int n) {
  std::cout << std::setprecision(7)
            << pow(array_of_mandrag[array_of_requests[i].second] /
                       array_of_mandrag[array_of_requests[i].first - 1],
                   (long double)n /
                       (long double)(array_of_requests[i].second -
                                     array_of_requests[i].first + 1))
            << std::endl;
}

int main() {
  int n, firstindex, lastindex, m;
  std::cin >> n;
  long double u;
  long double* array_of_mandrag = new long double[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> u;
    if (i > 0) {
      array_of_mandrag[i] = pow(u, 1.0 / (double)n) * array_of_mandrag[i - 1];
    } else {
      array_of_mandrag[i] = pow(u, 1.0 / (double)n);
    }
  }
  std::cin >> m;
  std::pair<int, int>* array_of_requests = new std::pair<int, int>[m];
  for (int i = 0; i < m; ++i) {
    std::cin >> firstindex >> lastindex;
    array_of_requests[i].first = firstindex;
    array_of_requests[i].second = lastindex;
  }
  for (int i = 0; i < m; ++i) {
    if (array_of_requests[i].first != 0) {
      PrintOfRes2(array_of_requests, array_of_mandrag, i, n);
    } else {
      PrintOfRes(array_of_requests, array_of_mandrag, i, n);
    }
  }
  delete[] array_of_mandrag;
  delete[] array_of_requests;
  return 0;
}
