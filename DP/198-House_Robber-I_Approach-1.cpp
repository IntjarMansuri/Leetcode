#include<bits/stdc++.h>
using namespace std;

// Approach : Recursion + Memoization (Top Down)

int dp[101];
int solve(vector<int>& nums, int i, int n) {
    if(i >= n)
        return 0;

    if(dp[i] != -1) {
        return dp[i];
    }

    int steal = nums[i] + solve(nums, i+2, n);
    int skip = solve(nums, i+1, n);

    return dp[i] = max(steal, skip);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(nums, 0, n);
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int ans = rob(nums);
    cout << ans << endl;
}