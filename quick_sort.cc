// Quick Sort written by Yeka Abueh

#include <iostream>
#include <vector>

using namespace std;

void swapp(int& a, int&b)
{
    int t = a;
    a = b;
    b = t;
}

int quick_sort_partition(vector<int>& v, int s, int e)
{
    int index = s;
    int pivot = v[e];
    for (int c = s; c < e; ++c) {
        if (v[c] <= pivot) {
            swapp(v[c], v[index]);
            index++;
        }
    }
    swapp(v[e], v[index]);
    return index;
}

void quick_sort(vector<int>& v, int s, int e)
{
    if (s < e) {
        int index = quick_sort_partition(v, s, e);
        quick_sort(v, s, index-1);
        quick_sort(v, index+1, e);
    }
}

int main()
{
    vector<int> vec{22,1,123,4,56,0,2,7,8,4,1,3};
    quick_sort(vec, 0, vec.size()-1);
    for (auto item : vec) cout << item << endl;

    return 0;
}
