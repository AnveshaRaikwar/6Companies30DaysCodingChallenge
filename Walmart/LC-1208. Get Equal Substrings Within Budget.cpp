class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int i=0,j=0;

        int maxlen = 0;
        int currcost = 0;

        while(j<n){
            currcost += abs(s[j] - t[j]);
            while(currcost > maxCost){
                currcost -= abs(s[i]-t[i]);
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        } 
        return maxlen;      
    }
};