#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    
    int i = 0;
    int j = n - 1;

    while(i < j) {
        int sum = nums[i] + nums[j];
        if (sum < target) {
            i++;
        }
        else if ( sum > target) {
            j--;
        }
        else {
            return {i+1, j+1};
        }
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

// T.C = O(n)
// S.C = O(1)