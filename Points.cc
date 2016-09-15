/////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ostream>

using namespace std;


class Points
{
private:
    int xCoord;
    int yCoord;
public:
    Points(int x, int y):xCoord{x}, yCoord{y} {}
    int get_xCoord() const;
    int get_yCoord() const;
};


///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Myheader.h"

using namespace std;


int Points::get_xCoord() const
{
    return xCoord;
}

int Points::get_yCoord() const
{
    return yCoord;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
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

ostream& operator<<(ostream& ost, const Points& p) // helper function
{
    return ost << "x coordinate: " << p.get_xCoord() << " and y coordinate: " << p.get_yCoord();
}

int main()
{
    Points p1{90, 4};
    Points p2{2, -500};
    cout << p1 << "\n" << p2 << endl;
    return 0;
}
