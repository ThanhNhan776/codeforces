#include <iostream>
#include <cmath>

using namespace std;

int n, countP, countN, countZ;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a > 0) ++countP;
        else if (a < 0) ++countN;
        else if (a == 0) ++countZ;
    }
    int t = ceil(n / 2.0);
    if (countP >= t) {
        cout << 1; 
    } else if (countN >= t) {
        cout << -1;
    } else {
        cout << 0;
    }
}