#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int>st;

    for(int ast : asteroids) {

        while(!st.empty() && ast < 0 && st.back() > 0) {
            int sum = ast + st.back();

            if(sum < 0) {
                st.pop_back();
            } else if(sum > 0) {
                ast = 0;
            } else {
                st.pop_back();
                ast = 0;
            }
        }
        if(ast != 0) {
            st.push_back(ast);
        }
    }
    return st;
}

int main() {
    int n;
    cin >> n;

    vector<int>asteroids(n);
    for(int i = 0; i<n; i++) {
        cin >> asteroids[i];
    }

    vector<int> result = asteroidCollision(asteroids);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Time : O(n),  Space: O(n)