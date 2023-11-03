#include<bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();

    int num1 = INT_MAX;
    int num2 = INT_MAX;

    for(int i = 0; i<n; i++) {

        int num3 = nums[i];

        // First ask num1
        if(num3 <= num1) {
            num1 = num3;
        } else if(num3 <= num2) { 
            num2 = num3;
        } else {
            return true;    // num1 < num2 < num 3
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    bool ans = increasingTriplet(nums);
    if(ans) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}

// Approach : Greedy (Optimise)
// Time : O(N), Space : O(1)