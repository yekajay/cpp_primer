/////////////////////////////////////////////////////////////////////////////////
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

int main()
{
    /*
        3 4 5
        1 2 4
    */
    vector<vector<int>> mat(2, vector<int>(3));
    mat[0][0] = 3;
    mat[0][1] = 4;
    mat[0][2] = 5;
    mat[1][0] = 1;
    mat[1][1] = 2;
    mat[1][2] = 4;
    for (unsigned i = 0; i < mat.size(); ++i)
    {
        for (unsigned j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
