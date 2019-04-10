#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 1000;

int n, m, a[SIZE][SIZE], hMin[SIZE][SIZE], vMin[SIZE][SIZE], rowMax[SIZE], colMax[SIZE];

void readInput() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
}

vector<int> minifyVector(vector<int> arr) { 
    vector<pair<int, int>> arrp;
    for (int i = 0; i < arr.size(); ++i) {        
        arrp.push_back(make_pair(arr[i], i));
    }
    sort(arrp.begin(), arrp.end());
    int max = 1;
    int minArr[SIZE];
    minArr[arrp[0].second] = 1;
    for (int i = 1; i < arrp.size(); ++i) {
        if (arrp[i].first > arrp[i-1].first) {
            ++max;
        }
        minArr[arrp[i].second] = max;
    }
    vector<int> minArrVec;
    for (int i = 0; i < arrp.size(); ++i) {
        minArrVec.push_back(minArr[i]);
    }
    return minArrVec;
}

void horizontallyMinify() {
    
    for (int i = 0; i < m; ++i) {
        vector<int> arr;
        for (int j = 0; j < n; ++j) {
            arr.push_back(a[i][j]);
        }
        auto minArr = minifyVector(arr);
        for (int j = 0; j < n; ++j) {
            hMin[i][j] = minArr[j];
        }
    }
}

void verticallyMinify() {
    for (int j = 0; j < n; ++j) {
        vector<int> arr;
        for (int i = 0; i < m; ++i) {
            arr.push_back(a[i][j]);
        }
        auto minArr = minifyVector(arr);
        for (int i = 0; i < m; ++i) {
            vMin[i][j] = minArr[i];
        }
    }
}

void minify() {
    horizontallyMinify();
    verticallyMinify();
}

void findRowMaxes() {
    for (int i = 0; i < m; ++i) {
        int tmp = hMin[i][0];
        for (int j = 1; j < n; ++j) {
            tmp = max(tmp, hMin[i][j]);
        }
        rowMax[i] = tmp;
    }
}

void findColMaxes() {
    for (int j = 0; j < n; ++j) {
        int tmp = vMin[0][j]; 
        for (int i = 1; i < m; ++i) {
            tmp = max(tmp, vMin[i][j]);
        }
        colMax[j] = tmp;
    }   
}

void findMaxes() {
    findRowMaxes();
    findColMaxes();
}

int main() {
    readInput();
    minify();
    findMaxes();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int r;
            if (vMin[i][j] >= hMin[i][j]) {
                r = max(colMax[j], rowMax[i] + vMin[i][j] - hMin[i][j]);
            } else {
                r = max(rowMax[i], colMax[j] + hMin[i][j] - vMin[i][j]);
            }
            cout << r << " ";
        }
        cout << "\n";
    }
}