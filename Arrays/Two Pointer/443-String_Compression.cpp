#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();

    int i = 0;
    int index = 0;

    while(i < n) {
        char curr_char = chars[i];
        int count = 0;

        // Find count of Duplicates
        while(i < n && chars[i] == curr_char) {
            count++;
            i++;
        }

        //Assign it to chars and move index ahead to add the count
        chars[index] = curr_char;
        index++;

        // Add the Count
        if(count > 1) {
            string count_str = to_string(count);
            for(char &ch : count_str) {
                chars[index] = ch;
                index++;
            }
        }
    }
    return index;
}

int main() {
    int n;
    cin >> n;

    vector<char> chars(n);
    for(int i = 0; i<n; i++) {
        cin >> chars[i];
    }

    int result = compress(chars);

    cout << result << endl;
    for (int i = 0; i < result; i++) {
        cout << chars[i];
    }

    return 0;
}