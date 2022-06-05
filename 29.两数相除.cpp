#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        bool flag=(dividend>>31)^(divisor>>31);
        int result=0;
        long t=abs((long)dividend);
        long d =abs((long)divisor);

        for (int i=31;i>=0;--i)
        {
            if ((t>>i)>=d) {//找出足够大的数2^n*divisor
                result+=1<<i;//将结果加上2^n
                t-=d<<i;//将被除数减去2^n*divisor
            }
        }
        return flag?-result:result;
    }
};
// @lc code=end
