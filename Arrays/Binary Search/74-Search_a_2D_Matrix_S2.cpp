#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int start = 0, end = n*m-1;
    
    while(start <= end) {
        int mid = start + (end - start)/2;

        int row = mid/m;
        int col = mid%m;

        if(matrix[row][col] > target) {
            end = mid-1;
        }
        else if(matrix[row][col] < target) {
            start = mid+1;
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
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
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

// T.C = O(log(n*m))