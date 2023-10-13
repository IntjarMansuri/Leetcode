#include<bits/stdc++.h>
using namespace std;

int integerBreak(int n) {
    if(n <= 3) {
        return n-1;
    }

    vector<int> dp(100);

    for(int i = 4; i<=n; i++) {
        for(int j=1; j<i; j++) {
            dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]));
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    int ans = integerBreak(n);
    cout << ans << endl;

    return 0;
}