#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> left(n);
    left[0] = 1;
    for(int i = 1; i<n; i++) {
        left[i] = left[i-1] * nums[i-1];
    }

    vector<int> right(n);
    right[n-1] = 1;
    for(int i = n-2; i>=0; i--) {
        right[i] = right[i+1] * nums[i+1];
    }

    vector<int> result(n);
    for(int i = 0; i<n; i++) {
        result[i] = left[i] * right[i];
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

    vector<int> result = productExceptSelf(nums);
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity = O(N);
// Space Complexity = O(N);