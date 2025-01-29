class Solution {
public:

    void findIndex(string &s, string &x, vector<int> &v){
        auto pos = s.find(x,0);

        if(pos == string::npos) return;

        while(pos != string::npos){
            v.push_back(pos);
            pos = s.find(x,pos+1);
        }
        return;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> m,n;

        findIndex(s,a,m);
        findIndex(s,b,n);

        vector<int> ans;
        for(auto i:m){
            for(auto j:n){
                if(abs(i-j)<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};