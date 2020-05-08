// 2 +3*6-4
//  0    +    2 +3*6-4
// sum  sign
class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        char sign = '+'; 
        int sum = 0;
        int number = 0;
        for( int i = 0; i < s.size(); ++i ) {

            if( s[i] >= '0') {
                number = number*10 + (s[i] - '0');
            }

            //注意i == s.size()-1时，最后一个数字的处理
            if( (s[i] != ' ' && s[i] < '0') || i == s.size()-1 ) { //当前遇到了符号,代表number截取完毕
        
                if( sign == '+' ) { //sign代表当前运算符的前一个运算符
                    stack.push( number);

                } else if( sign == '-') {
                    stack.push( -number); //减法转化为加法

                } else if( sign == '*') {
                    int tmp = stack.top(); stack.pop();
                    stack.push( tmp * number);

                } else if( sign == '/') {
                    int tmp = stack.top(); stack.pop();
                    stack.push( tmp / number);
                }
                sign = s[i];
                number = 0;
            }     
        }
        
        while( !stack.empty()) {
            sum += stack.top();
            stack.pop();
        }
        return sum;
    }
};