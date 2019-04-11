#include <iostream>

using namespace std;

const int SIZE = 100+1;

int n, m, k, p[SIZE], s[SIZE], c[SIZE], best[SIZE], result;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
    }

    result = 0;
    for (int i = 1; i <=n; ++i) {
        if (best[s[i]] == 0) {
            best[s[i]] = i;
        } else if (p[i] > p[best[s[i]]]) {
            best[s[i]] = i;
        }
    }
    for (int i = 1; i <= k; ++i) {
        if (best[s[c[i]]] != c[i]) {
            ++result;
        }
    }
    cout << result;
}