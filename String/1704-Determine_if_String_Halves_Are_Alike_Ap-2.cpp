#include<bits/stdc++.h>
using namespace std;

bool isVowels(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

bool halvesAreAlike(string s) {
    int n = s.length();
    int mid = n/2;

    int i = 0, j = mid;
    int countA = 0, countB = 0;

    while(i < n/2 && j < n) {
        if(isVowels(s[i]))countA++;

        if(isVowels(s[j]))countB++;

        i++, j++;
    }

    return countA == countB;
}

int main() {
    string s;
    cin >> s;

    bool ans = halvesAreAlike(s);
    cout << (ans ? "True" : "False") << endl;

    return 0;
}

// Approach : Without Set
// Time : O(n), Space : O(1)