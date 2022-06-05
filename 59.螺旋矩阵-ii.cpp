#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        
        vector<vector<int>> ivec;

        if (n == 0)
        {
            return ivec;
        }
        vector<int> row(n, 0);
        int i = n;
        while (i--) //需要先赋值好，不然后面用pushback太费�?
        {
            ivec.push_back(row);
        }
        int top = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        int nums = 1;
        while (true)
        {
            for (i = left; i <= right; ++i, ++nums)
                ivec[top][i] = nums;
            if (++top > down)
                break;
            for (i = top; i <= down; ++i, ++nums)
                ivec[i][right] = nums;
            if (--right < left)
                break;
            for (i = right; i >= left; --i, ++nums)
                ivec[down][i] = nums;
            if (--down < top)
                break;
            for (i = down; i >= top; --i, ++nums)
                ivec[i][left] = nums;
            if (++left > right)
                break;
        }
        return ivec;
    }
};
// @lc code=end
