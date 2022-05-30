#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<string> &svec, string str, int sz, int left_pos, int right_pos)
    {
        if (left_pos == sz && right_pos == sz)
        {
            svec.push_back(str);
            return;
        }
        if (right_pos > left_pos || left_pos > sz || right_pos > sz)
            return;
        
        dfs(svec, str + '(', sz, left_pos + 1, right_pos);
        dfs(svec, str + ')', sz, left_pos, right_pos + 1);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> svec;
        string str;         //默认是个空字符串，不要加=NULL，会报错
        dfs(svec, str, n, 0, 0);
        return svec;
    }
};
// @lc code=end
