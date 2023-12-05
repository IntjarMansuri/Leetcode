#include<bits/stdc++.h>
using namespace std;

int numberOfMatches(int n) {
    int matches = 0;

    while(n > 1) {
        if(n % 2 == 0) {  //Even Teams
            matches += n/2;
            n = n/2;
        }
        else {
            matches += (n-1)/2;
            n = (n-1)/2+1;
        }
    }
    return matches;
}

int main() {
    int n;
    cin >> n;

    int ans = numberOfMatches(n);
    cout << ans;

    return 0;
}

// Approache : Using Simple Simulation
// Time : O(log n), Space : O(1)