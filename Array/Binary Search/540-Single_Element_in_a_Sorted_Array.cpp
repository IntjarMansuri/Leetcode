#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicates(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n-1;
    
    while(l < r) {
        int mid = l + (r - l)/2;
        bool isEven = (r-mid)%2 == 0;

        if(nums[mid] == nums[mid+1]) {
            if(isEven) {
                l = mid+2;
            }
            else {
                r = mid-1;
            }
        }
        else if (nums[mid] == nums[mid-1]) {
            if(isEven) {
                r = mid - 2;
            }
            else {
                l = mid+1;
            }
        }
        else {
            return nums[mid];
        }
    }
    return nums[l];
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int ans = singleNonDuplicates(nums);
    cout << ans << endl;

    return 0;
}

// T.C = O(log n)