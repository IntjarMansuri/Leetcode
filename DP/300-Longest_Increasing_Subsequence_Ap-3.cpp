#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int>sorted;

    for(int i = 0; i<n; i++) {
        auto x = lower_bound(begin(sorted), end(sorted), nums[i]);

        if(x == end(sorted)) {
            sorted.push_back(nums[i]);
        } else {
            *x = nums[i];     //Replace with nums[i]
        }
    }

    return sorted.size();
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

// Approach : Patience Sorting
// Time : O(n log n)
