#include<bits/stdc++.h>
using namespace std;

int totalMoney(int n) {
    int terms = n/7;
    int first = 28;
    int last = 28 + (terms-1)*7;   // Ap formula for nth terms
    
    int result = terms * (first + last)/2;
    int start_money = 1 + terms;
    for(int day = 1; day <= (n%7); day++) {
        result += start_money;
        start_money++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    int result = totalMoney(n);
    cout << result;

    return 0;
}

// Approsch : Math Using Ap nth formula
// Time : O(1), Space : O(1)