class Solution {
public:

    vector<int> zmatch(string s){
        vector<int> z(s.size(),0);
        int l=0,r=0;

        for(int i=1; i<s.size(); i++){
            if(i<r){
                z[i] = min(r-i,z[i-l]);
                }
            
            while(i+z[i]<s.size() && s[z[i]] == s[i+z[i]]){
                z[i]++;
            }

            //out of boundary check if more same chars
            if(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }
        return z;
    }

    long long sumScores(string s) {
        vector<int> z = zmatch(s);

        long long sum=0;

        for(auto it:z){
            sum+=it;
        }
        sum+=s.size();
        return sum;
    }
};