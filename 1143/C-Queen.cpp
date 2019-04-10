#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100000 + 1;
const int SAFE = 1;
const int DANDER = -1;
const int NOT_SPECIFIED = 0;

int n, root;
vector<int> adj[SIZE];
int c[SIZE];
int state[SIZE];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        state[i] = NOT_SPECIFIED;
    }

    for (int i = 1; i <= n; ++i) {
        if (state[i] == NOT_SPECIFIED) {
            state[i] = DANDER;
        }
        int p;
        cin >> p >> c[i];
        if (p != -1) {
            adj[i].push_back(p);
        } else {
            root = i;
        }

        if (c[i] == 0) {
            state[i] = SAFE;
            state[p] = SAFE;
        }
    }

    bool found = false;
    for (int i = 1; i <= n; ++i) {
        if (state[i] == DANDER) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << -1;
    }
}