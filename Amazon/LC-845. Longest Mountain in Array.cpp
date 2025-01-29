class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        for(int i=1; i<=n-2; ){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int cnt = 1;
                int j=i;
                while(j>0 && arr[j]>arr[j-1]){
                    cnt++;
                    j--;
                }
                while(i<n-1 && arr[i]>arr[i+1]){
                    cnt++;
                    i++;
                }
                ans = max(ans,cnt);
            }
            else{
                i++;
            }

        }
        return ans;
    }
};