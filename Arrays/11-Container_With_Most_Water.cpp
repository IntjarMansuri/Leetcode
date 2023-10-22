#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0, j = n-1;
    int maxArea = 0;

    while(i < j) {
        int currHeight = min(height[i], height[j]);
        int currWidth = j - i;
        int currArea = currHeight * currWidth;

        maxArea = max(maxArea, currArea);

        if(height[i] < height[j]) {
            i++;
        }
        else {
            j--;
        }
    }
    return maxArea;
}

int main() {
    int n;
    cin >> n;

    vector<int>height(n);
    for(int i = 0; i<n; i++) {
        cin >> height[i];
    }

    int maxarea = maxArea(height);
    cout << maxarea << endl;

    return 0;
}