#include<bits/stdc++.h>
using namespace std;

int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    int freq = n/4;

    for(int i = 0; i<n-freq; i++) {
        if(arr[i] == arr[i + freq]) {
            return arr[i];
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

// Time : O(n), Space : O(1)