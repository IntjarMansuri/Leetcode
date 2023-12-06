#include<bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    if(m != n)
        return false;

    vector<int> freq1(26);
    vector<int> freq2(26);

    for(int i = 0; i<m; i++) {
        char ch1 = word1[i];
        char ch2 = word2[i];

        int idx1 = ch1 - 'a';
        int idx2 = ch2 - 'a';

        freq1[idx1]++;
        freq2[idx2]++;
    }

    // Jo char Word1 me hai Wo Word2 me bhi hone chhaiye
    for(int i = 0; i<26; i++) {
        if(freq1[i] != 0 && freq2[i] != 0) continue;

        if(freq2[i] == 0 && freq2[i] == 0) continue;

        return false;
    }

    // Match Karege Freq
    sort(begin(freq1), end(freq1));
    sort(begin(freq2), end(freq2));

    return freq1 == freq2;
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    bool ask = closeStrings(word1, word2);

    if(ask) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}