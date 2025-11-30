#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x) : data(x), next(nullptr) {}
};

class Queue {
private:
  Node *front;
  Node *back;

public:
  Queue() : front(nullptr), back(nullptr) {}

  void push_back(int x) {
    Node *newNode = new Node(x);
    if (back == nullptr) {
      front = back = newNode;
      return;
    }
    back->next = newNode;
    back = newNode;
  }

  void pop_front() {
    if (front == nullptr)
      return;
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
      back = nullptr;
    delete temp;
  }

  int front_val() { return front ? front->data : -1; }

  bool empty() { return front == nullptr; }

  bool isEmpty() { return empty(); }

  Node *get_front() { return front; }
  Node *get_back() { return back; }
};

class Stack {
private:
  Queue q1, q2;

public:
  void push(int x) { q1.push_back(x); }

  void pop() {
    // shift all items of q1 to q2
    while (!q1.isEmpty() && q1.get_front() != q1.get_back()) {
      q2.push_back(q1.front_val());
      q1.pop_front();
    }
    q1.pop_front();
    // swap q1 q2
    swap(q1, q2);
  }

  int top() { return q1.front_val() != -1 ? q1.front_val() : -1; }

  bool empty() { return q1.empty(); }
};

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode" << endl;
#endif

  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  cout << s.empty() << endl;

  return 0;
}
