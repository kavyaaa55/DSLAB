#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// ---------- BST INSERT ----------
Node *insertBST(Node *root, int x) {
  if (!root)
    return new Node(x);
  if (x < root->data)
    root->left = insertBST(root->left, x);
  else if (x > root->data)
    root->right = insertBST(root->right, x);
  return root;
}

// ---------- BST SEARCH ----------
bool searchRec(Node *root, int key) {
  if (!root)
    return false;
  if (root->data == key)
    return true;
  if (key < root->data)
    return searchRec(root->left, key);
  else
    return searchRec(root->right, key);
}

bool searchIter(Node *root, int key) {
  Node *cur = root;
  while (cur) {
    if (key == cur->data)
      return true;
    if (key < cur->data)
      cur = cur->left;
    else
      cur = cur->right;
  }
  return false;
}

// ---------- BST DELETE ----------
Node *minValueNode(Node *node) {
  Node *cur = node;
  while (cur && cur->left)
    cur = cur->left;
  return cur;
}

Node *deleteNode(Node *root, int key) {
  if (!root)
    return nullptr;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    // 0 or 1 child
    if (!root->left) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (!root->right) {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    // 2 children: replace with inorder successor
    Node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

// ---------- RECURSIVE TRAVERSALS ----------
void inorderRec(Node *root) {
  if (!root)
    return;
  inorderRec(root->left);
  cout << root->data << " ";
  inorderRec(root->right);
}

void preorderRec(Node *root) {
  if (!root)
    return;
  cout << root->data << " ";
  preorderRec(root->left);
  preorderRec(root->right);
}

void postorderRec(Node *root) {
  if (!root)
    return;
  postorderRec(root->left);
  postorderRec(root->right);
  cout << root->data << " ";
}

// ---------- ITERATIVE TRAVERSALS (ONE STACK EACH) ----------
void inorderIter(Node *root) {
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

void preorderIter(Node *root) {
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

void postorderIter(Node *root) {
  if (!root)
    return;
  stack<Node *> st;
  Node *curr = root;
  Node *last = nullptr;

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

// ---------- MENU MAIN ----------
int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode\n";
#endif

  Node *root = nullptr;
  int choice;

  while (true) {
    cout << "\n1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search (recursive & iterative)\n";
    cout << "4. Recursive traversals (3)\n";
    cout << "5. Iterative traversals (3, one stack each)\n";
    cout << "6. Exit\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
      int x;
      cout << "Value to insert: ";
      cin >> x;
      root = insertBST(root, x);
    } else if (choice == 2) {
      int x;
      cout << "Value to delete: ";
      cin >> x;
      root = deleteNode(root, x);
    } else if (choice == 3) {
      int x;
      cout << "Value to search: ";
      cin >> x;
      bool r1 = searchRec(root, x);
      bool r2 = searchIter(root, x);
      cout << "Recursive search: " << (r1 ? "Found" : "Not found") << "\n";
      cout << "Iterative search: " << (r2 ? "Found" : "Not found") << "\n";
    } else if (choice == 4) {
      if (!root) {
        cout << "Tree empty\n";
        continue;
      }
      cout << "Inorder (rec):   ";
      inorderRec(root);
      cout << "\nPreorder (rec):  ";
      preorderRec(root);
      cout << "\nPostorder (rec): ";
      postorderRec(root);
      cout << "\n";
    } else if (choice == 5) {
      if (!root) {
        cout << "Tree empty\n";
        continue;
      }
      cout << "Inorder (iter):   ";
      inorderIter(root);
      cout << "\nPreorder (iter):  ";
      preorderIter(root);
      cout << "\nPostorder (iter): ";
      postorderIter(root);
      cout << "\n";
    } else if (choice == 6) {
      break;
    } else {
      cout << "Invalid choice\n";
    }
  }

  return 0;
}
