#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findDiffrence(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int>set1(nums1.begin(), nums1.end());
    unordered_set<int>set2(nums2.begin(), nums2.end());

    vector<int>vec1;
    vector<int>vec2;

    for(int num : set1) {
        if(set2.find(num) == set2.end()) {
            vec1.push_back(num);
        }
    }

    for(int num : set2) {
        if(set1.find(num) == set1.end()) {
            vec2.push_back(num);
        }
    }

    return {vec1, vec2};
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> nums1(n1), nums2(n2);
    for(int i = 0; i<n1; i++) {
        cin >> nums1[i];
    }

    for(int i = 0; i<n2; i++) {
        cin >> nums2[i];
    }

    vector<vector<int>>result = findDiffrence(nums1, nums2);

    cout << "Output: [";
    for (int num : result[0]) {
        cout << num << ",";
    }
    cout << "], [";
    for (int num : result[1]) {
        cout << num << ",";
    }
    cout << "]" << endl;

    return 0;
}