#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// ---------- INSERT (NORMAL BINARY TREE, LEVEL ORDER) ----------
Node *insertNode(Node *root, int x) {
  Node *newNode = new Node(x);
  if (!root)
    return newNode;

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();

    if (!curr->left) {
      curr->left = newNode;
      break;
    } else {
      q.push(curr->left);
    }

    if (!curr->right) {
      curr->right = newNode;
      break;
    } else {
      q.push(curr->right);
    }
  }
  return root;
}

// ---------- DELETE (NORMAL BINARY TREE) ----------
Node *deleteNode(Node *root, int key) {
  if (!root)
    return nullptr;

  // Single node tree
  if (!root->left && !root->right) {
    if (root->data == key) {
      delete root;
      return nullptr;
    } else {
      return root;
    }
  }

  queue<Node *> q;
  q.push(root);

  Node *keyNode = nullptr;
  Node *last = nullptr;

  // Find node to delete (keyNode) and deepest/rightmost node (last)
  while (!q.empty()) {
    last = q.front();
    Node *curr = q.front();
    q.pop();

    if (curr->data == key)
      keyNode = curr;

    if (curr->left)
      q.push(curr->left);
    if (curr->right)
      q.push(curr->right);
  }

  if (!keyNode)
    return root; // key not found

  // Copy deepest node data
  int x = last->data;
  keyNode->data = x;

  // Delete deepest node
  q.push(root);
  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();

    if (curr->left) {
      if (curr->left == last) {
        delete curr->left;
        curr->left = nullptr;
        break;
      } else
        q.push(curr->left);
    }
    if (curr->right) {
      if (curr->right == last) {
        delete curr->right;
        curr->right = nullptr;
        break;
      } else
        q.push(curr->right);
    }
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
    cout << "\n1. Insert node\n";
    cout << "2. Delete node\n";
    cout << "3. Recursive traversals\n";
    cout << "4. Iterative traversals (one stack each)\n";
    cout << "5. Exit\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
      int x;
      cout << "Value to insert: ";
      cin >> x;
      root = insertNode(root, x);
    } else if (choice == 2) {
      int x;
      cout << "Value to delete: ";
      cin >> x;
      root = deleteNode(root, x);
    } else if (choice == 3) {
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
    } else if (choice == 4) {
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
    } else if (choice == 5) {
      break;
    } else {
      cout << "Invalid choice\n";
    }
  }

  return 0;
}
