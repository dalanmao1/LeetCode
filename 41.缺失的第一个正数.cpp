#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * 题解
 * 我们只需要跟踪数组中出现前 n 个正整数中的哪些。
 * 为了在没有额外空间的情况下做到这一点，我们可以将数组视为布尔数组，其中 sign(arr[i]) 表示第 i 个正整数是否存在。
 * 首先，我们用 n + 1 替换所有非正值，因为我们只会将这些索引用作存储空间。
 * 然后，对于数组中的前 n 个正数中的每一个，我们将其对应索引处的值变为负数。
 * 最后，我们需要做的就是检查第一个正值，这将为我们提供第一个缺失的正值。
 * 如果我们没有找到这样的索引，那么直到 n 的所有自然数都存在，所以我们返回 n + 1。
 */
// @lc code=start

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (auto &i : nums)
            if (i <= 0)
                i = n + 1;
        for (int i = 0; i < n; ++i)
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0)
                return i + 1;
        return n + 1;
    }
};

// @lc code=end
