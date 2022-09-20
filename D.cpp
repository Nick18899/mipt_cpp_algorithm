#include <algorithm>

#include <iostream>

struct Stack {
 public:
  Stack* next_in_stack;
  int size_of_stack;
  int min_in_stack;
  int curr_value;
  Stack(int val) {
    curr_value = val;
    min_in_stack = curr_value;
    size_of_stack = 1;
    next_in_stack = nullptr;
  }

  Stack(int val, Stack* next) {
    curr_value = val;
    if (next->min_in_stack > val) {
      min_in_stack = val;
    } else {
      min_in_stack = next->min_in_stack;
    }
    size_of_stack = next->size_of_stack + 1;
    next_in_stack = next;
  }
};

Stack* Push(int pushing_number, Stack* st) {
  if (st == nullptr) {
    st = new Stack(pushing_number);
  } else {
    Stack* st_new = st;
    st = new Stack(pushing_number, st_new);
  }
  std::cout << "ok" << std::endl;
  return st;
}

Stack* Pop(Stack* st) {
  if (st != nullptr) {
    Stack* st_new = st->next_in_stack;
    std::cout << st->curr_value << std::endl;
    delete st;
    return st_new;
  }
  std::cout << "error" << std::endl;
  return nullptr;
}

void Back(Stack* st) {
  if (st != nullptr) {
    std::cout << st->curr_value << std::endl;
  } else {
    std::cout << "error" << std::endl;
  }
}

void Min(Stack* st) {
  if (st != nullptr) {
    std::cout << st->min_in_stack << std::endl;
  } else {
    std::cout << "error" << std::endl;
  }
}

void Size(Stack* st) {
  if (st != nullptr) {
    std::cout << st->size_of_stack << std::endl;
  } else {
    std::cout << "0" << std::endl;
  }
}

void Clear(Stack* st) {
  while (st != nullptr) {
    Stack* st_next = st->next_in_stack;
    delete st;
    st = st_next;
  }
}

void ReadFromConsole(const char* cmd, Stack*& st) {
  switch (cmd[0]) {
    case 'm':
      Min(st);
      break;
    case 's':
      Size(st);
      break;
    case 'c':
      Clear(st);
      st = nullptr;
      std::cout << "ok" << std::endl;
      break;
    case 'b':
      Back(st);
      break;
    case 'p':
      if (cmd[1] == 'o') {
        st = Pop(st);
      } else {
        int pushing_number;
        std::cin >> pushing_number;
        st = Push(pushing_number, st);
      }
      break;
    default:
      break;
  }
}

int main() {
  int m;
  Stack* st = NULL;
  std::cin >> m;
  char str[6];
  for (int i = 0; i < m; ++i) {
    std::cin >> str;
    ReadFromConsole(str, st);
  }
  Clear(st);
  return 0;
}
