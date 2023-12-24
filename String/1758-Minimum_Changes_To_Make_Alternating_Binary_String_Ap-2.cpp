#include<bits/stdc++.h>
using namespace std;

int minOperations(string s) {
    int n = s.length();
    int start_with_zero = 0;

    for(int i = 0; i<n; i++) {
        if(i % 2 == 0) {
            if(s[i] == '1')
                start_with_zero++;
        } else {
            if(s[i] == '0')
                start_with_zero++;
        }
    }

    int start_with_one = n - start_with_zero;

    return min(start_with_zero, start_with_one);
}

int main() {
    string s;
    cin >> s;

    int result = minOperations(s);
    cout << result << endl;

    return 0;
}