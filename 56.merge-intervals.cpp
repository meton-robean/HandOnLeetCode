/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
/*
我们首先要做的就是给区间集排序，由于我们要排序的是个结构体，
所以我们要定义自己的 comparator，才能用 sort 来排序.

之后遍历进行合并即可，注意合并的条件判断
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty()) return {};
        sort( intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r ){
                    return l[0] < r[0];
             } 
        
        );

        vector<vector<int>> res = { intervals[0] };

        for( int i = 1; i < intervals.size(); ++ i ){
            if (intervals[i][0] <= res.back()[1]  ){
                res.back()[1] = max(intervals[i][1], res.back()[1] ) ;
            } else {
                res.push_back( intervals[i] );
            }
        }

        return res;
    }
};
// @lc code=end

