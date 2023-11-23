#include<bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    unordered_map<int, vector<int>>mp;   // row + col, elements

    for(int row = nums.size()-1; row>=0; row--) {
        for(int col = 0; col<nums[row].size(); col++) {
            int diag = row + col;

            mp[diag].push_back(nums[row][col]);
        }
    }

    vector<int>result;
    int diagonal = 0;

    while(mp.find(diagonal) != mp.end()) {
        for(int &num : mp[diagonal]) {
            result.push_back(num);
        }
        diagonal++;
    }
    return result;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> nums(m, vector<int>(n));
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            cin >> nums[i][j];
        }
    }

    vector<int> result = findDiagonalOrder(nums);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Approach : Using Map
// Time : O(n), Space : O(n)