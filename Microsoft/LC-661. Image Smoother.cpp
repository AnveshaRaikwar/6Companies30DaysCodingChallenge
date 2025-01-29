class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int x[] ={-1,-1,-1,0,0,0,1,1,1};
        int y[] ={-1,0,1,-1,0,1,-1,0,1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=0;
                int k=0;
                for(int l=0;l<9;l++){
                    int u=i+x[l];
                    int v=j+y[l];

                    if(u>=0 && u<m && v>=0 && v<n){
                        sum+=img[u][v];
                        k++;
                    }
                }
                ans[i][j]=sum/k;
            }
        }
        return ans;
    }
};