#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int numberOfWays(string corridor) {
    int n = corridor.size();
    vector<int>seats;    // indices of seats only

    for(int i = 0; i<n; i++) {
        if(corridor[i] == 'S') {
            seats.push_back(i);
        }
    }

    if(seats.size() % 2 != 0 || seats.size() == 0) {
        return 0;
    }

    long long result = 1;

    int prev_end_idx = seats[1];   // End index of the previous 2-seats Subarray

    for(int i = 2; i<seats.size(); i += 2) {
        int length = seats[i] - prev_end_idx;

        result = (result * length)%mod;
        prev_end_idx = seats[i + 1];
    }
    return result;
}

int main() {
    string corridor;
    cin >> corridor;

    int ans = numberOfWays(corridor);
    cout << ans << endl;

    return 0;
}

// Approach : Using Simple Iteraton
// Time : O(n), Space : O(n)