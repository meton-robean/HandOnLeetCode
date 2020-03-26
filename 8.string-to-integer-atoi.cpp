/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
/* 思路比较清晰
1. 若字符串开头是空格，则跳过所有空格，到第一个非空格字符，如果没有，则返回0.
2. 若第一个非空格字符是符号 +/-，则标记 sign 的真假，这道题还有个局限性，那就是在 c++ 里面，+-1 和-+1 都是认可的，都是 -1，而在此题里，则会返回0.
3. 若下一个字符不是数字，则返回0，完全不考虑小数点和自然数的情况，不过这样也好，起码省事了不少。
4. 如果下一个字符是数字，则转为整形存下来，若接下来再有非数字出现，则返回目前的结果。
5. 还需要考虑边界问题，如果超过了整型数的范围，则用边界值替代当前值。
*/

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;

        int i=0; int base = 0; int len = str.size(); int sign = 1;
        //跳过空格
        while(i<len && str[i] == ' ') i++;
        //如果遇到 + - 符号
        if(i<len && (str[i] == '+' || str[i] == '-' )){
            sign = str[i] == '+' ? 1 : -1;
            i++;
        }

        //遇到数字 按照 base = base*10 + (str[i] - '0') 迭代构造数字
        //倒数第二次可能可以判断下一次是否数值溢出
        while(i<len && str[i] >= '0' && str[i] <= '9'){
            if (base > INT_MAX / 10 || ( (base == INT_MAX / 10) && (str[i] - '0' > INT_MAX % 10) ) ){
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            base = base * 10 + (str[i] - '0');
            i++;
        }
        
        return sign * base ;


        
    }
};
// @lc code=end

