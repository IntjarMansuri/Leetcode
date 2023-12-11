#include<bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int>set1(nums1.begin(), nums1.end());
    unordered_set<int>set2(nums2.begin(), nums2.end());

    int count1 = 0, count2 = 0;

    for(int num : nums1) {
        if(set2.find(num) != set2.end()) {
            count1++;
        }
    }

    for(int num : nums2) {
        if(set1.find(num) != set1.end()) {
            count2++;
        }
    }

    return { count1, count2 };
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int>nums1(n1);
    for(int i = 0; i<n1; i++) {
        cin >> nums1[i];
    }

    vector<int>nums2(n2);
    for(int i = 0; i<n2; i++) {
        cin >> nums2[i];
    }

    vector<int> result = findCommonElements(nums1, nums2);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Approach : HaseSet
// Time : O(n1+n2), Space : O(n1+n2)