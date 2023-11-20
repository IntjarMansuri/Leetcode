#include<bits/stdc++.h>
using namespace std;

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    
    int hor_dist = abs(sy - fy);
    int ver_dist = abs(sx - fx);

    if(hor_dist == 0 && ver_dist == 0 && t == 1) {
        return false;
    }

    int minTime = max(hor_dist, ver_dist);

    if(t < minTime) {
        return false;
    }
    return true;
}

int main() {
    int sx, sy, fx, fy, t;
    cin >> sx >> sy >> fx >> fy >> t;

    bool chk = isReachableAtTime(sx, sy, fx, fy, t);
    if(chk) {
        cout << "True" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

// Time : O(1)