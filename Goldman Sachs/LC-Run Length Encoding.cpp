class Solution {
  public:
    string encode(string s) {
        string ans;
        int n=s.size();
        int i=0;
        
        while(i<n){
            char curr  = s[i];
            int cnt = 0;
            
            while(i<n && s[i]==curr){
                cnt++;
                i++;
            }
            
            ans += curr;
            ans += to_string(cnt);
        }
        return ans;
    }
};