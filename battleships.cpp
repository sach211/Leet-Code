#https://leetcode.com/problems/battleships-in-a-board/submissions/

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        int count = 0;
        
        for(int ir = 0; ir < row; ir++)
        {
            for (int ic = 0; ic < col; ic++)
            {
                if(board[ir][ic] == 'X' && (ir == 0 || board[ir-1][ic] != 'X') && (ic == 0 || board[ir][ic-1] != 'X'))
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};