#include<bits/stdc++.h>
using namespace std;

vector<int> sortByBits(vector<int>& arr) {

    auto lambda = [&](int &a, int &b) {
        int count_a = __builtin_popcount(a);
        int count_b = __builtin_popcount(b);

        if(count_a == count_b) {
            return a < b;
        }

        return count_a < count_b;
    };

    sort(begin(arr), end(arr), lambda);

    return arr;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = sortByBits(arr);
    for(int it : result) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}