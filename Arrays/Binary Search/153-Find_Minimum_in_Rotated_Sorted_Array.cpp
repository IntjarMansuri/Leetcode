#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n-1;

    while(l < r) {
        int mid = l + (r - l)/2;
        if(nums[mid] > nums[r]) {
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    return nums[r];
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0 ; i<n; i++) {
        cin >> nums[i];
    }

    int ans = findMin(nums);
    cout << ans << endl;

    return 0;
}

// T.C = O(log n)