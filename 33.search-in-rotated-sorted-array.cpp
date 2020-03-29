/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start

//二分查找变种
//做题是否可以把一个例子的所有情况列一下 e.g.  0 1 2 3 4
//所有情况有:
/*
a 1 2 3 4 0
b 2 3 4 0 1 
c 3 4 0 1 2 
d 4 0 1 2 3
可以看出 由于被翻转了， 所以要先分两种情况讨论： 左边有序（a b ） 左边无序情况（ c d）
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] >= nums[left]) { //左半边有序
                if (nums[left] <= target && nums[mid] > target) //target在左边
                    right = mid - 1;
                else 
                    left = mid + 1;
            } else {  //右半边有序,左边无序
                if (nums[mid] < target && nums[right] >= target) //target 在右边
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return -1;
    }
};


// @lc code=end

