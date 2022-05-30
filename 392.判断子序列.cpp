#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (t.size() == 0)
            return s.size()==0?true:false;
        for (int i = 0, j = 0; i < t.size(); ++i)
        {
            if (s[j] == t[i])
                j++;
            if (j == s.size())
                return true;
        }
        return false;
    }
};
// @lc code=end
