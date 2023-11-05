#include<bits/stdc++.h>
using namespace std;

int getWinner(vector<int>& arr, int k) {
    int n = arr.size();
    int maxElement = *max_element(begin(arr), end(arr));
    
    if(k >= n)   // Rotate --> Max element come at index O atleast once
        return maxElement;

    int winner = arr[0];
    int streak = 0;

    for(int i = 0; i<n; i++) {
        if(arr[i] > winner) {
            winner = arr[i];
            streak = 1;
        }
        else {
            streak++;
        }

        if(streak == k || winner == maxElement)
            return winner;
    }
    return winner;
}

int main() {
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int result = getWinner(arr, k);
    cout << result << endl;

    return 0;
}

// Time : O(n)