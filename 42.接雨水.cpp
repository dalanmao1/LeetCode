#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> stack;
        int sz = height.size();
        int len = 0, heig = 0, top = 0;
        int ans = 0;
        for (int i = 0; i < sz; ++i)
        {
            while (!stack.empty() && height[i] > height[*(stack.end() - 1)])
            {
                top = *(stack.end() - 1);
                stack.pop_back();
                if (stack.empty())
                {
                    break;
                }
                int left = *(stack.end() - 1);
                int width = i - left - 1;
                int heig = min(height[left], height[i]) - height[top];
                ans += width * heig;
            }
            stack.push_back(i);
        }
        return ans;
    }
};
// @lc code=end
