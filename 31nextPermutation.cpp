#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 31. 下一个排�?
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] �?
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] �?
 * �? arr = [3,2,1] 的下一个排列是 [1,2,3] ，因�? [3,2,1] 不存在一个字典序更大的排列�?
 */

/**�?
 *
 *
 */
class Solution
{
public:
    int nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1) //直接返回
            return 0;
        else if (nums.size() == 2) //交换一下返�?
        {
            swap(nums[0], nums[1]);
            return 0;
        }
        int i = nums.size() - 2;
        while (i > 0 && nums[i] >= nums[i + 1]) //找到山谷
            i--;
        if (i == 0 && nums[i] >= nums[i + 1]) //与比山谷大一点的数交换，把山谷后面的数排好序
        {
            sort(nums.begin(), nums.end());
            return 0;
        }
        int j = nums.size() - 1;
        while (j > 0 && nums[i] >= nums[j])
            j--;
        swap(nums[i], nums[j]);
        sort(nums.begin() + i + 1, nums.end());
        return 1;
    }
};
int main(int argc, char const *argv[])
{
    // vector<int> num{1, 2, 3, 8, 5, 7, 6, 4};
    vector<int> num{3, 2, 1};
    Solution sol;
    sol.nextPermutation(num);
    for (auto i : num)
    {
        cout << i << ends;
    }
    return 0;
}
