/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1; //这点很重要
        while (n)
        {
            if (n % 2)
                res = n > 0 ? res * x : res / x;
            x *= x;
            n /= 2;
        }
        return res;
    }
};
// @lc code=end
