#include<bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ']') {
            // Pop until '[' is encountered
            while (!st.empty() && st.top() != '[') {
                ans = st.top() + ans;
                st.pop();
            }

            // Pop the '['
            if (!st.empty()) {
                st.pop();

                // Extract the number
                string number = "";
                while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                    number = st.top() + number;
                    st.pop();
                }

                // Apply multiplication effect
                int digit = stoi(number);
                string temp = ans;

                for (int i = 0; i < digit - 1; i++) {
                    ans += temp;
                }

                // Push characters back to the stack in the correct order
                for (char c : ans) {
                    st.push(c);
                }
                ans = "";
            }
        } else {
            st.push(s[i]);
        }
    }

    // Pop remaining characters from the stack
    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    string result = decodeString(s);
    cout << result << endl;

    return 0;
}