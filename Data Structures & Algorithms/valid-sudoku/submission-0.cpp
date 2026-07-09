class Solution {
public:
    bool check(vector<vector<char>>& board,pair<int,int> pos){
        int row = pos.first;
        int col = pos.second;
        
        for(int i=0;i<9;i++){
            //row check
            if(board[row][i]==board[row][col] && i!=col) return false;
            //col check 
            if(board[i][col]==board[row][col] && i!=row) return false;
        }
        int row_rem = row%3;
        int col_rem = col%3;

        for(int i = row-row_rem;i<row-row_rem+3;i++){
            for(int j = col-col_rem;j<col-col_rem+3;j++){
                if(i==row && j==col) continue;
                if(board[i][j]==board[row][col]) return false;
            }
        }
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        pair<int,int> pos;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                pos={i,j};
                if(board[i][j]=='.') continue;
                if(check(board,pos)==false){
                    cout<<pos.first<<" "<<pos.second<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};
