#include<bits/stdc++.h>
using namespace std;

int n;
    
int findMax(vector<int>& nums, int skip_idx) {
        
    int currLength = 0;
    int maxLength  = 0;
        
    for(int i = 0; i<n; i++) {
        if(i == skip_idx)
            continue;
            
        if(nums[i] == 1) {
            currLength++;
            maxLength = max(maxLength, currLength);
        } else {
            currLength = 0;
        }
    }
        
    return maxLength;
        
}
    
int longestSubarray(vector<int>& nums) {
    n = nums.size();
    int result = 0;
        
    int countZero = 0;
    for(int i = 0; i<n; i++) {
            
        if(nums[i] == 0) {
            countZero++;
            result = max(result, findMax(nums, i));
        }
            
    }
        
    if(countZero == 0)
        return n-1;
        
    return result;
        
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int ans = longestSubarray(nums);
    cout << ans << endl;
    
    return 0;
}

// Approach : BrutForce
// Time : O(n^2)