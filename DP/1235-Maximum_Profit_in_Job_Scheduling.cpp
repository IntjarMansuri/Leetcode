#include<bits/stdc++.h>
using namespace std;

int n;
int dp[50001];

// Find the first job jiska >= current job ka end point
int getNextJob(vector<vector<int>>& arr, int l, int currentJobEnd) {
    int r = n-1;
    int result = n+1;

    while(l <= r) {
        int mid = l + (r - l)/2;

        if(arr[mid][0] >= currentJobEnd) {
            result = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return result;
}

int solve(vector<vector<int>>& arr, int i) {
    if (i >= n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int next = getNextJob(arr, i + 1, arr[i][1]);
    int taken = arr[i][2] + solve(arr, next);
    int notTaken = solve(arr, i + 1);

    return dp[i] = max(taken, notTaken);
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    n = startTime.size();
    memset(dp, -1, sizeof(dp));

    vector<vector<int>> arr(n, vector<int>(3, 0)); // {s, e, p}

    for(int i = 0; i < n; i++) {
        arr[i][0] = startTime[i];
        arr[i][1] = endTime[i];
        arr[i][2] = profit[i];
    }

    auto comp = [&](auto& vec1, auto& vec2) {
        return vec1[0] <= vec2[0];
    };


    // sort karenge accrording to startTime
    sort(begin(arr), end(arr), comp);
    return solve(arr, 0);
}

int main() {
    int n;
    cin >> n;

    vector<int>startTime(n);
    for(int i = 0; i<n; i++) {
        cin >> startTime[i];
    }
    vector<int>endTime(n);
    for(int i = 0; i<n; i++) {
        cin >> endTime[i];
    }
    vector<int>profit(n);
    for(int i = 0; i<n; i++) {
        cin >> profit[i];
    }

    int result = jobScheduling(startTime, endTime, profit);
    cout << result << endl;

    return 0;
}

// Approach : Recursion + Memoigation