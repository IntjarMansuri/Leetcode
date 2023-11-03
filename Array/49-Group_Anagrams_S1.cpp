#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& str) {
    int n = str.size();
    vector<vector<string>>result;
    unordered_map<string, vector<string>>mp;

    for(int i = 0; i<n; i++) {
        string temp = str[i];

        sort(begin(temp), end(temp));
        mp[temp].push_back(str[i]);
    }

    for(auto it : mp) {
        result.push_back(it.second);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string>str(n);
    for(int i = 0; i<n; i++) {
        cin >> str[i];
    }

    vector<vector<string>> result = groupAnagrams(str);
    for(auto ans : result) {
        for(auto it : ans) {
            cout << it << ", ";
        }
        cout << endl;
    }

    return 0;
}

// T.C = O(n*k log k)