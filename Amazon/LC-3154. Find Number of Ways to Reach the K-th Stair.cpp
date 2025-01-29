class Solution {
public:

    vector<long long> power;
    unordered_map<string,int> mp;

    int solve(int i, int jump, int canGoBack, int k){
        if(i > k+1){
            return 0;
        }
        
        string key = to_string(i)+"_"+to_string(jump)+"_"+to_string(canGoBack);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }

        int ways = 0;

        if(i == k){
            ways += 1;
        }
        //i-1
        if(canGoBack == 1){
            ways += solve(i-1, jump, 0, k);
        }
        ways += solve(i+power[jump], jump+1, 1, k);

        return  mp[key] = ways;
    }
    int waysToReachStair(int k) {
        power.resize(32);
        for(int i=0; i<=31; i++){
            power[i] = pow(2,i);
        }
        return solve(1,0, 1, k);
    }
};