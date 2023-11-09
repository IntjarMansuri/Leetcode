#include<bits/stdc++.h>
using namespace std;

int MOD =  1e9+7;

int countHomogenous(string s) {
    int n = s.length();

    int length = 0;
    int result = 0;

    for(int i = 0; i<n; i++) {
        
        if(i > 0 && s[i] == s[i-1]) {
            length += 1;
        }
        else {
            length = 1;
        }
        result = (result + length)% MOD;
    }
    return result;
}

int main() {
    string s;
    cin >> s;

    int ans = countHomogenous(s);
    cout << ans << endl;

    return 0;
}

// Time : 0(n), Space: 0(1)