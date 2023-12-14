#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> rowOnes(m, 0);
    vector<int> colOnes(n, 0);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                rowOnes[i] += 1;
                colOnes[j] += 1;
            }
        }
    }

    vector<vector<int>> diff(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int onesRowi = rowOnes[i];
            int onesColj = colOnes[j];
            int zerosRowi = n - onesRowi;
            int zerosColj = m - onesColj;

            diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
        }
    }
    return diff;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> result = onesMinusZeros(grid);

    // Printing the result for demonstration
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time : O(m*n), Space : O(m + n)