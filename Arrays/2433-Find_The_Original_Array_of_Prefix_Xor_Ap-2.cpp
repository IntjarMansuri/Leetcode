#include<bits/stdc++.h>
using namespace std;

vector<int> findArray(vector<int>& pref) {
    int n = pref.size();

    for(int i = n-1; i > 0; i--) {
        pref[i] = pref[i] ^ pref[i-1];
    }

    return pref;
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

// Approach : Bit Manupulation , No Extra Space 
// T.C : O(N)