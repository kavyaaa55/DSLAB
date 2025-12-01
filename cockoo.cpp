#include <bits/stdc++.h>
using namespace std;

const int TABLE_SIZE = 11;
const int MAX_KICKS = 20;

struct CuckooHash {
  int table[2][TABLE_SIZE];

  CuckooHash() {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < TABLE_SIZE; j++)
        table[i][j] = -1; // -1 = empty
  }

  int h1(int key) { return key % TABLE_SIZE; }
  int h2(int key) { return (key / TABLE_SIZE) % TABLE_SIZE; }

  bool search(int key) {
    int i1 = h1(key);
    int i2 = h2(key);
    return (table[0][i1] == key || table[1][i2] == key);
  }

  void insertKey(int key) {
    if (search(key))
      return; // already present

    int curKey = key;
    int tableId = 0;

    for (int kick = 0; kick < MAX_KICKS; kick++) {
      int pos = (tableId == 0 ? h1(curKey) : h2(curKey));

      if (table[tableId][pos] == -1) {
        table[tableId][pos] = curKey;
        return;
      }

      // kick out existing key
      swap(curKey, table[tableId][pos]);
      tableId ^= 1; // 0 -> 1, 1 -> 0
    }
    cout << "Rehash needed (too many kicks)\n";
  }

  void deleteKey(int key) {
    int i1 = h1(key);
    int i2 = h2(key);
    if (table[0][i1] == key)
      table[0][i1] = -1;
    else if (table[1][i2] == key)
      table[1][i2] = -1;
    else
      cout << "Key not found\n";
  }

  void display() {
    cout << "Table 0:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
      cout << i << ": " << table[0][i] << "\n";
    }
    cout << "Table 1:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
      cout << i << ": " << table[1][i] << "\n";
    }
  }
};

// 1 1
// 1 12
// 4
// 5


int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode\n";
#endif

  CuckooHash ht;
  int choice;

  while (true) {
    cout << "\n1. Insert\n";
    cout << "2. Search\n";
    cout << "3. Delete\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
      int x;
      cout << "Key: ";
      cin >> x;
      ht.insertKey(x);
    } else if (choice == 2) {
      int x;
      cout << "Key: ";
      cin >> x;
      cout << (ht.search(x) ? "Found\n" : "Not found\n");
    } else if (choice == 3) {
      int x;
      cout << "Key: ";
      cin >> x;
      ht.deleteKey(x);
    } else if (choice == 4) {
      ht.display();
    } else if (choice == 5) {
      break;
    } else {
      cout << "Invalid choice\n";
    }
  }

  return 0;
}
