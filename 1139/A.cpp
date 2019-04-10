#include <iostream>

using namespace std;

int n, result = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char digit;
        cin >> digit; 
        if ((digit - '0') % 2 == 0) {
            result += i;
        }
    }
    cout << result;
}