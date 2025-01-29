class Solution {
public:

    void markAdjacent(vector<vector<char>>& board, int i, int j, int m, int n){
        board[i][j] = 'M';
        if(i-1>=0 && board[i-1][j] == 'X'){
            markAdjacent(board ,i-1, j, m, n);
        }
        if( j-1>=0 && board[i][j-1] == 'X'){
            markAdjacent(board ,i, j-1, m, n);
        }
        if( j+1<n && board[i][j+1] == 'X'){
            markAdjacent(board ,i, j+1, m, n);
        }
        if(i+1<m && board[i+1][j] == 'X'){
            markAdjacent(board ,i+1, j, m, n);
        }
        return;
    }

    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int cnt =0;
        for(int i=0; i<m ; i++){
            for(int j = 0; j<n ;j++){
                if(board[i][j] == 'X'){
                    markAdjacent(board, i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};