#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int curr_max = nums[0];
    int result = 0;

    for(int i = 1; i<n; i++) {
        result = max(result, (nums[i]-1)*(curr_max-1));
        curr_max = max(curr_max, nums[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int result = maxProduct(nums);
    cout << result << endl;

    return 0;
}

// Time : O(n), Space : O(1)