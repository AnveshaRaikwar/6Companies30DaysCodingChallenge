class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        vector<int> r,c;
        int cnt1=1, cnt2=1,max1=1,max2=1;

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        for(int i=0; i<hBars.size()-1; i++){
            if( hBars[i]+1 == hBars[i+1]){
                cnt1++;
            }
            else{
                cnt1=1;
            }
            max1=max(max1,cnt1);
        }

        for(int i=0; i<vBars.size()-1; i++){
            if(vBars[i]+1 == vBars[i+1]){
                cnt2++;
            }
            else{
                cnt2=1;
            }
            max2=max(max2,cnt2);
        }

        int ans = min(max1,max2);
        ans++;
        return (ans)*(ans);
    }
};