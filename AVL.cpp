# cook your dish here
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  int height;
  Node *left, *right;
  Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(Node *node) {
  if (!node)
    return 0;
  return node->height;
}

int getBalance(Node *node) {
  if (!node)
    return 0;
  return getHeight(node->left) - getHeight(node->right);
}

Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = 1 + max(getHeight(y->left), getHeight(y->right));
  x->height = 1 + max(getHeight(x->left), getHeight(x->right));

  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = 1 + max(getHeight(x->left), getHeight(x->right));
  y->height = 1 + max(getHeight(y->left), getHeight(y->right));

  return y;
}

Node *insert(Node *root, int key) {
  // normal BST insert
  if (!root)
    return new Node(key);
  if (key < root->key)
    root->left = insert(root->left, key);
  else if (key > root->key)
    root->right = insert(root->right, key);
  else
    return root; // duplicates ignore

  // update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  // check balance
  int balance = getBalance(root);

  // LL case
  if (balance > 1 && key < root->left->key)
    return rightRotate(root);

  // RR case
  if (balance < -1 && key > root->right->key)
    return leftRotate(root);

  // LR case
  if (balance > 1 && key > root->left->key) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // RL case
  if (balance < -1 && key < root->right->key) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void inorder(Node *root) {
  if (!root)
    return;
  inorder(root->left);
  cout << root->key << " ";
  inorder(root->right);
}

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode\n";
#endif

//   5
// 30 20 40 10 25
//   Inserts in mixed order → triggers rotations.

// Contains:

// LL case (insert 10)

// RR case (insert 40)

// Balanced inserts (25)

  Node *root = nullptr;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    root = insert(root, x);
  }

  inorder(root);
  cout << endl;
  
//   4
// 30 20 10 25

// 4
// 10 20 30 25

// 3
// 30 10 20

  return 0;
}
