class Solution {
public:

    int solveBU(vector<int>& prices,  vector<vector<vector<int>>> &dp, int k){

        for(int i=prices.size()-1; i>=0; i--){
            
            for(int buy = 0; buy < 2; buy++){
                for(int limit =1; limit < k+1; limit++){
                    int profit = 0;
                    if(buy){
                        int Buyprofit = -prices[i] + dp[i+1][0][limit]; //solveRecursion(prices, i+1, 0, limit);
                        int skip = 0 + dp[i+1][1][limit]; // solveRecursion(prices, i+1, 1, limit);
                        profit = max(skip, Buyprofit);
                    }
                    else{
                        //sell
                        int Sellprofit = prices[i] + dp[i+1][1][limit-1]; // solveRecursion(prices, i+1, 1, limit-1);
                        int skip = 0 + dp[i+1][0][limit];  //solveRecursion(prices, i+1, 0, limit);
                        profit = max(skip, Sellprofit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }

        }
        return dp[0][1][k];
    }

    int maxProfit( int k, vector<int>& prices) {

        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2,vector<int>(k+1,0)));
        return solveBU(prices, dp, k);
    }
};