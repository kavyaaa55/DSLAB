#include <bits/stdc++.h>
using namespace std;

const int SIZE = 11;
int tableArr[SIZE];

// simple hash function
int hashFunc(int key) { return key % SIZE; }

// linear probing insert
void insertKey(int key) {
  int index = hashFunc(key);
  int i = 1;

  while (tableArr[index] != -1) {
    // for slot 1
    index = (hashFunc(key) + i) % SIZE;

    // for slot 2 make it i*2
    // for slot 3 make it i*3;
    i++;
  }
  tableArr[index] = key;
}

void printTable() {
  for (int i = 0; i < SIZE; i++) {
    cout << i << ": " << tableArr[i] << "\n";
  }
}

int main() {
  fill(tableArr, tableArr + SIZE, -1);

  insertKey(5);  // goes to 5
  insertKey(15); // collides at 4, but 4 empty -> goes to 4
  insertKey(3);  // goes to 3

  printTable();

  return 0;
}
