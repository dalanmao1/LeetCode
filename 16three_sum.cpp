#include <iostream>
#include <vector>
#include <algorithm>
//#include <stdlib.h>
/**
 * 16. 最接近的三数之和
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 返回这三个数的和。
 * 假定每组输入只存在恰好一个解。
 */

/**解答
 * 目的：三元组之和-target的绝对值最小的那个值
 * 工具：遍历+首尾指针
 * 先从数组的第一个i开始，首尾指针从i+1到尾指针，没必要从0和尾开始，前面都遍历了
 * 依次查找，如果三元组值>target，说明太大了，尾指针前移；如果小于，太小了，首指针前移；
 */

using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int closenum = nums[0] + nums[1] + nums[2], nownum = 0;
        int front = 0, rear = 0;
        for (int i = 0; i < sz; ++i)
        {
            //定义首尾双指针
            front = i + 1;
            rear = sz - 1;
            while (front < rear) // front ！= rear不可以，出不来结果
            {
                nownum = nums[i] + nums[front] + nums[rear];
                if (std::abs(nownum - target) < std::abs(closenum - target))
                    closenum = nownum;
                if (nownum > target)
                {
                    --rear;
                }
                else if (nownum < target)
                {
                    ++front;
                }
                else
                {
                    return nownum;
                }
            }
        }
        return closenum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{-1, 2, 1, -4};
    Solution sol;
    cout << sol.threeSumClosest(num, 1);
    // cout << 1;
    return 0;
}
