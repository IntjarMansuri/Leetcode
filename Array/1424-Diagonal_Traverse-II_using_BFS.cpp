#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    vector<int> result;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        int row = p.first;
        int col = p.second;

        result.push_back(nums[row][col]);

        if (row + 1 < nums.size() && col == 0) {
            q.push(make_pair(row + 1, col));
        }

        if (col + 1 < nums[row].size()) {
            q.push(make_pair(row, col + 1));
        }
    }
    return result;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }

    vector<int> result = findDiagonalOrder(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Approach : Using BFS
// Time : O(n), Space : O(n)
