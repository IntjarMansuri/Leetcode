#include<bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k) {

    sort(begin(nums), end(nums));

    int count = 0;
    int i = 0;
    int j = nums.size()-1;

    while(i < j) {
        int sum = nums[i] + nums[j];

        if(sum == k) {
            count++;
            i++;
            j--;
        } else if(sum < k) {
            i++;
        } else {
            j--;
        }
    }
    return count++;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    int result = maxOperations(nums, k);

    cout << result << endl;

    return 0;
}