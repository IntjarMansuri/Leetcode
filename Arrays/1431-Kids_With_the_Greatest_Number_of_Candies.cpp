#include<bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int n = candies.size();

    int maxCandies = *max_element(begin(candies), end(candies));

    vector<bool> ans(n, false);

    for(int i = 0; i<n; i++) {
        if(candies[i] + extraCandies >= maxCandies) {
            ans[i] = true;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int>candies(n);
    for(int i = 0; i<n; i++) {
        cin >> candies[i];
    }

    int extraCandies;
    cin >> extraCandies;

    vector<bool> result = kidsWithCandies(candies, extraCandies);
    for (int i = 0; i < n; i++) {
        cout << (result[i] ? "true" : "false");
        if (i < n - 1) {
            cout << ",";
        }
    }

    return 0;
}