#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_map<int, int> lostPlayers;

    for(auto &match : matches) {
        int loser = match[1];
        lostPlayers[loser]++;
    }

    vector<int>neverLost;
    vector<int>lostOnce;

    for(auto &match : matches) {
        int winner = match[0];
        int loser = match[1];

        if(lostPlayers.find(winner) == lostPlayers.end()) {
            neverLost.push_back(winner);
            lostPlayers[winner] == 2;
        }

        if(lostPlayers[loser] == 1) {
            lostOnce.push_back(loser);
        }
    }

    sort(begin(neverLost), end(neverLost));
    sort(begin(lostOnce), end(lostOnce));

    return {neverLost, lostOnce};
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matches(n, vector<int>(2));
    for(int i = 0; i<n; i++) {
        cin >> matches[i][0] >> matches[i][1];
    }

    vector<vector<int>> result = findWinners(matches);

    for (int player : result[0]) {
        cout << player << " ";
    }

    for (int player : result[1]) {
        cout << player << " ";
    }

    return 0;
}

// Approach : HashMap
