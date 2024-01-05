#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLIS = 1;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] +  1);
                maxLIS = max(maxLIS, dp[i]);
            }
        }
    }
    return maxLIS;
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

// Approach : Memoigation
// Time : O(n^2)