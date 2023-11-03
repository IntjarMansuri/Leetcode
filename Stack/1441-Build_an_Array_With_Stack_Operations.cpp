#include<bits/stdc++.h>
using namespace std;

vector<string> buildArray(vector<int>& target, int n) {

    int stream = 1;
    vector<string> result;
    int i = 0;

    while(i < target.size() && stream <= n) {
        result.push_back("Push");

        if(target[i] == stream) {
            i++;
        }
        else {
            result.push_back("Pop");
        }
        stream++;
    }
    return result;
}

int main() {
    int d;
    cin >> d;

    vector<int> target(d);
    for(int i = 0; i<d; i++) {
        cin >> target[i];
    }

    int n;
    cin >> n;

    vector<string> result = buildArray(target, n);
    for(auto it : result) {
        cout << it <<", ";
    }
    cout << endl;

    return 0;
}