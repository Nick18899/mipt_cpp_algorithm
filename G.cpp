#include "iostream"

class Stack {
  char* arr_;
  int top_;
  int capacity_;

 public:
  Stack(int size = 10000);
  ~Stack();

  void Push(char x);
  int Pop();
  int Peek();

  int Size();
  bool IsEmpty();
  bool IsFull();
};

Stack::Stack(int size) {
  arr_ = new char[size];
  capacity_ = size;
  top_ = -1;
}

Stack::~Stack() { delete[] arr_; }

void Stack::Push(char x) {
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

bool CheckingOfLastBracket(Stack*& res, char s) {
  bool result = false;
  if (res->IsEmpty()) {
    result = false;
  } else {
    int current_opened_bracket = res->Pop();
    switch (current_opened_bracket) {
      case '{':
        if (s == '}') {
          result = true;
        }
        break;
      case '[':
        if (s == ']') {
          result = true;
        }
        break;
      case '(':
        if (s == ')') {
          result = true;
        }
        break;
      default:
        break;
    }
  }
  return result;
}

int main() {
  std::string s;
  std::getline(std::cin, s);
  bool flag = true;
  Stack* res = new Stack();
  for (int i = 0; i < s.size(); ++i) {
    if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
      res->Push(s[i]);
    } else {
      if (!CheckingOfLastBracket(res, s[i])) {
        flag = false;
        break;
      }
    }
  }
  if ((res->IsEmpty()) && (flag)) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  delete res;
  return 0;
}
