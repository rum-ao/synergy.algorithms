#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int *bin_search(int *first, int *last, int x)
{
    int sz = last - first;
    int l = 0, r = sz;
    while (r - l > 1)
    {
        int m = (r + l) / 2;
        if (first[m] < x)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    if (l == r || r == sz || first[r] - x >= x - first[l]) {
            return first +l;
        }
        else {
            return first + r;
        }         
}

int main()
{
    vector<int> v = {1, 2, 2, 3, 6, 9, 11, 15};
    cout << *bin_search(&v[0], &v[v.size() - 1], 14);
}