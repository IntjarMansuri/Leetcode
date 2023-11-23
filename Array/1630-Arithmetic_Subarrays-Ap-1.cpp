#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr) {
    sort(begin(arr), end(arr));
    int n = arr.size();
    int diff = arr[1] - arr[0];

    for(int i = 2; i<n; i++) {
        if(arr[i] - arr[i-1] != diff) {
            return false;
        }
    }
    return true;
}

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int m = l.size();
    vector<bool> result;

    for(int i = 0; i<m; i++) {
        vector<int> arr(begin(nums)+l[i], begin(nums)+r[i]+1);

        result.push_back(check(arr));
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i= 0; i<n; i++) {
        cin >> nums[i];
    }

    int m;
    cin >> m;

    vector<int>l(m);
    vector<int>r(m);

    for(int i = 0; i<m; i++) {
        cin >> l[i] >> r[i];
    }

    vector<bool> result = checkArithmeticSubarrays(nums, l ,r);

    for (bool res : result) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}

// Approach : Sorting
// Time : m*(nlogn), Space : O(n)