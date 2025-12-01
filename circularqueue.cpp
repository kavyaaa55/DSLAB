#include <bits/stdc++.h>
using namespace std;

const int SIZE = 5;
int cq[SIZE];
int front = -1, back = -1;

bool isFull() {
  return (front == 0 && back == SIZE - 1) || (back + 1 == front);
}

bool isEmpty() { return front == -1; }

void insertCQ(int x) {
  if (isFull()) {
    cout << "Queue full\n";
    return;
  }
  if (isEmpty()) {
    front = back = 0;
  } else {
    back = (back + 1) % SIZE;
  }
  cq[back] = x;
}

void deleteCQ() {
  if (isEmpty()) {
    cout << "Queue empty\n";
    return;
  }
  if (front == back) { // last element
    front = back = -1;
  } else {
    front = (front + 1) % SIZE;
  }
}

void displayCQ() {
  if (isEmpty()) {
    cout << "Queue empty\n";
    return;
  }
  int i = front;
  while (true) {
    cout << cq[i] << " ";
    if (i == back)
      break;
    i = (i + 1) % SIZE;
  }
  cout << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode\n";
#endif

  int ch;
  while (true) {
    cout << "\n1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
    cout << "Choice: ";
    cin >> ch;

    if (ch == 1) {
      int x;
      cout << "Value: ";
      cin >> x;
      insertCQ(x);
    } else if (ch == 2) {
      deleteCQ();
    } else if (ch == 3) {
      displayCQ();
    } else if (ch == 4) {
      break;
    } else {
      cout << "Invalid choice\n";
    }
  }
  return 0;
}

// // 1
// 1
// 10
// 1
// 20
// 1
// 30
// 3
// 4

// 1
// 10
// 1
// 20
// 1
// 30
// 1
// 40
// 1
// 50
// 3
// 1
// 60
// 4

