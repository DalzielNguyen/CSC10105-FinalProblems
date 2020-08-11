#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector <long long> a(n);
    vector <long long > prefixSum(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];   
    }

    prefixSum[0] = a[0];
    for (long long i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + a[i]; 
    }
    long long count = 0, start  = 0, end = 0;
    //______O(N^3)_________//
    // for (long long i  = 0; i < n; i++){
    //     for (long long j = i; j < n; j++){
    //         long long sum = 0;
    //         for (long long k = i; k <= j; k++)
    //             sum += a[k];
    //         if (sum == 0 && j - i > count ){
    //             count = end - start;
    //             start = i;
    //             end = k;
    //         }
    //     }
    // }

    //___________O(N^2)___________//
    // for (long long i = 1; i < n; i++) {
    //      for (long long j = 1; j < n; j++) {
    //          if (prefixSum[j] - prefixSum[i - 1] == 0 && j - i > count){
    //             count = j - i;
    //             start = i;
    //             end =j;
    //          }
    //     }
    // }

    // better
    map<long long, int> idx;
    for (int i = 0; i < n; i++) {
        if (idx.find(prefixSum[i]) != idx.end()) {
            int p = idx[prefixSum[i]];
            if (i - p > end - start) {
                start = p;
                end = i;
            }
        }
        else {
            idx[prefixSum[i]] = i;
        }
    }
    count = end - start;

    cout << count << endl;
    cout << start << " " << endl;
    return 0;
}
