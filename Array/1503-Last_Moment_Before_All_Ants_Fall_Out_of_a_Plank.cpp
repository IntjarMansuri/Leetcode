#include<bits/stdc++.h>
using namespace std;

int getLastMoment(int n, vector<int>& left, vector<int>& right) {

    int maxTime = 0;

    for(int x : left) {
        maxTime = max(maxTime, x);
    }

    for(int x : right) {
        maxTime = max(maxTime, n-x);
    }

    return maxTime;
}

int main() {
    int n;
    cin >> n;

    int l;
    cin >> l;

    vector<int>left(l);
    for(int i = 0; i<l; i++) {
        cin >> left[i];
    }

    int r;
    cin >> r;

    vector<int>right(r);
    for(int i = 0; i<r; i++) {
        cin >> right[i];
    }

    int ans = getLastMoment(n, left, right);
    cout << ans << endl;

    return 0;
}

// Time : O(n*m), Space : O(1)