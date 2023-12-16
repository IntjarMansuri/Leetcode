#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {

    vector<int>freq(26, 0);

    for(int i = 0; i<s.size(); i++) {
        freq[s[i] - 'a']++;
    }

    for(int i = 0; i<t.size(); i++) {
        freq[t[i] - 'a']--;
    }

    for(int i = 0; i<26; i++) {
        if(freq[i] != 0) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    string t;
    cin >> t;

    bool result = isAnagram(s, t);
    cout << (result ? "true" : "false");

    return 0;
}

// Time : O(n), Space : O(1)