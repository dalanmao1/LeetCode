#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 26. 删除有序数组中的重复项
 * 给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
 * 返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
 */

/**解
 * 思路：一个快指针（遍历），一个慢指针（记录大小），如果当前值和上一个值相等，重复了，继续遍历；如果不相等，nums[sz++] = nums[i];
 *
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int sz = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                nums[sz++] = nums[i];
            }
        }
        return sz;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution sol;
    int sz = sol.removeDuplicates(nums);
    auto it = nums.begin();
    for (int i = 0; i < sz; ++i, ++it)
    {
        cout << *it << " ";
    }
    return 0;
}
