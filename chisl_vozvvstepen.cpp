#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll pow_fast(ll x, ll y) {
    if (y == 0) return 1.0;
    ll t = pow_fast(x, y / 2);
    if (y % 2 == 0) return t * t;
    else return t * t * x;
}

int main() {
    ll x;
    ll y;
    ll p = 1234567891;
    cin >> x >> y;
    cout << (x + y) % p;
}