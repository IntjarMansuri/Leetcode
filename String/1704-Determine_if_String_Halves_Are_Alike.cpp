#include<bits/stdc++.h>
using namespace std;

bool halvesAreAlike(string s) {
    int n = s.length();
    int mid = n/2;

    int i = 0, j = mid;
    int countA = 0, countB = 0;

    unordered_set<char>vowels{'a','e','i','o','u','A','E','I','O','U'};

    while(i < n/2 && j < n) {
        if(vowels.find(s[i]) != vowels.end()) countA++;

        if(vowels.find(s[j]) != vowels.end()) countB++;

        i++, j++;
    }

    return countA == countB;
}

int main() {
    string s;
    cin >> s;

    bool ans = halvesAreAlike(s);
    cout << (ans ? "true" : "false") << endl;

    return 0;
}

// Approach : Using Set
// Time : O(n), Space : O(1)