#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

const int SIZE = 2*10e5;

int n, a[SIZE], ceiling;
ll result;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    result = a[n-1];
    ceiling = a[n-1];
    for (int i = n-2; i >= 0; --i) {
        --ceiling;
        if (ceiling == 0) {
            break;
        }
        ceiling = min(ceiling, a[i]);
        result += ceiling;
    }

    cout << result;
}