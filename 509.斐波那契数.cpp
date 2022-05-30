#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        int f0 = 0;
        int f1 = 1;
        int val = 0;
        if (n == 0)
            return f0;
        else if (n == 1)
            return f1;
        else
        {
            for (int i = 2; i <= n; ++i)
            {
                val = f0 + f1;
                f0 = f1;
                f1 = val;
            }
        }
        return val;
    }
};
// @lc code=end
