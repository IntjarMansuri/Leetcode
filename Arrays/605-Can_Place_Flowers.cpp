#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowersBed, int m) {

    int l = flowersBed.size();

    if(m == 0) {
        return true;
    }

    for(int i = 0; i<l; i++) {

        if(flowersBed[i] == 0) {
            
            bool leftEmpty = (flowersBed[i-1] == 0) || (i == 0);
            bool rightEmpty = (flowersBed[i+1] == 0) || (i == l - 1);

            if(leftEmpty && rightEmpty) {
                flowersBed[i] = 1;
                m--;

                if(m == 0){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {a
    int n;
    cin >> n;

    vector<int>flowersBed(n);
    for(int i = 0; i<n; i++) {
        cin >> flowersBed[i];
    }

    int m;
    cin >> m;

    bool ans = canPlaceFlowers(flowersBed, m);
    if(ans) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}