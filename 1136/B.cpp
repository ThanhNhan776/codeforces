#include <iostream>
#include <algorithm>

using namespace std;

int n, k, result = 0;

int main() {
    cin >> n >> k;
    
    // pick up the k-th stone: throw stone, pick coin, get stone back
    result = 3;

    // pick up the rest stones
    result += 3 * (n - 1);

    // add moves
    result += min(k - 1, n - k);

    cout << result;
}