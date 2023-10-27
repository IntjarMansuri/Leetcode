#include<bits/stdc++.h>
using namespace std;

// Approach : Brutforce
// Time Complexity : O(2^n)

int solve(int n) {
    if(n < 0) 
        return 0;

    if(n == 0)
        return 1;

    int one_step = solve(n-1);
    int two_step = solve(n-2);

    return one_step + two_step;
}

int climbStairs(int n) {
    return solve(n);
}

int main() {
    int n;
    cin >> n;

    int ans = climbStairs(n);
    cout << ans << endl;

    return 0;
}