#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> sol(n + 1, 0);
        int Bit = 0;
        for (int i = 1; i <= n; ++i)
        {
            if ((i & (i - 1)) == 0) //比如0010,0100
            {
                Bit = i;
            }
            sol[i] = sol[i - Bit] + 1;
        }
        return sol;
    }
};
// @lc code=end
