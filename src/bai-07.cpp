// -- ai < bj: tương tự bài 12

// -- ai <> bj

#include <iostream>
#include <algorithm>
#define N 100000
using namespace std;

int binary_search(int arr[], int left, int right, int x) {
    int mid;

    while (left <= right) {
        mid = (left + right)/2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n, m;
    int a[N] = {};
    int b[N] = {};
    int res = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a+n);
    sort(b, b+m);

    int a_val[N] = {};
    int a_frg[N] = {0};
    int b_val[N] = {};
    int b_frg[N] = {0};
    int a_size = 0;
    int b_size = 0;

    for (int i = 0; i < n; i++) {
        if (a_size == 0 && i == 0) {
            a_val[a_size] = a[i];
            a_frg[a_size]++;
        }
        else if (a[i] == a_val[a_size]) {
            a_frg[a_size]++;
        }
        else {
            a_size++;
            a_val[a_size] = a[i];
            a_frg[a_size]++;
        }
    }
    a_size++;

    for (int i = 0; i < m; i++) {
        if (b_size == 0 && i == 0) {
            b_val[b_size] = b[i];
            b_frg[b_size]++;
        }
        else if (b[i] == b_val[b_size]) {
            b_frg[b_size]++;
        }
        else {
            b_size++;
            b_val[b_size] = b[i];
            b_frg[b_size]++;
        }
    }
    b_size++;

    for (int i = 0; i < a_size; i++) {
        int pos = binary_search(b_val, 0, b_size, a_val[i]);
        if (pos >= 0)
            res+= a_frg[i] * (m - b_frg[pos]);
        else
            res += a_frg[i] * m;
    }

    cout << res;
    return 0;
}