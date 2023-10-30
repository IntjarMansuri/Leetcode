#include<bits/stdc++.h>
using namespace std;

int countOneBits(int num) {

    int count = 0;

    while(num) {
        count += num &1;
        num >>= 1;
    }

    return count;
}

vector<int> sortByBits(vector<int>& arr) {

    auto lambda = [&](int &a, int &b) {
        int count_a = countOneBits(a);
        int count_b = countOneBits(b);

        if(count_a == count_b)
            return a < b;

        return count_a < count_b;
        
    };

    sort(begin(arr), end(arr), lambda);

    return arr;
}


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> result = sortByBits(arr);
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

// Approach : Bit Manupulation
// Time Compllexity : O(N * log(N) * M)