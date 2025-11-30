#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x) : data(x), next(nullptr) {}
};

Node *head = nullptr;

// Insert at beginning
void insertFront(int x) {
  Node *newNode = new Node(x);
  newNode->next = head;
  head = newNode;
}

// Insert at end
void insertEnd(int x) {
  Node *newNode = new Node(x);
  if (head == nullptr) {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Delete from beginning
void deleteFront() {
  if (head == nullptr) {
    cout << "List empty\n";
    return;
  }
  Node *temp = head;
  head = head->next;
  delete temp;
}

// Delete from end
void deleteEnd() {
  if (head == nullptr) {
    cout << "List empty\n";
    return;
  }
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    return;
  }
  Node *temp = head;
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
}

// Delete at given position (1-based)
void deleteAtPos(int pos) {
  if (head == nullptr) {
    cout << "List empty\n";
    return;
  }
  if (pos <= 0) {
    cout << "Invalid position\n";
    return;
  }
  if (pos == 1) {
    Node *temp = head;
    head = head->next;
    delete temp;
    return;
  }
  Node *temp = head;
  int i = 1;
  while (temp != nullptr && i < pos - 1) {
    temp = temp->next;
    i++;
  }
  if (temp == nullptr || temp->next == nullptr) {
    cout << "Position out of range\n";
    return;
  }
  Node *del = temp->next;
  temp->next = del->next;
  delete del;
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
    cout << "5. Delete at given position\n";
    cout << "6. Display list\n";
    cout << "7. Exit\n";
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
      int p;
      cout << "Position (1-based): ";
      cin >> p;
      deleteAtPos(p);
    } else if (ch == 6) {
      display();
    } else if (ch == 7) {
      break;
    } else {
      cout << "Invalid choice\n";
    }
  }

  return 0;
}
