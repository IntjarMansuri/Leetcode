#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int rev(int num) {
    int ans = 0;
    while(num > 0) {
        int rem = num%10;
        ans = (ans*10) + rem;
        num = num/10;
    }
    return ans;
}
int countNicePairs(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int>mp;

    // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
    for(int i = 0; i<n; i++) {
        nums[i] = nums[i] - rev(nums[i]);
    }

    int result = 0;
    for(int i = 0; i<n; i++) {
        result = (result + mp[nums[i]]) % mod;
        mp[nums[i]]++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int totalPairs = countNicePairs(nums);
    cout << totalPairs << endl;

    return 0;
}

// Using Hashmap
// time : O(n), space : O(n)