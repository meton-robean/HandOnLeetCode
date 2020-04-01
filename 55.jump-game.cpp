/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start

//贪心法
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int max = 0; //表示最远走到的位置
        
        //i 相当于我们一步一步走
        for(int i = 0; i < nums.size(); ++i){
            if( i > max) return false; //说明连走一步都比不过，就是遇到了方格为0的地方，原地踏步

            int cur = i + nums[i]; //cur是从当前i能跳到最远的位置
            max = cur > max? cur : max;
        }
        return ( max >= nums.size() - 1);
        
    }
};
// @lc code=end

