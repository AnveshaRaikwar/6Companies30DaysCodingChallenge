class Solution {
public:

    // int LongestCommonSubsequence(string &a, string &b, vector<vector<int>> dp, int i, int j){
    //     if(i>= a.length() || j >= b.length()){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int ans=0;

    //     if(a[i] == b[j]){
    //         //include
    //         ans = 1+LongestCommonSubsequence(a, b, dp, i+1, j+1);
    //     }
    //     else{
    //         ans = max(LongestCommonSubsequence(a, b, dp, i, j+1), LongestCommonSubsequence(a, b, dp, i+1, j));
    //     }

    //     return dp[i][j] = ans;
    // }

    int LongestCommonSubsequence(string &a, string &b){
        vector<vector<int>> dp(a.length()+1, vector<int> (b.length()+1,0));

        for(int i = a.length()-1; i>=0; i--){
            for(int j = b.length()-1; j>=0; j--){
                int ans=0;

                if(a[i] == b[j]){
                    //include
                     ans = 1+dp[i+1][j+1];
                 }
                else{
                     ans = max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] = ans;
            }

        }
        return dp[0][0];
    }

    int palindrome(string &subsequence){
        int n = subsequence.length();
        string reversed = subsequence;
        reverse(reversed.begin(), reversed.end());

        // vector<vector<int>> dp(n, vector<int> (n,-1));
        int palindromeLen = LongestCommonSubsequence(subsequence, reversed);
        return palindromeLen;
    }

    int maxProduct(string s) {
        int n=s.length();

        int ans = 0;
        for(int i=0; i <= (1<<n); i++){
            string x = "" ,y = "";
            for(int j=0; j<n; j++){
                int mask = (1<<j)&i;
                if(mask){
                    x+=s[j];
                }
                else{
                    y+=s[j];
                }
            }
            ans = max( ans , palindrome(x) * palindrome(y));
        }

        return ans;
    }
};