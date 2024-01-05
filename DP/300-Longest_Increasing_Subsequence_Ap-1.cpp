#include<bits/stdc++.h>
using namespace std;
int n;
int dp[2501][2501];

int solve(vector<int>& nums, int i, int prev) {
    
    if(i >= n) {
        return 0;
    }

    if(prev != -1 && dp[i][prev] != -1) {
        return dp[i][prev];
    }

    int take = 0;
    if(prev == -1 || nums[i] > nums[prev]) {
        take = 1 + solve(nums, i+1, i);
    }

    int skip = solve(nums, i+1, prev);

    if(prev != -1) {
        dp[i][prev] = max(take, skip);
    }

    return max(take, skip);
}

int lengthOfLIS(vector<int>& nums) {
    n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(nums, 0, -1);
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int result = lengthOfLIS(nums);
    cout << result << endl;

    return 0;
}

// Approach : Recursion + Memoigation
// Time : O(n^2)