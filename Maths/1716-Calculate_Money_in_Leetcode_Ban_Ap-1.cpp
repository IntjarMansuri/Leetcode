#include<bits/stdc++.h>
using namespace std;

int totalMoney(int n) {
    int result = 0;
    int firstDay = 1;

    while(n > 0 ){
        int money = firstDay;
        for(int day = 1; day <= min(n, 7); day++) {
            result += money;
            money++;
        }
        n -= 7;
        firstDay++;
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

// Approach : Simple Simulation
// Time : O(n), Space : O(1)