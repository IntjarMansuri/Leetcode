#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
        
    while(n) {
        n = (n&(n-1)); 
        count++;
    }
        
    return count;
}

int main() {
    uint32_t n;
    cin >> n;

    int result = hammingWeight(n);
    cout << result ;

    return 0;
}

//Approach-2 (Using simple bit magic)
//T.C : O(k) -> Where k = number of set bits (1s) in input 'n'
//S.C : O(1)