#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Create a matrix of size n x m for the transposed result
    vector<vector<int>> result(n, vector<int>(m));

    // Iterate through the original matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            // Transpose the elements
            result[j][i] = matrix[i][j];
        }
    }

    // Return the transposed matrix
    return result;
}

int main() {
    // Input the dimensions of the matrix
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    // Input the elements of the matrix
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Call the transpose function
    vector<vector<int>> result = transpose(matrix);

    // Output the transposed matrix
    cout << "Transposed Matrix:" << endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
