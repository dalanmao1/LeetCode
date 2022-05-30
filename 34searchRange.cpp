#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 34. 在排序数组中查找元素的第一个和最后一个位�?
 * 给定一个按照升序排列的整数数组 nums，和一个目标�? target。找出给定目标值在数组中的开始位置和结束位置�?
 * 如果数组中不存在目标�? target，返�? [-1, -1]�?
 */

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> num;
        if (nums.size() == 1) //先处理长度是1的情�?
        {
            if (nums[0] != target)
            {
                num.push_back(-1);
                num.push_back(-1);
                return num;
            }
            else
            {
                num.push_back(0);
                num.push_back(0);
                return num;
            }
        }
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (target > nums[mid])
            {
                left = mid + 1;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = right = mid;
                while (left >= 0 && target == nums[left]) //精髓，left >= 0先，不然会报错，可能会退到边界外面，但是下面会拉进来
                {
                    --left;
                }
                while (right <= nums.size() - 1 && target == nums[right])
                {
                    ++right;
                }
                num.push_back(left + 1);
                num.push_back(right - 1);
                return num;
            }
        }
        num.push_back(-1);
        num.push_back(-1);
        return num;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{5, 7, 7, 8, 8, 10};
    Solution sol;
    for (auto i : sol.searchRange(num, 8))
    {
        cout << i << ' ';
    }
    return 0;
}
