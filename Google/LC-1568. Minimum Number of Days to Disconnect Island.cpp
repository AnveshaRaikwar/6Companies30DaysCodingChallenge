class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m,n;

    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited){
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || grid[i][j]==0){
            return;
        }

        visited[i][j] = 1;

        for(auto dir : directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            DFS(grid,new_i,new_j,visited);
        }
    }

    int numberofIslands(vector<vector<int>>& grid){
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int island = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    DFS(grid,i,j,visited);
                    island+=1;
                }
            }
        }
        return island;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int islands = numberofIslands(grid);

        if(islands == 0 || islands > 1){
            return 0;
        }
        else{
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;

                        islands = numberofIslands(grid);

                        grid[i][j] = 1;
                        if(islands > 1 || islands == 0){
                            return 1;
                        }
                    }
                }
            }
        }
        return 2;
    }
};