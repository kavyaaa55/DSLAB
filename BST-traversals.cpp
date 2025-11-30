#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node *root = nullptr; // GLOBAL ROOT

// ---------- INSERT (void, no root argument) ----------
void insertBST(int x) {
  Node *newNode = new Node(x);

  if (!root) {
    root = newNode;
    return;
  }

  Node *curr = root;
  Node *parent = nullptr;

  while (curr) {
    parent = curr;
    if (x < curr->data)
      curr = curr->left;
    else if (x > curr->data)
      curr = curr->right;
    else
      return;
  }

  if (x < parent->data)
    parent->left = newNode;
  else
    parent->right = newNode;
}

// ---------- SEARCH ----------
bool searchRec(Node *node, int key) {
  if (!node)
    return false;
  if (key == node->data)
    return true;
  return key < node->data ? searchRec(node->left, key)
                          : searchRec(node->right, key);
}

bool searchIter(int key) {
  Node *curr = root;
  while (curr) {
    if (curr->data == key)
      return true;
    curr = (key < curr->data ? curr->left : curr->right);
  }
  return false;
}

// ---------- DELETE ----------
Node *minNode(Node *node) {
  while (node && node->left)
    node = node->left;
  return node;
}

Node *deleteRec(Node *node, int key) {
  if (!node)
    return node;

  if (key < node->data)
    node->left = deleteRec(node->left, key);
  else if (key > node->data)
    node->right = deleteRec(node->right, key);
  else {
    if (!node->left) {
      Node *t = node->right;
      delete node;
      return t;
    } else if (!node->right) {
      Node *t = node->left;
      delete node;
      return t;
    }
    Node *t = minNode(node->right);
    node->data = t->data;
    node->right = deleteRec(node->right, t->data);
  }

  return node;
}

void deleteNode(int key) { root = deleteRec(root, key); }

// ---------- TRAVERSALS (recursive) ----------
void inorderRec(Node *node) {
  if (!node)
    return;
  inorderRec(node->left);
  cout << node->data << " ";
  inorderRec(node->right);
}

void preorderRec(Node *node) {
  if (!node)
    return;
  cout << node->data << " ";
  preorderRec(node->left);
  preorderRec(node->right);
}

void postorderRec(Node *node) {
  if (!node)
    return;
  postorderRec(node->left);
  postorderRec(node->right);
  cout << node->data << " ";
}

// ---------- ITERATIVE TRAVERSALS ----------
void inorderIter() {
  stack<Node *> st;
  Node *curr = root;

  while (curr || !st.empty()) {
    while (curr) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    cout << curr->data << " ";
    curr = curr->right;
  }
}

void preorderIter() {
  if (!root)
    return;
  stack<Node *> st;
  st.push(root);

  while (!st.empty()) {
    Node *curr = st.top();
    st.pop();
    cout << curr->data << " ";
    if (curr->right)
      st.push(curr->right);
    if (curr->left)
      st.push(curr->left);
  }
}

void postorderIter() {
  stack<Node *> st;
  Node *curr = root, *last = nullptr;

  while (curr || !st.empty()) {
    if (curr) {
      st.push(curr);
      curr = curr->left;
    } else {
      Node *node = st.top();
      if (node->right && last != node->right) {
        curr = node->right;
      } else {
        cout << node->data << " ";
        st.pop();
        last = node;
      }
    }
  }
}

// ---------- MENU ----------
int main() {
  int choice;

  while (true) {
    cout << "\n1. Insert\n2. Delete\n3. Search\n4. Recursive Traversals\n5. "
            "Iterative Traversals\n6. Exit\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
      int x;
      cout << "Insert value: ";
      cin >> x;
      insertBST(x);
    } else if (choice == 2) {
      int x;
      cout << "Delete value: ";
      cin >> x;
      deleteNode(x);
    } else if (choice == 3) {
      int x;
      cout << "Search value: ";
      cin >> x;
      cout << "Recursive: " << (searchRec(root, x) ? "Found" : "Not found")
           << "\n";
      cout << "Iterative: " << (searchIter(x) ? "Found" : "Not found") << "\n";
    } else if (choice == 4) {
      cout << "Inorder: ";
      inorderRec(root);
      cout << "\n";
      cout << "Preorder: ";
      preorderRec(root);
      cout << "\n";
      cout << "Postorder: ";
      postorderRec(root);
      cout << "\n";
    } else if (choice == 5) {
      cout << "Inorder: ";
      inorderIter();
      cout << "\n";
      cout << "Preorder: ";
      preorderIter();
      cout << "\n";
      cout << "Postorder: ";
      postorderIter();
      cout << "\n";
    } else
      break;
  }
}
