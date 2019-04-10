#include <cstdio>

const int SIZE = 200000;

int main() {
    int n;
    int a[SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int index = n - 1;
    while (n > 0) {
        if (a[index] != a[index-1]) {
            break;
        }
        --index;
    }

    printf("%d", index);
}