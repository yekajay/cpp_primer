#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


string makeZeros(int count)
{
    string result;
    for(auto idx = 0; idx < count; idx++)
        result += "0";
    return result;
}

string encode(string text)
{
    vector<int> bits(text.size()+10000);
    int si = 0;
    for (auto i = 0; i < text.size(); i++) {
        for (auto j = 0; j < 7; j++) {
            auto mask = 1 << (6 - j);
            bits[i * 7 + j] = ((text[i] & mask) != 0) ? 1 : 0;
            si = i * 7 + j;
        }
    }
    auto k = 1; int last = bits[0];
    string result = (bits[0] == 0) ? "00 " : "0 ";
    for (auto i = 1; i <= si; i++) {
        if(bits[i] != last) {
            result += makeZeros(k);
            k = 1; last = bits[i];
            result += (bits[i] == 0) ? " 00 " : " 0 ";
        }
        else {
            k++;
        }
    }
    result += makeZeros(k);
    
    return result;
}

int main()
{
    string message;
    stringstream ss;
    getline(cin, message);
    
    string answer = encode(message);
    cout << answer << endl;
}
