
// T.C : O(N)
// S.C : O(1)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>result(n);

        int maxi = *max_element(begin(score), end(score));
        vector<int>arr(maxi+1, -1);

        for(int i = 0; i < n; i++) {
            arr[score[i]] = i;
        }
        int rank = 1;
        for(int i = maxi; i >= 0; i--) {
            if(arr[i] != -1) {
                int ath = arr[i];

                if(rank == 1) {
                    result[ath] = "Gold Medal";
                }
                else if(rank == 2) {
                    result[ath] = "Silver Medal";
                } else if(rank == 3) {
                    result[ath] = "Bronze Medal";
                }
                else {
                    result[ath] = to_string(rank);
                }
                rank++;
            }
        }
        return result;
    }
};