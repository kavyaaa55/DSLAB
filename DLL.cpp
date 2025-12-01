#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *prev, *next;
  Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node *head = nullptr;
Node *tail = nullptr;

// Insert from front
void insertFront(int x) {
  Node *newNode = new Node(x);
  if (head == nullptr) {
    head = tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// Insert from end
void insertEnd(int x) {
  Node *newNode = new Node(x);
  if (tail == nullptr) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

// Delete from front
void deleteFront() {
  if (head == nullptr) {
    cout << "List empty\n";
    return;
  }
  Node *temp = head;
  if (head == tail) {
    head = tail = nullptr;
  } else {
    head = head->next;
    head->prev = nullptr;
  }
  delete temp;
}

// Delete from end
void deleteEnd() {
  if (tail == nullptr) {
    cout << "List empty\n";
    return;
  }
  Node *temp = tail;
  if (head == tail) {
    head = tail = nullptr;
  } else {
    tail = tail->prev;
    tail->next = nullptr;
  }
  delete temp;
}

// Display list
void display() {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << "\n";
}

// Find nodes having even numbers (print them)
void findEvenNodes() {
  Node *temp = head;
  int pos = 1;
  bool any = false;
  while (temp != nullptr) {
    if (temp->data % 2 == 0) {
      cout << "Position " << pos << ": " << temp->data << "\n";
      any = true;
    }
    temp = temp->next;
    pos++;
  }
  if (!any)
    cout << "No even nodes\n";
}

// Swap first and last node (swap data)
void swapFirstLast() {
  if (head == nullptr || head == tail) {
    cout << "Cannot swap (0 or 1 node)\n";
    return;
  }
  int tmp = head->data;
  head->data = tail->data;
  tail->data = tmp;
}

// Delete nodes having even numbers
void deleteEvenNodes() {
  Node *cur = head;
  while (cur != nullptr) {
    Node *nxt = cur->next;
    if (cur->data % 2 == 0) {
      if (cur == head)
        head = cur->next;
      if (cur == tail)
        tail = cur->prev;
      if (cur->prev)
        cur->prev->next = cur->next;
      if (cur->next)
        cur->next->prev = cur->prev;
      delete cur;
    }
    cur = nxt;
  }
}

// Delete nodes having odd numbers
void deleteOddNodes() {
  Node *cur = head;
  while (cur != nullptr) {
    Node *nxt = cur->next;
    if (cur->data % 2 != 0) {
      if (cur == head)
        head = cur->next;
      if (cur == tail)
        tail = cur->prev;
      if (cur->prev)
        cur->prev->next = cur->next;
      if (cur->next)
        cur->next->prev = cur->prev;
      delete cur;
    }
    cur = nxt;
  }
}

// Delete nodes divisible by 3
void deleteDivBy3Nodes() {
  Node *cur = head;
  while (cur != nullptr) {
    Node *nxt = cur->next;
    if (cur->data % 3 == 0) {
      if (cur == head)
        head = cur->next;
      if (cur == tail)
        tail = cur->prev;
      if (cur->prev)
        cur->prev->next = cur->next;
      if (cur->next)
        cur->next->prev = cur->prev;
      delete cur;
    }
    cur = nxt;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode\n";
#endif

  int ch;
  while (true) {
    cout << "\n1. Insert from front\n";
    cout << "2. Insert from end\n";
    cout << "3. Delete from front\n";
    cout << "4. Delete from end\n";
    cout << "5. Display list\n";
    cout << "6. Find nodes having even numbers\n";
    cout << "7. Swap first and last node\n";
    cout << "8. Delete nodes having even numbers\n";
    cout << "9. Delete nodes having odd numbers\n";
    cout << "10. Delete nodes having numbers divisible by 3\n";
    cout << "11. Exit\n";
    cout << "Choice: ";
    cin >> ch;

    if (ch == 1) {
      int x;
      cout << "Value: ";
      cin >> x;
      insertFront(x);
    } else if (ch == 2) {
      int x;
      cout << "Value: ";
      cin >> x;
      insertEnd(x);
    } else if (ch == 3) {
      deleteFront();
    } else if (ch == 4) {
      deleteEnd();
    } else if (ch == 5) {
      display();
    } else if (ch == 6) {
      findEvenNodes();
    } else if (ch == 7) {
      swapFirstLast();
    } else if (ch == 8) {
      deleteEvenNodes();
    } else if (ch == 9) {
      deleteOddNodes();
    } else if (ch == 10) {
      deleteDivBy3Nodes();
    } else if (ch == 11) {
      break;
    } else {
      cout << "Invalid choice\n";
    }
  }

  return 0;
}


// 1
// 10
// 1
// 5
// 2
// 20
// 2
// 7
// 5
// 6
// 7
// 5
// 11

// 1
// 10
// 1
// 15
// 1
// 8
// 1
// 7
// 5
// 3
// 5
// 4
// 5
// 8
// 5
// 11

