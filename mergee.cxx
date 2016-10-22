#include <iostream>
#include <vector>

using namespace std;

void mergee(vector<int>& left, vector<int>& right, vector<int>& v)
{
    unsigned i = 0;
    unsigned j = 0;
    unsigned k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            v[k] = left[i];
            i++;
        }
        else {
            v[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size()) {v[k] = left[i]; i++; k++;}
    while (j < right.size()) {v[k] = right[j]; j++; k++;}
}

void merge_sort(vector<int>& v)
{
    if (v.size() == 1) return; // one base case here
    int mid_point = v.size()/2;
    vector<int> left(mid_point);
    vector<int> right;
    for (unsigned i = 0; i < left.size(); i++) {
        left[i] = v[i];
    }
    for (unsigned i = left.size(); i < v.size(); i++) {
        right.push_back(v[i]);
    }
    merge_sort(left);
    merge_sort(right);
    mergee(left, right, v);
}

int main()
{
    vector<int> vec{21,12,0,1,16,15,2,5,7,13,20,0};
    merge_sort(vec);
    for (auto item : vec) cout << item << endl;
}
