#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <unordered_map>
#include <cctype>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    unordered_map<string, string>um;
    regex pattern1{"(\\w*)([\\.]+)(\\w+)$"};
    regex pattern2{"\\w+$"};
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        for (auto& item : EXT) {
            item = tolower(item);
        }
        um[EXT] = MT;
    }
    for (int i = 0; i < Q; i++) {
        smatch t;
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        for (auto& item : FNAME) {
            item = tolower(item);
        }
        if (regex_search(FNAME,t,pattern1)) {
            if (regex_search(FNAME,t,pattern2)) {
                for (auto item : t) {
                    if (um[item] != "") {
                        cout << um[item] << endl;
                    }
                    else {
                        cout << "UNKNOWN" << endl;
                    }
                }
            }
        }
        else {
                cout << "UNKNOWN" << endl;
        }
    }
}
