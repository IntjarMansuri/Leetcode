#include<bits/stdc++.h>
using namespace std;

string removeDupliates(string s, int k) {
    stack<pair<char, int>>st;
    int n = s.length();

    for(int i = 0; i<n; i++) {
        if(!st.empty() && st.top().first == s[i]) {
            st.top().second++;

            if(st.top().second == k) {
                st.pop();
            }
        } else {
            st.push({s[i], 1});
        }
    }

    string result = "";

    while(!st.empty()) {
        for(int i = 0; i<st.top().second; i++) {
            result += st.top().first;
        }
        st.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    string result = removeDupliates(s, k);
    cout << result;

    return 0;
}