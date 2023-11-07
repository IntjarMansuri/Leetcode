#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int i = 0;
    int j = 0;

    int last_Zero_idx = -1;
    int result = 0;

    while(j < nums.size()) {
        if(nums[j] == 0) {
            i = last_Zero_idx+1;
            last_Zero_idx  = j;
        }
        result = max(result, j-i);
        j++;
    }
    return result;
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

// Approach : Better Sliding Window
// Time : O(n)