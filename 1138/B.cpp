#include <iostream>
#include <string>

using namespace std;

const int SIZE = 5000;

int n, na, nb, nc, nd, ra, rb, rc, rd; // a = {0, 0}, b = {0, 1}, c = {1, 0}, d = {1, 1}
string c, a;

void countArtistsByType();
void printResult();

int main() {
    cin >> n >> c >> a;

    countArtistsByType();
    // cout << "->" << na << " " << nb << " " << nc << " " << nd << endl;


    for (rb = 0; rb <= nb; ++rb) {
        for (rc = 0; rc <= nc; ++rc) {
            int doubleD = nb + nd - rb - rc; 
            // cout << "doubleD " << doubleD << endl;
            if (doubleD % 2 == 1) {
                continue;
            }
            rd = doubleD / 2;
            if (rd < 0 || rd > nd) {
                continue;
            }
            ra = n/2 - rd - rc - rb;
            if (ra < 0 || ra > na) {
                continue;
            }
            // cout << ra << " " << rb << " " << rc << " " << rd << endl;
            printResult();
            return 0;
        }
    }
    cout << -1;
    return 0;
}

void countArtistsByType() {
    na = nb = nc = nd = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] == '0' && a[i] == '0') {
            ++na;
        } else if (c[i] == '0' && a[i] == '1') {
            ++nb;
        } else if (c[i] == '1' && a[i] == '0') {
            ++nc;
        } else if (c[i] == '1' && a[i] == '1') {
            ++nd;
        }
    }
}

void printResult() {
    for (int i = 0; i < n; ++i) {
        if (ra > 0 && c[i] == '0' && a[i] == '0') {
            cout << i+1 << " ";
            --ra;
        }
        if (rb > 0 && c[i] == '0' && a[i] == '1') {
            cout << i+1 << " ";
            --rb;
        }
        if (rc > 0 && c[i] == '1' && a[i] == '0') {
            cout << i+1 << " ";
            --rc;
        }
        if (rd > 0 && c[i] == '1' && a[i] == '1') {
            cout << i+1 << " ";
            --rd;
        }
    }
}