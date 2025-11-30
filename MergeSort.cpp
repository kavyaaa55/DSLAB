#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;

  // merge them in sorted order
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  // if elemnts are still left
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode" << endl;
#endif

  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  mergeSort(arr, 0, arr.size() - 1);

  for (int x : arr) {
    cout << x << " ";
  }
  // Output: 11 12 22 25 34 64 90

  return 0;
}
