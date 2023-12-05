#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = accumulate(begin(nums), end(nums), 0);
    int leftSum = 0;

    for(int i = 0; i<nums.size(); i++) {
        if(leftSum == totalSum - leftSum - nums[i])
            return i;
            
        leftSum += nums[i];
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int result = pivotIndex(nums);
    cout << result;

    return 0;
}

// Time : O(n), Space O(1)