#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    int n = s.length();

    string ans = "";

    for (int i = 0; i < n; i++) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s;
    cin >> s;

    string result = removeDuplicates(s);
    cout << result;

    return 0;
}
