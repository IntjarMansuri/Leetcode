#include<bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2) {
    if(word1.length() != word2.length()) {
        return false;
    }

    unordered_map<char, int> freq1, freq2;
    unordered_set<char> chars1, chars2;

    // Count chracter freq and reciord unique charater in each word
    for(char ch : word1) {
        freq1[ch]++;
        chars1.insert(ch);
    }

    for(char ch : word2) {
        freq2[ch]++;
        chars2.insert(ch);
    }

    // Check if the sets of unique character are the same
    if(chars1 != chars2) {
        return false;
    }

    // check if the sorted freq are the same
    vector<int> freqList1, freqList2;
    for(char ch : chars1) {
        freqList1.push_back(freq1[ch]);
        freqList2.push_back(freq2[ch]);
    }

    sort(freqList1.begin(), freqList1.end());
    sort(freqList2.begin(), freqList2.end());

    return freqList1 == freqList2;
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    bool ask = closeStrings(word1, word2);
    cout << (ask ? "True" : "False") << endl;

    return 0;
}