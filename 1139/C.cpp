#include <iostream>
#include <vector>
#include <cstring>
#define ll long long

using namespace std;

const int SIZE = 1e5 + 1;
const int base = 1e9 + 7;

ll n, k;
vector<int> adj[SIZE];
bool isVisited[SIZE];
ll result, badSeqCount;

void readInput();
ll countBadSequences();
ll pow(ll a, ll p);

int main() { 
    readInput();
    badSeqCount = countBadSequences();
    result = pow(n, k) - badSeqCount;
    if (result < 0) {
        result += base;
    }
    cout << result;
    return 0;
}

void readInput() {
    cin >> n >> k;
    int u, v, isBlack;
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v >> isBlack;
        if (!isBlack) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}

ll p;

void DFS(int u) {
    isVisited[u] = true;
    ++p;
    for (auto v : adj[u]) {
        if (!isVisited[v]) {
            DFS(v);
        }
    }
}

ll countBadSequences() { 
    memset(isVisited, false, sizeof(isVisited));
    ll count = 0;
    for (int i = 1; i <= n; ++i) {
        if (!isVisited[i]) {
            p = 0;
            DFS(i);
            count += pow(p, k) % base;
        }
    }
    return count % base;
}

ll pow(ll a, ll p) {
    ll result = 1;
    for (int i = 0; i < p; ++i) {
        result = (result * a)%base;
    }
    return result;
}
