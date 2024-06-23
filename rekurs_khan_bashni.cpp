#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rec(int n, int from, int to) {
    int temp = from ^ to;
    if (n == 1) {
        cout << from << "->" << to << endl;
        return; 
    }
    rec(n-1, from, temp);
    rec(1, from, to);
    rec(n-1, temp, to);
}

int main() {
    int n;
    cin >> n;
    rec(n, 1, 3);
}