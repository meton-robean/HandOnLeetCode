/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
//hash思想
//利用 unordered_map<string, vector<string>> ， key是经过排序后的Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        unordered_map<string, vector<string>> hashTable;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            hashTable[s].push_back(strs[i]);

        }

        for(auto pair : hashTable){
            res.push_back( pair.second );
        }
        return res;
    }
};
// @lc code=end

