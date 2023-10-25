#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp) {
    
    if(n <= 1)
        return n;

    if(dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int fib(int n) {
    
    if(n <= 1) {
        return n;
    }

    vector<int> dp(n+1, -1);

    return solve(n, dp);
}

int main() {
    int n ;
    cin >> n;

    int ans = fib(n);
    cout << ans << endl;

    return 0;
}

// Approach : Recursion + Memoization