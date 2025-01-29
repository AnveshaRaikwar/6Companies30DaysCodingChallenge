class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bull=0,cow=0,valid_no=0;

        unordered_map<char,int> map1,map2;

        for(int i=0; i<n; i++){
            if(secret[i]==guess[i]) bull++;
            else{
                map1[secret[i]]++;
                map2[guess[i]]++;
            }
        }

        for(auto it:map1){
            if(map2.find(it.first)!=map2.end()){
                cow += min(it.second,map2[it.first]);
            }
        }
        
        string ans = to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};