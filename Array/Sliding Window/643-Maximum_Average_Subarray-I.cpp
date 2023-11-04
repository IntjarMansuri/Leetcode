#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();

    double maxAvg = 0;
    double currentSum = 0;

    for(int i = 0; i<k; i++) {
        currentSum += nums[i];
    }
    maxAvg = currentSum/k;

    for(int i = k; i<n; i++) {
        currentSum += nums[i] - nums[i-k];
        maxAvg = max(maxAvg, currentSum/k);
    }
    return maxAvg;
}

int main() {
    int n;
    cin >> n;

    vector<int>nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    double result = findMaxAverage(nums, k);

    cout << fixed << setprecision(5); // Set precision to 5 decimal places
    cout << result << endl;

    return 0;
}

// Approach : Sliding Window
// Time : O(N)