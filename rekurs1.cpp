#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int res;

void rec(int num, int ost) {
    if (ost == 0) {
        res++;
        return;
    }
    for (int k = num + 1; k <= ost; ++k) {
        rec(k, ost - k);
    }
}

int main() {
    int n;
    cin >> n;
    rec(0, n);
    cout << res;

}