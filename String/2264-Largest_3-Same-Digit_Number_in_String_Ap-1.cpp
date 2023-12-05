#include<bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num) {
    int n = num.length();
    
    char maxChar = ' ';

    for(int i = 2; i<n; i++) {
        if(num[i] == num[i-1] && num[i] == num[i-2]) {
            maxChar = max(maxChar, num[i]);
        }
    }

    if(maxChar == ' ') {
        return "";
    }

    return string(3, maxChar);
}

int main() {
    string num;
    cin >> num;

    string result = largestGoodInteger(num);
    cout << result;

    return 0;
}

// Time : O(n)