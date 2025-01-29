class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int m = g.size();
        int n = s.size();
        int j = 0, i=0;
        
        while(j<n && i<m){
            
            if(g[i]<=s[j]){
                i++;
            }  
            j++;
        }
        return i;
    }
};