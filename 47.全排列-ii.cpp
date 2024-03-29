/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int>> &res)
    {
        if (i == j - 1)
        {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++)
        {
            if (i != k && num[i] == num[k])
                continue;
            swap(num[i], num[k]);
            recursion(num, i + 1, j, res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &num)
    {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};
// @lc code=end
