#include<bits/stdc++.h>
using namespace std;

bool isVowels(char &ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

string reverseVowels(string s) {
    int i = 0;
    int j = s.length()-1;

    while(i < j) {
        if(!isVowels(s[i])) {
            i++;
        }
        else if(!isVowels(s[j])) {
            j--;
        }
        else {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    return s;
}

int main() {
    string s;
    cin >>  s;

    string ans = reverseVowels(s);
    cout << ans;

    return 0;
}