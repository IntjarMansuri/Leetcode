#include<bits/stdc++.h>
using namespace std;

int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int>mp;
    int freq = n/4;

    for(int num : arr) {
        mp[num]++;

        if(mp[num] > freq) {
            return num;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    int result = findSpecialInteger(arr);
    cout << result;

    return 0;
}

// Approach : Using HashMap
// Time : O(n), Space : O(n)