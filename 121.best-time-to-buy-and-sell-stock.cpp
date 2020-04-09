/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
//动态规划
/*
要满足两个条件:
profit = sell_price - buy_price;  profit越大越好
sell time 要出现在buy time之后

[7,  1 ,     5       3        6   4]
     buy         price[i]
     maxprofit = max(maxprofit, price[i] - buy)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = INT_MAX;
        int max_profit = 0;
        for(int i = 0; i < prices.size(); ++i){
            buy_price = min( buy_price, prices[i] );
            max_profit = max(max_profit, prices[i] - buy_price);

        }
        return max_profit;
    }
};
// @lc code=end

