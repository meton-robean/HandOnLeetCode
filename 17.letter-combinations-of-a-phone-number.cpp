/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start

//暴力搜索即可 100%
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        int size = digits.size();
        if (size == 0)
            return res;
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < size; i++)
        {
            int idx = int(digits[i] - '0');
            string s_item = dict[idx];
            vector<string> tmp_res;
            for (char c : s_item)
            {
                for (string sub_string : res)
                {
                    tmp_res.push_back(sub_string + c);
                }
            }
            res = tmp_res;
        }
        return res;
    }
};
// @lc code=end

