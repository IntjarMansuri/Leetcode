#include<bits/stdc++.h>
using namespace std;

bool isPowerFour(int n) {
    if(n <= 0) {
        return false;
    }

    if(n == 1) {
        return true;
    }

    if(n % 4 != 0) {
        return false;
    }

    return isPowerFour(n/4);
}

int main() {
    int n;
    cin >> n;

    bool chk = isPowerFour(n);
    if(chk) cout << "Yes" << endl;
    else cout << "NO" << endl;

    return 0;
}