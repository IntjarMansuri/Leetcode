#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int zeroCount = 0;
    int maxLength = 0;

    int i = 0;
    for(int j = 0; j<nums.size(); j++) {
        if(nums[j] == 0) {
            zeroCount++;
        }

        while(zeroCount > 1) {
            if(nums[i] == 0) {
                zeroCount--;
            }
            i++;
        }
        maxLength = max(maxLength, j-i);
    }
    return maxLength;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int ans = longestSubarray(nums);
    cout << ans << endl;

    return 0;
}

// Approach : Sliding Window
// Time : O(n)