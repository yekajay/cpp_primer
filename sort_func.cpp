#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
};

bool sort_func(Player a, Player b) {
    if (a.score != b.score) {return (a.score > b.score);}
    return (a.name < b.name);
}

vector<Player> comparator(vector<Player> players) {
    sort(players.begin(), players.end(), sort_func);
    return players;
}

int main() {
    
    int n;
    cin >> n;
    vector<Player> players;
    string name;
    int score;
    for(unsigned i = 0; i < n; i++){
        cin >> name >> score;
        Player t;
        t.name = name;
        t.score = score;
        players.push_back(t);
    }
    
    vector<Player> answer = comparator(players);
    for(unsigned i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
