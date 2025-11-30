#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// INSERT (BST rule)
Node *insertBST(Node *root, int x) {
  if (root == nullptr)
    return new Node(x);
  if (x < root->data)
    root->left = insertBST(root->left, x);
  else if (x > root->data)
    root->right = insertBST(root->right, x);
  return root;
}

// SEARCH (recursive)
bool searchBST(Node *root, int key) {
  if (root == nullptr)
    return false;
  if (root->data == key)
    return true;
  if (key < root->data)
    return searchBST(root->left, key);
  else
    return searchBST(root->right, key);
}

// COUNT NODES
int countNodes(Node *root) {
  if (root == nullptr)
    return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

// HEIGHT of tree
int height(Node *root) {
  if (root == nullptr)
    return 0;
  int hl = height(root->left);
  int hr = height(root->right);
  if (hl > hr)
    return hl + 1;
  else
    return hr + 1;
}

// MIRROR image
void mirrorTree(Node *root) {
  if (root == nullptr)
    return;
  mirrorTree(root->left);
  mirrorTree(root->right);
  Node *temp = root->left;
  root->left = root->right;
  root->right = temp;
}

// INORDER traversal (display)
void inorder(Node *root) {
  if (root == nullptr)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// MIN value node (for delete)
Node *minValueNode(Node *node) {
  Node *cur = node;
  while (cur != nullptr && cur->left != nullptr) {
    cur = cur->left;
  }
  return cur;
}

// DELETE in BST
Node *deleteNode(Node *root, int key) {
  if (root == nullptr)
    return nullptr;

  if (key < root->data) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->data) {
    root->right = deleteNode(root->right, key);
  } else {
    // 0 or 1 child
    if (root->left == nullptr) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    // 2 children: inorder successor
    Node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode\n";
#endif

  Node *root = nullptr;
  int ch;

  while (true) {
    cout << "\n1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Count nodes\n";
    cout << "5. Height of tree\n";
    cout << "6. Mirror image\n";
    cout << "7. Display (Inorder)\n";
    cout << "8. Exit\n";
    cout << "Choice: ";
    cin >> ch;

    if (ch == 1) {
      int x;
      cout << "Value: ";
      cin >> x;
      root = insertBST(root, x);
    } else if (ch == 2) {
      int x;
      cout << "Value to delete: ";
      cin >> x;
      root = deleteNode(root, x);
    } else if (ch == 3) {
      int x;
      cout << "Value to search: ";
      cin >> x;
      if (searchBST(root, x))
        cout << "Found\n";
      else
        cout << "Not found\n";
    } else if (ch == 4) {
      cout << "Total nodes = " << countNodes(root) << "\n";
    } else if (ch == 5) {
      cout << "Height = " << height(root) << "\n";
    } else if (ch == 6) {
      mirrorTree(root);
      cout << "Tree mirrored\n";
    } else if (ch == 7) {
      cout << "Inorder: ";
      inorder(root);
      cout << "\n";
    } else if (ch == 8) {
      break;
    } else {
      cout << "Invalid choice\n";
    }
  }

  return 0;
}
