#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    int left = 1;
    for(int i = 0; i<n; i++) {
        result[i] *= left;
        left *= nums[i];
    }

    int right = 1;
    for(int i = n-1; i>=0; i--) {
        result[i] *= right;
        right *= nums[i];
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

    vector<int>result = productExceptSelf(nums);
    for(int ans : result) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity = O(N)
// Space Complexity = O(1)