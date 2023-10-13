#include<bits/stdc++.h>
using namespace std;

int first_Position(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    int ans = -1;

    while(l <= r) {
        int mid = l + (r-l)/2;
        if(nums[mid] == target) {
            ans = mid;
            r = mid - 1;
        }
        else if(nums[mid] > target) {
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return ans;
}

int last_Position(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    int ans = -1;

    while(l <= r) {
        int mid = l + (r-l)/2;
        if(nums[mid] == target) {
            ans = mid;
            l = mid + 1;
        }
        else if(nums[mid] > target) {
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    
    int first = first_Position(nums, target);
    int last = last_Position(nums, target);

    return {first, last};
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<int> positions = searchRange(nums, target);
    if (positions[0] == -1) {
        cout << "Target not found in the array." << endl;
    } else {
        cout << positions[0] <<", "<< positions[1] << endl;
    }

    return 0;
}

// T.C = O(n*log n)