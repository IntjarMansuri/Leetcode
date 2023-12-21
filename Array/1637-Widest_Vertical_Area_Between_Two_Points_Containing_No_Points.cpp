#include<bits/stdc++.h>
using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    int n = points.size();

    sort(begin(points), end(points));

    int result = 0;

    for(int i = 1; i<n; i++) {
        int width = points[i][0] - points[i-1][0];
        result = max(result, width);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for(int i = 0; i<n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    int result = maxWidthOfVerticalArea(points);
    cout << result << endl;

    return 0;
}

// Time : O(log n)