/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>

using namespace std;


class Frequency_dictionary
{
private:
    string name;
    int counter;
public:
    Frequency_dictionary(string n, int c):name{n}, counter{c} {}
    string get_name() const;
    int get_counter() const;
    void increment_counter();
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Myheader.h"

using namespace std;


string Frequency_dictionary::get_name() const
{
    return name;
}

int Frequency_dictionary::get_counter() const
{
    return counter;
}

void Frequency_dictionary::increment_counter()
{
    ++counter;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void polish_words(vector<string>& vs, vector<string>& vs2)
{
    for (unsigned i = 0; i < vs.size(); ++i)
    {
        for (char& c : vs[i])
        {
            c = tolower(c);
        }
    }
    sort(vs.begin(), vs.end());
    for (unsigned i = 0; i < vs.size(); ++i)
    {
        if (vs[i].empty()) {}
        else {vs2.push_back(vs[i]);}
    }
}

int main()
{
    vector<string> words;
    vector<string> words2;
    int dictionary_counter = 0;
    int largest = 1;
    string strlargest;
    vector<Frequency_dictionary> dictionary;
    string s;
    ifstream in_file{"testt.txt", ifstream::in};
    char c = in_file.get();
    while (in_file.good())
    {
        if (!(c == '\n' || c == ' ' || c == '.' || c == ',' || isspace(c)))
        {
            s += c;
        }
        else
        {
            words.push_back(s); //there will be empty words. did not want to modify code here due to time
            s = "";
        }
        c = in_file.get();
    }
    in_file.close();
    polish_words(words, words2);
    for (unsigned j = 0; j < words2.size(); ++j)
    {
        if (j == 0 || words2[j] != words2[j-1])
        {
            Frequency_dictionary t{words2[j], 1};
            dictionary.push_back(t);
            ++dictionary_counter;
        }
        else {dictionary[dictionary_counter - 1].increment_counter();}
    }
    cout << setw(20) << "Words:" << setw(20) << "Frequency:" << endl;
    for (auto item : dictionary)
    {
        if (item.get_counter() > largest)
        {
            largest = item.get_counter();
            strlargest = item.get_name();
        }
        cout << setw(20) << item.get_name() << setw(20) << item.get_counter() << endl;
    }
    cout << "\nthe largest item appeared " << largest << " times and it is: " << strlargest << endl;
    return 0;
}
