#include <iostream>
#include <vector>
#include <assert.h>
#include <bitset>
#include <iterator>
#include <random>
#include <algorithm>
#include <functional>

using namespace std;

template <class T>
void print(vector<T> &v)
{
    for (auto elem : v)
    {
        cout << elem << ' ';
    }
    cout << endl;
}

template <class T>
void merge_sort(vector<T> &v, size_t l, size_t r)
{
    if (l == r)
        return;
    size_t m = (l + r) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    vector<T> merged(r - l + 1);
    merge(v.begin() + l, v.begin() + m + 1, v.begin() + m + 1, v.begin() + r + 1, merged.begin());
    copy(merged.begin(), merged.end(), v.begin() + l);
}

template <class T>
void sort_merge(vector<T> &v)
{
    merge_sort(v, 0, v.size() - 1);
}

int main()
{
    vector<float> v1_ = {3.5, 1.2, 2.5, 1.4, 5.1, 4.3};
    vector<int> v2_ = {5, 6, 1, -1, 100, -100, 2, 500, 0};
    vector<int> v3_ = {0};
    vector<float> v1_ans = {1.2, 1.4, 2.5, 3.5, 4.3, 5.1};
    vector<int> v2_ans = {-100, -1, 0, 1, 2, 5, 6, 100, 500};
    {
        vector<float> v1 = v1_;
        vector<int> v2 = v2_;
        vector<int> v3 = v3_;
        sort_merge(v1);
        sort_merge(v2);
        sort_merge(v3);
        print(v1);
        assert(v1 == v1_ans);
        assert(v2 == v2_ans);
        assert(v3 == v3_);
        cout << "merge passed test";
    }
}