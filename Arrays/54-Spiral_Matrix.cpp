#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.size() == 0)
        return {};

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int>result;

    int top = 0;
    int down = n-1;
    int left = 0;
    int right = m-1;

    int dir = 0;

    while(top <= down && left <= right) {
        // Left to right
        if(dir == 0) {
            for(int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
        }

        // Top to down
        if(dir == 1) {
            for(int i = top; i <= down; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
        }

        // Right to Left
        if(dir == 2) {
            for(int i = right; i >= left; i--) {
                result.push_back(matrix[down][i]);
            }
            down--;
        }

        // Down to Top
        if(dir == 3) {
            for(int i = down; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }

        dir = (dir + 1)%4;
    }
    return result;
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

    vector<int> result = spiralOrder(matrix);
    for(auto x: result) {
        cout << x << " ";
    }
    
    return 0;
}