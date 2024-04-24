#include<bits/stdc++.h>
using namespace std;

    int dp[38];
    int find(int n) {
        if(n == 0) {
            return 0;
        }

        if(n == 1 || n == 2) {
            return 1;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int a = find(n-1);
        int b = find(n-2);
        int c = find(n-3);

        return dp[n] =  a + b + c;
    }
    
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        return find(n);
    }

int main() {
    int n;
    cin >> n;

    cout << tribonacci(n) << endl;

    return 0;
}

// Approach : Recursion + Memoization
// Time Complexity: O(n);
// Space Complexity: O(38) Constant