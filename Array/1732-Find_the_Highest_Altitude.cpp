#include<bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int currAltitude = 0;
    int highAltitude = 0;

    for(int i = 0; i<gain.size(); i++) {
        currAltitude += gain[i];

        highAltitude = max(highAltitude, currAltitude);
    }
    return highAltitude;
}

int main() {
    int n;
    cin >> n;

    vector<int>gain(n);
    for(int i = 0; i<n; i++) {
        cin >> gain[i];
    }

    int result = largestAltitude(gain);
    cout << result;

    return 0;
}

// Time : O(n), Space : O(1)