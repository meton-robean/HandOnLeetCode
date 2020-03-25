/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

//@cmt 目前发现讲解的比较清楚的：https://www.youtube.com/watch?v=nSFWpXuNfyw
class Solution {
public:
    string longestPalindrome(string s) {
        int str_len = s.size();
        string palindrome;
        for(int i=0; i< str_len; i++){
            string s1 = get_longest_palindrome(s, i, i);    //中心对称： bab
            string s2 = get_longest_palindrome(s, i, i+1);  //轴对称： abba

            string tmp = s1.size() > s2.size()? s1: s2;
            palindrome = palindrome.size() > tmp.size()? palindrome: tmp;
        }
        return palindrome;

    }

    //从s[left: right]为中心，分别往左右两边扩散搜索符合条件的 回文子串，
    //下一轮substring变为： s[left-1, right+1]
    string get_longest_palindrome(string & s, int left, int right){

        while( left>=0 && right< s.size() && s[left] == s[right]){
            left --;
            right++;

        }
        return s.substr(left+1, ((right-1)-(left+1)+1) );
    }


};
// @lc code=end

