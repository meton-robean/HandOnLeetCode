/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
//走迷宫，DFS搜索...
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        //遍历 每个都作为word匹配起始点
        for(int x = 0; x < board.size(); x++){
            for(int y = 0; y< board[0].size(); y++){
                if (search(board, x, y, word, 0))
                    return true;
            }
        }

        return false;
        
    }

    bool search(vector<vector<char>> &board, int x, int y, const string & word, int d){
        
        if( out_of_bound(board, x, y) ) return false;
        if( board[x][y] != word[d] ) return false;
        if( d == word.length()-1) return true;
        

        int cur = board[x][y];
        board[x][y] = '#'; //标记为不可走，避免之后的深度搜索又走回原来的位置..
        bool found = search(board, x - 1, y, word, d + 1) ||
                     search(board, x + 1, y, word, d + 1) ||
                     search(board, x, y - 1, word, d + 1) ||
                     search(board, x, y + 1, word, d + 1);
        board[x][y] = cur;
        return found;
    }

    bool out_of_bound(vector<vector<char>> &board, int x, int y ){
        //out of boundary
        if( y < 0 || y >= board[0].size()
            || x < 0 || x >= board.size() ){
                return true;
        }
        return false;
    }
};
// @lc code=end

