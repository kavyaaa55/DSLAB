#include <bits/stdc++.h>
using namespace std;

vector<int> a, originalA;

void readArray() {
  int n;
  cout << "Size: ";
  cin >> n;
  a.resize(n);
  cout << "Elements: ";
  for (int i = 0; i < n; i++)
    cin >> a[i];
  originalA = a;
}

void resetArray() { a = originalA; }

void displayArray() {
  for (int x : a)
    cout << x << " ";
  cout << "\n";
}

// ---------- Bubble Sort ----------
void bubbleSort() {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
    }
  }
}

// ---------- Insertion Sort ----------
void insertionSort() {
  int n = a.size();
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

// ---------- Merge Sort ----------
void mergeVec(int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = a[m + 1 + j];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      a[k++] = L[i++];
    else
      a[k++] = R[j++];
  }
  while (i < n1)
    a[k++] = L[i++];
  while (j < n2)
    a[k++] = R[j++];
}

void mergeSort(int l, int r) {
  if (l >= r)
    return;
  int m = (l + r) / 2;
  mergeSort(l, m);
  mergeSort(m + 1, r);
  mergeVec(l, m, r);
}

// ---------- Quick Sort (pivot = first element) ----------
int partitionFirstPivot(int l, int r) {
  int pivot = a[l]; // first element as pivot
  int i = l + 1;
  int j = r;

  while (true) {
    while (i <= r && a[i] <= pivot)
      i++;
    while (j >= l + 1 && a[j] > pivot)
      j--;
    if (i >= j)
      break;
    swap(a[i], a[j]);
  }
  swap(a[l], a[j]); // put pivot in correct place
  return j;
}

void quickSort(int l, int r) {
  if (l >= r)
    return;
  int p = partitionFirstPivot(l, r);
  quickSort(l, p - 1);
  quickSort(p + 1, r);
}

// ---------- Radix Sort (base 10, non-negative) ----------
int getMaxVal() {
  int mx = 0;
  for (int x : a)
    if (x > mx)
      mx = x;
  return mx;
}

void countingSortExp(int exp) {
  int n = a.size();
  vector<int> output(n);
  int cnt[10] = {0};

  for (int i = 0; i < n; i++)
    cnt[(a[i] / exp) % 10]++;

  for (int i = 1; i < 10; i++)
    cnt[i] += cnt[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    int d = (a[i] / exp) % 10;
    output[cnt[d] - 1] = a[i];
    cnt[d]--;
  }
  for (int i = 0; i < n; i++)
    a[i] = output[i];
}

void radixSort() {
  int mx = getMaxVal();
  for (int exp = 1; mx / exp > 0; exp *= 10)
    countingSortExp(exp);
}

// ---------- Bucket Sort (always 10 buckets) ----------
void bucketSort() {
  if (a.empty())
    return;
  int mx = getMaxVal();
  if (mx == 0)
    return;

  const int bucketCount = 10; // fixed 10 buckets
  vector<vector<int>> buckets(bucketCount);

  for (int x : a) {
    int idx = (long long)x * bucketCount / (mx + 1); // 0..9
    if (idx >= bucketCount)
      idx = bucketCount - 1;
    buckets[idx].push_back(x);
  }

  int k = 0;
  for (int i = 0; i < bucketCount; i++) {
    sort(buckets[i].begin(), buckets[i].end());
    for (int x : buckets[i])
      a[k++] = x;
  }
}

// ---------- Binary Search (on sorted array a) ----------
int binarySearch(int key) {
  int l = 0, r = (int)a.size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (a[m] == key)
      return m;
    if (a[m] < key)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}

int main() {
#ifndef ONLINE_JUDGE
  cout << "Debug mode\n";
#endif

  int ch;
  while (true) {
    cout << "\n1. Read array\n";
    cout << "2. Reset to original\n";
    cout << "3. Bubble sort\n";
    cout << "4. Insertion sort\n";
    cout << "5. Merge sort\n";
    cout << "6. Quick sort (pivot = first element)\n";
    cout << "7. Radix sort\n";
    cout << "8. Bucket sort (10 buckets)\n";
    cout << "9. Binary search (on current array)\n";
    cout << "10. Display array\n";
    cout << "11. Exit\n";
    cout << "Choice: ";
    cin >> ch;

    if (ch == 1) {
      readArray();
    } else if (ch == 2) {
      resetArray();
    } else if (ch == 3) {
      bubbleSort();
    } else if (ch == 4) {
      insertionSort();
    } else if (ch == 5) {
      if (!a.empty())
        mergeSort(0, (int)a.size() - 1);
    } else if (ch == 6) {
      if (!a.empty())
        quickSort(0, (int)a.size() - 1);
    } else if (ch == 7) {
      radixSort();
    } else if (ch == 8) {
      bucketSort();
    } else if (ch == 9) {
      int key;
      cout << "Key: ";
      cin >> key;
      int idx = binarySearch(key);
      if (idx == -1)
        cout << "Not found\n";
      else
        cout << "Found at index " << idx << "\n";
    } else if (ch == 10) {
      displayArray();
    } else if (ch == 11) {
      break;
    } else {
      cout << "Invalid choice\n";
    }
  }
  return 0;
}

// Take any test case think of random nos
