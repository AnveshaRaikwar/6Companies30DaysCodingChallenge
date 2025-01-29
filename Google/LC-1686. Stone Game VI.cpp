class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<vector<int>> v(n);

        for(int i=0; i<n; i++){
            v[i] = {-aliceValues[i]-bobValues[i],i};
        }
        sort(v.begin(),v.end());
        int f=1;
        int a=0,b=0;
        for(auto x:v){
            if(f == 1) a += aliceValues[x[1]];
            else b += bobValues[x[1]];
            f=1-f;
        }
        if(a>b) return 1;
        if(b==a) return 0;
        return -1;

    }
};