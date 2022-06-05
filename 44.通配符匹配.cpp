/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        int i = 0, j = 0;
        int iflag = 0, jflag = -1;

        while (i < m)
        {
            if (j < n && p[j] == '*')
            {
                iflag = i;
                jflag = j++;
            }
            else if (j < n && (p[j] == '?' || p[j] == s[i]))
            {
                ++i;
                ++j;
            }
            else if (jflag >= 0)
            {
                i = ++iflag;
                j = jflag + 1;
            }
            else
                return false;
        }
        while (j < n && p[j] == '*')
            ++j;
        if (j == n)
            return true;
        return false;
    }
};
// @lc code=end
