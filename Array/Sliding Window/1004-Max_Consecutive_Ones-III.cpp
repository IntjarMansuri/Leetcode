#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0;
    int maxOnesCount = 0;
    int maxLen = 0;

    for(int j = 0; j<n; j++) {
        if(nums[j] == 0)
            k--;

        while(k < 0) {
            if(nums[i] == 0) {
                k++;
            }
            i++;
        }
        maxLen = max(maxLen, j-i+1);
    }
    return maxLen;
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    int ans = longestOnes(nums, k);
    cout << ans << endl;

    return 0;
}