#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 33. 搜索旋转排序数组
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
 * 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
 * 例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为?[4,5,6,7,0,1,2] 。给你 旋转后 的数组 nums 和一个整数 target ，
 * 如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回?-1?。
 */

/**解答
 * 目的：在局部有序的表中找到目标值
 * 工具：二分
 * 如果 [l, mid - 1] 是有序数组，且 target 的大小满足 [\textit{nums}[l],\textit{nums}[mid])[nums[l],nums[mid])，
 * 则我们应该将搜索范围缩小至 [l, mid - 1]，否则在 [mid + 1, r] 中寻找。
 * 如果 [mid, r] 是有序数组，且 target 的大小满足 (\textit{nums}[mid+1],\textit{nums}[r]](nums[mid+1],nums[r]]，
 * 则我们应该将搜索范围缩小至 [mid + 1, r]，否则在 [l, mid - 1] 中寻找。
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        /********这种方法虽然可行，但失去了题目的意义，应该追求更好的算法******
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
                return i;
        }
        return -1;
        ******************************************************************/
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) || (nums[0] > nums[mid]) || (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{3, 1};
    Solution sol;
    cout << sol.search(num, 1);
    // cout << 1;
    return 0;
}