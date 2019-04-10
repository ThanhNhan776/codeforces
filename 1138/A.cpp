#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 10e5 + 1;
int n, t[SIZE], result;

void readInput() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
            cin >> t[i];
    }
}

void solve() {
    result = 1;
    t[n] = -1;
    int left = 0, right, root = 0;
    for (int i = 1; i <= n; ++i) {
        if (t[i] != t[i-1]) {
            right = i - root;
            result = max(result, min(left, right));
            left = right;
            root = i;
        }
    }
}

void writeOutput() {
    cout << result * 2;
}

int main() {
    readInput();
    solve();
    writeOutput();
}