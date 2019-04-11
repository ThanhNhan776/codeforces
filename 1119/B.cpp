#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1e3;

int n, h, a[SIZE], k;

int main() {
    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < n; ++j) {
        for (int i = j; i > 0; --i) {
            if (a[i] < a[i-1]) {
                swap(a[i], a[i-1]); 
            }
        } 
        // a[0..j] is sorted
        int sumOdd = 0, sumEven = 0;
        for (int i = 0; i <= j; i+= 2) {
            sumEven += a[i]; 
            if (i+1 <= j) sumOdd += a[i+1];
        }
        // cout << j << ": " << sumOdd << " " << sumEven << endl;
        if (max(sumOdd, sumEven) <= h) {
            k = j; 
        } else {
            cout << k+1;
            return 0;
        }
    }
    cout << n;
    return 0;
}