/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string str = countAndSay(n - 1);
        string result;
        int sz = str.size();
        for (int i = 0, j = 1; i < sz; ++i)
        {
            if (i + 1 != sz && str[i + 1] == str[i])
                ++j;
            else
            {
                result += j + '0';
                result += str[i];
                j = 1;
            }
        }
        return result;
    }
};
// @lc code=end
