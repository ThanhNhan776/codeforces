#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 300000;

int n, c[SIZE], result;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    result = 0;
    int i = 0;
    while (i < n && c[i] == c[n-1]) {
        ++i;
    }
    result = max(result, n-1 - i);
    int j = n-1;
    while (j >= 0 && c[0] == c[j]) {
        --j;
    }
    result = max(result, j);
    cout << result;
    return 0;
}