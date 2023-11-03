#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int>& nums) {
    int n = nums.size();

    int i = 0;

    for(int j = 0; j<n; j++) {
        
        if(nums[j] != 0) {
            swap(nums[j], nums[i]);
            i++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    moveZeros(nums);
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}