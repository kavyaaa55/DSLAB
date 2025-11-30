#include <bits/stdc++.h>
using namespace std;

class HashTable {
private:
  static const int SIZE = 11;
  int table[SIZE];

public:
  HashTable() { fill(table, table + SIZE, -1); }

  int hash(int key) { return key % SIZE; }

  void insert(int key) {
    int index = hash(key);
    int i = 0;

    // h(k,i) = (h(k) + i) % m
    while (table[index] != -1) {
      index = (hash(key) + ++i) % SIZE;
    }
    table[index] = key;
  }

  void print() {
    for (int i = 0; i < SIZE; i++) {
      cout << i << ": " << table[i] << endl;
    }
  }
};

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode" << endl;
#endif

  HashTable ht;
  ht.insert(5);  // 5 % 11 = 5
  ht.insert(15); // 15 % 11 = 4
  ht.insert(3);  // 3 % 11 = 3

  ht.print();

  return 0;
}
