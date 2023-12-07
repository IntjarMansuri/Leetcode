#include<bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int count = 0;

    for(int r = 0; r<n; r++) {
        for(int c = 0; c<n; c++) {
            
            int isEqual = true;
            for(int i = 0; i<n; i++) {
                if(grid[r][i] != grid[i][c]) {
                    isEqual = false;
                    break;
                }
            }
            count += isEqual;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = equalPairs(grid);
    cout << result << endl;

    return 0;
}

// Approach : Brutforce
// Time : O(n^3)