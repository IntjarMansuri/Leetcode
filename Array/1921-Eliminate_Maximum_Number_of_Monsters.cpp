#include<bits/stdc++.h>
using namespace std;

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();

    vector<int> time(n);

    for(int i = 0; i<n; i++) {
        time[i] = ceil((float)dist[i]/speed[i]);
    }

    sort(begin(time), end(time));

    int count = 1;
    int time_passed = 1;

    for(int i=1; i<n; i++) {
        if(time[i] - time_passed <= 0) {
            return count;
        }
        count++;
        time_passed += 1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> dist(n);
    for(int i = 0; i<n; i++) {
        cin >> dist[i];
    }

    vector<int> speed(n);
    for(int i = 0; i<n; i++) {
        cin >> speed[i];
    }

    int result = eliminateMaximum(dist, speed);
    cout << result << endl;

    return 0;
}

// Approach : Simple Greedy
// Time : O(nlogn)