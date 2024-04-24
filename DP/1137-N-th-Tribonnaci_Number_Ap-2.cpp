#include<bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
        int dp[38];

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i<=37; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }

int main() {
    int n;
    cin >> n;

    cout << tribonacci(n) << endl;
    return 0;
}

// Approach : Bottom Up;
// Time Complexity: O(n);
// Space Complexity: O(38) Constant