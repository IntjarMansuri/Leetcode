#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {

    // Base Case
    if(n <= 1) {
        return 1;
    }

    // Recursive Call
    return n* factorial(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << factorial(n) << endl;
    return 0;
}