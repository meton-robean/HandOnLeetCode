/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start

/*
//计数排序
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3);
        for( auto num : nums ){
            colors[num] ++;
        }

        for(int i =0, cur = 0; i < 3; ++i){

            for(int j = 0; j < colors[i]; ++j){
                nums[cur] = i;
                cur ++;
            }
        }
    }
};
*/


//双指针法
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int red = 0, blue = (int)nums.size() - 1;
        for (int i = 0; i <= blue; ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[red++]);
            }
            else if (nums[i] == 2)
            {
                swap(nums[i--], nums[blue--]);
            }
        }
    }
};

// @lc code=end

