/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

//类似走迷宫， DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int r = grid.size(); 
        int c = grid[0].size();
        int total = 0;
        for (int x = 0; x < r; ++x)
        {
            for (int y = 0; y < c; ++y)
            {
                total += grid[x][y] - '0';
                dfs(grid, x, y, r, c);
            }
        }
        return total;
    }

    void dfs(vector<vector<char>> &grid,
            int x, int y, int r, int c )
    {

        if (x < 0 || x >=r || y < 0 || y >= c ) 
            return;
        if ( grid[x][y] == '0') 
            return;
        //标记为0,防止重复遍历。可以想象成小岛沉了. 那么遍历grid的过程就是把一片片陆地变为0的过程
        grid[x][y] = '0'; 
        dfs(grid, x - 1, y, r, c);
        dfs(grid, x + 1, y, r, c);
        dfs(grid, x, y - 1, r, c);
        dfs(grid, x, y + 1, r, c);

        return;
    }
};
// @lc code=end

