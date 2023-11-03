#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0;
    int j = 0;

    while(i < s.length() && j < t.length()) {
        
        if(s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == s.length();
}

int main() {
    string s;
    cin >> s;

    string t;
    cin >> t;

    bool ans = isSubsequence(s, t);

    if(ans) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}