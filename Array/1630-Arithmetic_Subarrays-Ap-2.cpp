#include<bits/stdc++.h>
using namespace std;

vector<bool> arithmaticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> result;

    for(int i = 0; i < l.size(); i++) {
        vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
        sort(begin(arr), end(arr));

        bool isArithmetic = true;
        int diff = arr[1] - arr[0];

        for(int j = 2; j < arr.size(); j++) {
            if(arr[j] - arr[j-1] != diff) {
                isArithmetic = false;
                break;
            }
        }

        result.push_back(isArithmetic);
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int m;
    cin >> m;

    vector<int> l(m);
    vector<int> r(m);

    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
    }

    vector<bool> result = arithmaticSubarrays(nums, l , r);

    for(bool res : result) {
        cout << (res ? "True" : "False") << " ";
    }

    cout << endl;

    return 0;
}

// Approach : Sorting