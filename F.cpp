#include "cctype"

#include "iostream"

class Stack {
  int* arr_;
  int top_;
  int capacity_;

 public:
  Stack(int size = 10000);
  ~Stack();

  void Push(int x);
  int Pop();
  int Peek();

  int Size();
  bool IsEmpty();
  bool IsFull();
};

Stack::Stack(int size) {
  arr_ = new int[size];
  capacity_ = size;
  top_ = -1;
}

Stack::~Stack() { delete[] arr_; }

void Stack::Push(int x) {
  if (IsFull()) {
    exit(EXIT_FAILURE);
  }
  arr_[++top_] = x;
}

int Stack::Pop() {
  if (IsEmpty()) {
    exit(EXIT_FAILURE);
  }
  return arr_[top_--];
}

int Stack::Peek() {
  if (!IsEmpty()) {
    return arr_[top_];
  }
  exit(EXIT_FAILURE);
}

int Stack::Size() { return top_ + 1; }

bool Stack::IsEmpty() { return top_ == -1; }

bool Stack::IsFull() { return top_ == capacity_ - 1; }

void Pushing(Stack*& res, char s) {
  int b = res->Pop();
  int a = res->Pop();
  switch (s) {
    case '+':
      res->Push(b + a);
      break;
    case '-':
      res->Push(a - b);
      break;
    case '*':
      res->Push(b * a);
      break;
    case '/':
      res->Push(a / b);
      break;
  }
}

int main() {
  std::string s;
  std::getline(std::cin, s);
  Stack* res = new Stack();
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] != ' ') {
      if (std::isdigit(s[i]) == 0) {
        Pushing(res, s[i]);
      } else {
        res->Push(s[i] - '0');
      }
    }
  }
  std::cout << res->Pop();
  delete res;
  return 0;
}
