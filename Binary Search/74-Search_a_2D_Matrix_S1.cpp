#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> & matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0; 
    int end = row - 1;

    while( start < row && end >= 0) {
        if(matrix[start][end] > target) {
            end--;
        }
        else if(matrix[start][end] < target) {
            start++;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    bool chk = searchMatrix(matrix, target);
    if(chk) {
        cout << "Target Found" << endl;
    }
    else {
        cout << "Not Found!";
    }

    return 0;
}

// T.C = O(n*m)