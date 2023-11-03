#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout<< "Enter matrix elements:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

    cout << "Rotated Matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}