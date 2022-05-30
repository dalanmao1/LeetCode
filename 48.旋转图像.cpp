#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // C++ 这里�? = 拷贝是值拷贝，会得到一个新的数�?
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        // 这里也是值拷�?
        matrix = matrix_new;
    }
};

// @lc code=end
