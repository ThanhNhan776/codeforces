#include <iostream>

using namespace std;

const int SIZE = 500;
int m, n, a[SIZE][SIZE], b[SIZE][SIZE];

int main() {
    cin >> m >> n;

    int totalParityA = 0, totalParityB = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            totalParityA += a[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
            totalParityB += b[i][j];
        }
    }

    totalParityA %= 2;
    totalParityB %= 2;
    if (totalParityA != totalParityB) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        int rowParityA = 0, rowParityB = 0;
        for (int j = 0; j < n; ++j) {
            rowParityA += a[i][j];
            rowParityB += b[i][j];
        }
        rowParityA %= 2;
        rowParityB %= 2;
        if (rowParityA != rowParityB) {
            cout << "NO";
            return 0;
        }
    }

    for (int j = 0; j < n; ++j) {
        int colParityA = 0, colParityB = 0;
        for (int i = 0; i < m; ++i) {
            colParityA += a[i][j];
            colParityB += b[i][j];
        }
        colParityA %= 2;
        colParityB %= 2;
        if (colParityA != colParityB) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}