#include <bits/stdc++.h>
using namespace std;

struct Node {
  char data;
  Node *next;
  Node(char x) : data(x), next(nullptr) {}
};

class Stack {
private:
  Node *top;

public:
  Stack() : top(nullptr) {}

  void push(char x) {
    Node *newNode = new Node(x);
    newNode->next = top;
    top = newNode;
  }

  char pop() {
    if (top == nullptr)
      return '#'; // Invalid char
    char res = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return res;
  }

  char peek() { return top ? top->data : '#'; }

  bool empty() { return top == nullptr; }
};

bool isValid(string s) {
  Stack st;

  for (char c : s) {
    if (c == '(' || c == '{' || c == '[') {
      st.push(c);
    } else {
      if (st.empty())
        return false;

      char top = st.pop();

      if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
          (c == ']' && top != '[')) {
        return false;
      }
    }
  }

  return st.empty();
}

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode" << endl;
#endif

  string expr;
  cout << "Enter expression: ";
  cin >> expr;

  if (isValid(expr)) {
    cout << "Valid parentheses!" << endl;
  } else {
    cout << "Invalid parentheses!" << endl;
  }

  return 0;
}
