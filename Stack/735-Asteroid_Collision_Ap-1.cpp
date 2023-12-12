#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int>st;
    for(int &a : asteroids) {
        
        while(!st.empty() && a < 0 && st.top() > 0) {
            int sum = a + st.top();

            if(sum < 0) {
                st.pop();
            } else if(sum > 0) {
                a = 0;
            } else {
                st.pop();
                a = 0;
            }
        }

        if(a != 0) {
            st.push(a);
        }
    }

    int s = st.size();
    vector<int>result(s);
    int i = s-1;
    while(!st.empty()) {
        result[i] = st.top();
        st.pop();
        i--;
    }
    return result;
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

// Time : O(n), Space : O(n)