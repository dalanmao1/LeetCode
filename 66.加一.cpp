#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int length = digits.size() - 1;
        int carry = 0;
        // if (digits[length] != 9)
        // {
        //     ++digits[length];
        // }
        // else
        // {
        for (; length >= 0; --length)
        {
            if (digits[length] != 9)
            {
                ++digits[length];
                carry = 0;
                return digits;
            }
            else
            {
                carry = 1;
                digits[length] = 0;
            }
        }
        if (carry == 1)
        {
            digits.insert(digits.begin(), 1);
        }
        // }
        return digits;
    }
};
// @lc code=end
