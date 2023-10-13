#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;

void twoSum(vector<int>& nums, int target, int i, int j) {
    while(i < j) {
        if(nums[i] + nums[j] > target)
            j--;
        else if(nums[i] + nums[j] < target)
            i++;
        else {
            while(i < j && nums[i] == nums[i+1]) i++;
            while(i < j && nums[j] == nums[j-1]) j--;

            ans.push_back({-target, nums[i], nums[j]});
            i++;
            j--;
        }
    } 
}

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    if(n < 3) {
        return {};
    }

    ans.clear();
    sort(begin(nums), end(nums));
    for(int i = 0; i<n-2; i++) {
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        } 
        int n1 = nums[i];
        int target = -n1;
        twoSum(nums, target, i+1, n-1);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin>>nums[i];
    }

    vector<vector<int>>result = threeSum(nums);
    for(vector<int>& triplet : result) {
        for(int num : triplet) {
            cout<< num << " ";
        }
        cout << endl;
    }
}

// T.C = O(n^2)
// S.C = O(1)