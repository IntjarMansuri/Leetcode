#include<bits/stdc++.h>
using namespace std;

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int>rowCount(m, 0);  // How many 1s in a row
    vector<int>colCount(n, 0);   // How many 1s in a col

    for(int row = 0; row<m; row++) {
        for(int col = 0; col<n; col++) {
            if(mat[row][col] == 1) {
                rowCount[row]++;
                colCount[col]++;
            }
        }
    }

    int result = 0;
    for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {
            if(mat[row][col] == 0) continue;

            if(rowCount[row] == 1 && colCount[col] == 1) {
                result++;
            }
        }
    }

    return result;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    int result = numSpecial(mat);
    cout << result << endl;

    return 0;
}

// Approach : Better Approach
// Time : O(m*n), Space : O(m+n)