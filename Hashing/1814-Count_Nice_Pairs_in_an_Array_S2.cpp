#include<bits/stdc++.h>
using namespace std;

int countNicePairs(vector<int>& nums) {
    int mod = 1e9 + 7;
    unordered_map<long long, int>freq;

    long long nicePairs = 0;
    for(int num : nums) {
        long long key = 0, n = num;
        while(n > 0) {
            key = key*10 + n%10;
            n /= 10;
        }
        int diff = num - key;
        nicePairs += freq[diff];
        freq[diff]++;
    }
    return nicePairs % mod;
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int pairs = countNicePairs(nums);
    cout << pairs << endl;

    return 0;
}

// Approach : Hashmap
// time : O(n), space : O(n)