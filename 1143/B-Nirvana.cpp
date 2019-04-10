#include <iostream>
#include <cmath>
using namespace std;

int productOfDigits(int x) {
    int result = 1;
    while (x > 0) {
        result *= (x % 10);
        x /= 10;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    if (n < 10) {
        cout << n;
        return 0;
    }

    int result = productOfDigits(n);
    for (long long i = 1; i < n; i *= 10) {
        int r = productOfDigits(n - (n%i) - 1);
        result = max(result, r); 
    }
    cout << result;
}