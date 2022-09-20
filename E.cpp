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

void Clear(Stack* st);
Stack* Push(int pushing_number, Stack* st) {
  if (st == nullptr) {
    st = new Stack(pushing_number);
  } else {
    Stack* st_new = st;
    st = new Stack(pushing_number, st_new);
    Clear(st_new);
  }
  return st;
}

Stack* PopFromStack(Stack* st) {
  Stack* st_new = st->next_in_stack;
  delete st;
  return st_new;
}

void Pop(Stack*& st1, Stack*& st2) {
  if (st1 != nullptr) {
    if (st2 == nullptr) {
      while (st1 != nullptr) {
        int value_from_st1 = st1->curr_value;
        st1 = PopFromStack(st1);
        st2 = Push(value_from_st1, st2);
      }
    }
    std::cout << st2->curr_value << std::endl;
    st2 = st2->next_in_stack;
  } else if (st2 != nullptr) {
    std::cout << st2->curr_value << std::endl;
    st2 = st2->next_in_stack;
  } else {
    std::cout << "error" << std::endl;
  }
}

void Back(Stack*& st1, Stack*& st2) {
  if (st1 != nullptr) {
    if (st2 == nullptr) {
      while (st1 != nullptr) {
        int value_from_st1 = st1->curr_value;
        st1 = PopFromStack(st1);
        st2 = Push(value_from_st1, st2);
      }
    }
    std::cout << st2->curr_value << std::endl;
  } else {
    std::cout << "error" << std::endl;
  }
}

void Min(Stack* st1, Stack* st2) {
  if (st1 != nullptr && st2 != nullptr) {
    std::cout << std::min(st1->min_in_stack, st2->min_in_stack) << std::endl;
  } else if (st1 != nullptr) {
    std::cout << st1->min_in_stack << std::endl;
  } else if (st2 != nullptr) {
    std::cout << st2->min_in_stack << std::endl;
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

void ReadFromConsole(const char* cmd, Stack*& st1, Stack*& st2) {
  switch (cmd[0]) {
    case 'm':
      Min(st1, st2);
      break;
    case 's':
      Size(st1);
      break;
    case 'c':
      Clear(st1);
      st1 = nullptr;
      std::cout << "ok" << std::endl;
      break;
    case 'f':
      Back(st1, st2);
      break;
    case 'd':
      Pop(st1, st2);
      break;
    case 'e':
      int pushing_number;
      std::cin >> pushing_number;
      st1 = Push(pushing_number, st1);
      std::cout << "ok" << std::endl;
      break;
    default:
      break;
  }
}

int main() {
  int m;
  Stack* st1 = NULL;
  Stack* st2 = NULL;
  std::cin >> m;
  char str[9];
  for (int i = 0; i < m; ++i) {
    std::cin >> str;
    ReadFromConsole(str, st1, st2);
  }
  Clear(st1);
  Clear(st2);
  return 0;
}
