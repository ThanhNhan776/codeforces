#include <iostream>
#include <utility>

using namespace std;

const int SIZE = 100;

int n, k;
pair<int, int> chapter[SIZE];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> chapter[i].first >> chapter[i].second;
    }
    cin >> k;

    int result;
    for (int i = 0; i < n; ++i) {
        if (k <= chapter[i].second) {
            result = n - i;
            break;
        }
    }
    cout << result;
}