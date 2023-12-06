#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    vector<int>vec(2001, 0);

    for(int num : arr) {
        vec[num + 1000]++;
    }

    sort(begin(vec), end(vec));

    for(int i = 1; i<2001; i++) {
        if(vec[i] != 0 && vec[i] == vec[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    bool ask = uniqueOccurrences(arr);

    if(ask) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}