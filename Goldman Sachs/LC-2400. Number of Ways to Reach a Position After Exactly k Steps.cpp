#define MOD 1000000007
class Solution {
public:
    long long solve(vector<vector<int> > &dp, int x,int y, int k){
        if(k==0 && x==y){
            return 1;
        }
        if(k==0){
            return 0;
        }

        if(dp[x+1000][k]!=-1){
            return dp[x+1000][k];
        }

        long long cnt=0;
        cnt += solve(dp,x-1,y,k-1);
        cnt += solve(dp,x+1,y,k-1);
        
        dp[x+1000][k] = cnt%MOD;
        return dp[x+1000][k];
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int> > dp(4001,vector<int>(2001,-1));

        long long ans = solve(dp,startPos,endPos,k);
        return ans%MOD;
    }
};
 


 