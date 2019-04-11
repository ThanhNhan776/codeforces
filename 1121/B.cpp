#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE_N = 1000;
const int SIZE_S = 2*1e5;

int n, a[SIZE_N], s[SIZE_S], result;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    result = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            int sum = a[i] + a[j];
            ++s[sum];
            result = max(result, s[sum]);
        }
    }
    cout << result;
}