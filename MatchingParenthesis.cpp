#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
char st[MAXN];
int top = -1;

bool isEmpty() { return top == -1; }

bool isFull() { return top == MAXN - 1; }

void push(char x) {
  if (!isFull())
    st[++top] = x;
}

int pop() {
  if (isEmpty())
    return -1;
  return st[top--];
}

bool isValid(string s) {
  for (char c : s) {
    if (c == '(' || c == '{' || c == '[') {
      push(c);
    } else {
      int t = pop();
      if (t == -1)
        return false;

      if ((c == ')' && t != '(') || (c == '}' && t != '{') ||
          (c == ']' && t != '['))
        return false;
    }
  }
  return isEmpty();
}

int main() {
  string expr;
  cin >> expr;

  if (isValid(expr))
    cout << "Valid parentheses!\n";
  else
    cout << "Invalid parentheses!\n";

  return 0;
}
