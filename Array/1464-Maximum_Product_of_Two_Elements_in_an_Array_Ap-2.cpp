#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int largest = 0;
    int sec_largest = 0;

    for(int num : nums) {
        if(num > largest) {
            sec_largest = largest;
            largest = num;
        } else {
            sec_largest = max(sec_largest, num);
        }
    }

    return (largest-1) * (sec_largest-1);
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int result = maxProduct(nums);
    cout << result << endl;

    return 0;
}