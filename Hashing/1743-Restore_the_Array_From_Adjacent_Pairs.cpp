#include<bits/stdc++.h>
using namespace std;
vector<int> result;
void solve(int u, int prev, unordered_map<int, vector<int>>& adj) {
    result.push_back(u);

    for(int &v : adj[u]) {
        if(v != prev) {
            solve(v, u, adj);
        }
    }
}
vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, vector<int>>adj;

    for(vector<int>& vec : adjacentPairs) {
        int u = vec[0];
        int v = vec[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int startPoint = -1;
    for(auto & x : adj) {
        if(x.second.size() == 1) {
            startPoint = x.first;
            break;
        }
    }
    solve(startPoint, INT_MIN, adj);

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjacentPairs(n, vector<int>(2));
    for(int i = 0; i<n; i++) {
        cin >> adjacentPairs[i][0] >> adjacentPairs[i][1];
    }

    vector<int> result = restoreArray(adjacentPairs);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Approach : Simple DFS
// Time : O(n), Space : O(n)