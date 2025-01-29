class Solution {
public:

    int solve(int i, string &s, unordered_set<string> &st, int &n, vector<int> &dp){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1) return dp[i];

        int result = 1 + solve(i+1,s,st,n,dp);

        for(int j=i; j<n; j++){
            string curr = s.substr(i,j-i+1);
            if(st.count(curr)){
                result = min(result, solve(j+1,s,st,n,dp));
            }
        }
        dp[i] = result;
        return dp[i];
    }

    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> st(begin(dict),end(dict));
        int n=s.length();
        vector<int> dp(n+1,-1);
        
        return solve(0,s,st,n,dp);
    }
};