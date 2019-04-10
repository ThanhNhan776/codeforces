#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 500;

int a[SIZE][SIZE], b[SIZE][SIZE], n, m;

bool isDiagonalOk(int, int);

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        if (!isDiagonalOk(0, j)) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (!isDiagonalOk(i, m-1)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

bool isDiagonalOk(int i, int j) {
    vector<int> va, vb;
    while (i < n && j >= 0) {
        va.push_back(a[i][j]);
        vb.push_back(b[i][j]);
        ++i;
        --j;
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    for (int x = 0; x < va.size(); ++x) {
        if (va[x] != vb[x]) {
            return false;
        }
    }
    return true;
}