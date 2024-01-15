#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_map<int, int>losses;
    unordered_set<int>players;

    for(auto &match : matches) {
        players.insert(match[0]);
        players.insert(match[1]);

        losses[match[1]]++;
    }

    vector<int>zeroLoss;
    vector<int>oneLoss;

    for(auto &player : players) {
        if(losses[player] == 0) {
            zeroLoss.push_back(player);
        }
        else if(losses[player] == 1) {
            oneLoss.push_back(player);
        }
    }

    sort(begin(zeroLoss), end(zeroLoss));
    sort(begin(oneLoss), end(oneLoss));

    return {zeroLoss, oneLoss};
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matches(n, vector<int>(2));
    for(int i = 0; i<n; i++) {
        cin >> matches[i][0] >> matches[i][1];;
    }

    vector<vector<int>>result =  findWinners(matches);
    
    for(int player : result[0]) {
        cout << player << " ";
    }

    for(int player : result[1]) {
        cout << player << " ";
    }

    return 0;
}