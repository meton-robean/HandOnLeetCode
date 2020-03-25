/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start


//这属于滑动窗口的题目
//@cmt 从左到右扫描字符串，利用map存储出现的（字符， idx)对
//条件判断 map.count(s[i])代表map中已经存储了这个字符， map[s[i]] > left 代表这个
//重复的字符是在滑动窗口的内部。
//left是滑动窗口的左端
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0;
        int left = -1;
        int len = s.size();
        unordered_map<int, int> map;
        for(int i=0; i<len; i++){
            if( map.count(s[i]) && map[s[i]] > left ){
                left = map[s[i]];
            }
            map[s[i]] = i;
            cnt = max(cnt, i-left);
        }
        return cnt;
        
    }
};
// @lc code=end

