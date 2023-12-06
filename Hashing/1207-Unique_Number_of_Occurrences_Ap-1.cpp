#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int>mp;

    // store frequency of each number
    for(int num : arr) {
        mp[num]++;
    }

    unordered_set<int>st;
    for(auto num : mp) {
        int freq = num.second;

        if(st.find(freq) != st.end()) {
            return false;
        }
        st.insert(freq);
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    bool ask = uniqueOccurrences(arr);

    if(ask) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}