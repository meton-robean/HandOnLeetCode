/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start

/*
典型的二分查找法的时间复杂度，所以这里也需要用此方法，
思路是首先对原数组使用二分查找法，找出其中一个目标值的
位置，然后**向两边搜索找出起始和结束的位置**，代码如下：
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
         if ( len == 0) 
            return {-1, -1};
        int left = 0, right = len - 1;
        int l, r;
        int resIdx = binSearchDFS(nums, target, left, right);
        if ( resIdx == -1) 
            return {-1, -1};

        l = resIdx ; r = resIdx ;
        while( l > left && nums[l-1] == target) l--;
        while( r < right && nums[r+1] == target) r++;
        return { l, r}; 

    }


    int binSearch(vector<int>& nums, int target, int left, int right){

        int mid;

        while ( left <= right){
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                right = mid - 1 ;
            if (nums[mid] < target)
                left = mid + 1 ;
            
        }

        return -1;

        
    }

    int binSearchDFS(vector<int> &nums, int target, int left, int right){
        
        if ( left > right) return -1 ;

        int mid = left + (right - left) / 2 ;
        if ( nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            return binSearchDFS(nums, target, left, mid - 1);
        else
            return binSearchDFS(nums, target, mid + 1, right);
        
    }
};
// @lc code=end

