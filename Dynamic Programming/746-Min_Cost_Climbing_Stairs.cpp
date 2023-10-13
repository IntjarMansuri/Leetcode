#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if(n == 2) {
        return min(cost[0], cost[1]);
    }

    for(int i = 2; i<n; i++) {
        cost[i] = cost[i] + min(cost[i-1], cost[i-2]);
    }
    return min(cost[n-1], cost[n-2]);
}

int main() {
    int n;
    cin >> n;

    vector<int>cost(n);
    for(int i = 0; i<n; i++) {
        cin >> cost[i];
    }

    int minCost = minCostClimbingStairs(cost);
    cout << minCost << endl;

    return 0;
}

// T.C = O(n)