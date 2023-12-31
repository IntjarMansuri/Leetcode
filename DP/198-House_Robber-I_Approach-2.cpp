#include<bits/stdc++.h>
using namespace std;

// Approach : Bottom Up

int rob(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) 
        return nums[0];

    vector<int> dp(n+1, 0);

    dp[0] = 0;
    dp[1] = nums[0];

    for(int i = 2; i <= n; i++) {
        int steal = nums[i-1] + dp[i-2];
        int skip = dp[i-1];

        dp[i] = max(steal, skip);
    }
    return dp[n];
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

    return 0;
}