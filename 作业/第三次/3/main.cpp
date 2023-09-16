#include <iostream>
#include <utility>
#include "altset.h"
#include<fstream>
using namespace std;
int main() {
    ifstream cin("sample.in");
    // cout << "testing" <<endl;
    int n, m, k;
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    // cout << n << k << endl;
    Altset *altset = new Altset[n];
    char *str = new char[k + 1];
    cin >> str;
    altset[0] = Altset(str, k);

    cin >> m;
    for (int op, i, j; m --;) {
        cin >> op >> i >> j;
        if (op == 0) {
            altset[i].inverse(j);
        } else if (op == 1) {
            altset[i].append(j);
        } else if (op == 2) {
            altset[j] = altset[i];
        } else if (op == 3) {
            altset[j] = std::move(altset[i]);
        } else if (op == 4) {
            std::cout << int(altset[i].get(j)) << '\n';
        }
    }

    for (int i = 0; i < n; i ++) {
        if (altset[i].empty()) {
            std::cout << -1 << '\n';
        }
        else {
            std::cout << altset[i].count() << '\n';
        }
    }

    delete [] str;
    delete [] altset;
	return 0;
}
