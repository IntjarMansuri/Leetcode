#include<bits/stdc++.h>
using namespace std;

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int result = 0;

    for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {

            if(mat[row][col] == 0) continue;
            bool special  = true;

            // check column
            for(int r = 0; r<m; r++) {
                if(r != row && mat[r][col] == 1) {
                    special = false;
                    break;
                }
            }

            // check row
            for(int c = 0; c<n; c++) {
                if(c != col && mat[row][c] == 1) {
                    special = false;
                    break;
                }
            }

            if(special == true) {
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

// Approach : Brutforce
// Time : O(m*n) + (m+n),  Space : O(1)