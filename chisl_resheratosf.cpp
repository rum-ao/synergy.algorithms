#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int N = 1e3;
    bool p[N + 10];
    vector<vector<int>> v(N);
    for (int i = 2; i <= N; ++i) {
        p[i] = 1;
    }
    for (int x = 2; x < N; ++x) {
        if (p[x]) {
            for (int y = 2 * x; y < N; y += x) {
                p[y] = 0;
                v[y].push_back(x);
            }
        }
        else {
            for (int y = 2 * x; y < N; y += x) {
                    v[y].push_back(x);
            }
        }
        v[x].push_back(x);
        cout << x << " - ";
        for (int prim : v[x]) {
            cout << prim << ' ';
        }
        cout << endl;
    }
}