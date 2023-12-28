#include<bits/stdc++.h>
using namespace std;

int dp[101][27][101][101];

int solve(string &s, int i, int prev, int freq, int k) {

    if(k < 0) {
        return INT_MAX;
    }

    if(i >= s.length()) {
        return 0;
    }

    if(dp[i][prev][freq][k] != -1) {
        return dp[i][prev][freq][k];
    }

    int dlt_i = solve(s, i+1, prev, freq, k-1);
    int keep_i = 0;

    if(s[i] - 'a' == prev) {
        int one_more_added = 0;
        if(freq == 1 || freq == 9 || freq == 99) {
            one_more_added = 1;
        }

        keep_i = one_more_added + solve(s, i+1, prev, freq+1, k);
    }
    else {
        keep_i = 1 + solve(s, i+1, s[i] - 'a', 1, k);
    }

    return dp[i][prev][freq][k] = min(dlt_i, keep_i);
}

int getLengthOfOptimalCompression(string s, int k) {
    memset(dp, -1, sizeof(dp));

    return solve(s, 0, 26, 0, k);
}

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    int result = getLengthOfOptimalCompression(s, k);
    cout << result << endl;

    return 0;
}

// Approach : Recursion + Memoization
// Time : O(n^2 * k), Space : O(1)