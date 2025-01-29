class Solution {
public:
    // int longestIncreasingSubsequenceForHeights(vector<int>& heights,vector<vector<int>>& dp, int curr,int prev){
    //     if(curr == heights.size()){
    //         return 0;
    //     }

    //     if(dp[curr][prev+1] != -1){
    //         return dp[curr][prev+1];
    //     }
    //     int cnt=0;

    //     if(prev==-1 || heights[curr]>heights[prev]){
    //         //include
    //         cnt = 1+longestIncreasingSubsequenceForHeights(heights, dp, curr+1, curr);
    //     }

    //     int notCnt = 0+longestIncreasingSubsequenceForHeights(heights, dp, curr+1, prev);

    //     return dp[curr][prev+1] = max(cnt,notCnt);
    // }

    int solveOptimal(vector<int> &heights, int n){
        if(n==0){
            return 0;
        }

        vector<int> helper; //the subsequence it will have it will not be the LIS but its length will be of LIS
        helper.push_back(heights[0]);

        for(int i=1; i<n; i++){
            if(heights[i]>helper.back()){
                helper.push_back(heights[i]);
            }
            else{
                //find index of just bada element int helper
                int index = lower_bound(helper.begin(), helper.end(), heights[i]) - helper.begin();
                helper[index] = heights[i];
            }
        }
        return helper.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // If first values are the same, sort by second value in decreasing order
            }
            return a[0] < b[0]; // Otherwise, sort by first value in increasing order
        });

        vector<int> heights(n);
        int i=0;
        for (int i = 0; i < n; i++) {
            heights[i] = envelopes[i][1];
        }

        //using dp 
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // int ans=longestIncreasingSubsequenceForHeights(heights, dp,  0, -1);

        //SINCE USING DP GIVES MEMORY LIMIT EXCEED SOO USING BINARY SEARCH SPECIAL WAY
        
        
        return solveOptimal(heights, n);
        
    }
};