#include<bits/stdc++.h>
using namespace std;

int maxProductDiffrence(vector<int>& nums) {
    int largest = INT_MIN;
    int sec_largest = INT_MIN;

    int smallest = INT_MAX;
    int sec_smallest = INT_MAX;

    for(int &num : nums) {
        if(num > largest) {
            sec_largest = largest;
            largest = num;
        } else {
            sec_largest = max(sec_largest, num);
        }

        if(num < smallest) {
            sec_smallest = smallest;
            smallest = num;
        } else {
            sec_smallest = min(sec_smallest, num);
        }
    }

    return(largest * sec_largest) - (smallest * sec_smallest);
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int result = maxProductDiffrence(nums);
    cout << result << endl;

    return 0;
}

// Time : O(n), Space : O(1)