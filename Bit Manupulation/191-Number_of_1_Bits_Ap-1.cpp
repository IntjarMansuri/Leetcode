#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
        
    for(int i = 31; i>=0; i--) {
        if(((n >> i) & 1) == 1) {
            count++;
        }
    }
        
    return count;
}

int main() {
    uint32_t n;
    cin >> n;

    int result = hammingWeight(n);
    cout << result;

    return 0;
}

//Approach-1 (Using simple right shift operator)
//T.C : O(1) - because the loop in the code iterates 32 times, which is a constant number regardless of the input n
//S.C : O(1)