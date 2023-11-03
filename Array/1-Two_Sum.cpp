#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    map<int, int>mp;

    for(int i = 0; i<n; i++) {
        int remaining = target - nums[i];
        if(mp.find(remaining) != mp.end()) {
            return {mp[remaining], i};
        }
        mp[nums[i]] = i;
    }
    return {};
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

    vector<int>result = twoSum(nums, target);
    if (result.size() == 2) {
        cout << "[" << result[0] << ","<< result[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}

// T.C = O(N)