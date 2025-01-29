class Solution {
public:

    map<vector<int>,int> dp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        
        if(dp.count(needs)!=0){
            return dp[needs];
        }

        int ans=0;
        for(int i=0; i<price.size(); i++){
            ans += (price[i] * needs[i]);
        }

        for(int i=0; i< special.size(); i++){
            bool isSafeOffer=true;
            for(int j=0; j<needs.size(); j++){
                if(needs[j]<special[i][j]){
                    isSafeOffer = false;
                    break;
                }
            }
            if(isSafeOffer){
                for(int j=0; j<needs.size(); j++){
                    needs[j] -= special[i][j];
                }
                
                int ans2 = special[i].back() + shoppingOffers(price, special, needs);
                ans = min(ans,ans2);

                //backtrack
                for(int j=0; j<needs.size(); j++){
                    needs[j] += special[i][j];
                }
            }
        }
        
        return dp[needs]=ans;
    }
};