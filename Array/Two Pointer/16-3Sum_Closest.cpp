#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int closestSum = 1000000;

    for(int k = 0; k < n-2; k++) {
        int i = k+1, j = n-1;

        while(i < j) {
            int sum = nums[k] + nums[i] + nums[j];

            if(abs(target-sum) < abs(target-closestSum)) {
                closestSum = sum;
            }
            if(sum > target) 
                j--;
            else 
                i++;
        }
    }
    return closestSum;
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

    int ans = threeSumClosest(nums, target);
    cout<< ans << endl;

    return 0;
}

// T.C = O(n*log(n))
// S.C = O(n)