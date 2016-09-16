/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <cmath>
#include <stdexcept>
#include <fstream>
#include "Myheader.h"
#define LOG(x) std::cout << x << std::endl;

using namespace std;

void add_to_vector(vector<int>& v, int a)
{
    for (unsigned i = 0; i < v.size(); ++i)
    {
        if (a == v[i]) {return;}
    }
    v.push_back(a);
}

int main()
{
    int x[] = {90, 12, 490, 90, 3, 2, 30, 90, 30, 2, 1, 1, 1, 1, 1, 1, 0, 8, 30, 9, 2, 90, 90, 90, 90};
    int size = 26;
    vector<int> x_vec(x, x+size);
    vector<int> xd;
    int most = 1;
    int counter = 1;
    int mode = 0;
    sort(x_vec.begin(), x_vec.end());
    for (unsigned i = 0; i < x_vec.size()-1; ++i)
    {
        if (x_vec[i] == x_vec[i+1])
        {
            ++counter;
            if (counter >= most)
            {
                if (counter == most)
                {
                    add_to_vector(xd, mode);
                    add_to_vector(xd, x_vec[i+1]);
                }
                else
                {
                    most = counter;
                    mode = x_vec[i+1];
                    xd.clear();
                    add_to_vector(xd, mode);
                }
            }
        }
        else {counter = 1;}
    }
    cout << "the multi-mode item(s): " << endl;
    for (auto item : xd)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
