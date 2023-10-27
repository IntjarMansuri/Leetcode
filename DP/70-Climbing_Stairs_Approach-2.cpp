#include<bits/stdc++.h>
using namespace std;

// Approach : Recursion + Memoization

int dp[46];
int solve(int n) {
    if(n < 0)
        return 0;

    if(dp[n] != -1) {
        return dp[n];

    }

    if(n == 0)
        return 1;

    int one_step = solve(n-1);
    int two_step = solve(n-2);

    return one_step + two_step;
}

int climbStars(int n) {

    memset(dp, -1, sizeof(dp));

    return solve(n);
}

int main() {
    int n;
    cin >> n;

    int ans = climbStars(n);
    cout << ans << endl;

    return 0;
}