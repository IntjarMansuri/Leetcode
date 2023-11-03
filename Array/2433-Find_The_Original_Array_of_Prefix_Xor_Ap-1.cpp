#include<bits/stdc++.h>
using namespace std;

vector<int> findArray(vector<int>& pref) {
    
    int n = pref.size();

    vector<int>arr;
    arr.push_back(pref[0]);

    for(int i = 1; i < n; i++) {
        arr.push_back(pref[i] ^ pref[i-1]);
    }

    return arr;
}

int main() {
    int n;
    cin >> n;

    vector<int>pref(n);
    for(int i = 0; i < n; i++) {
        cin >> pref[i];
    }

    vector<int> result = findArray(pref);
    for(int it : result) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

// Approach : Bit Manupulation + Extra Space
// T.C = O(N)
// S.C = O(N)