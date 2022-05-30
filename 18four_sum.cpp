#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; //哈哈哈4545

/**18. 四数之和
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
 * 请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
 * （若两个四元组元素一一对应，则认为两个四元组重复）：
 */

/**解答
 * 和三个数之和一样，只不过要返回四个值，那么就需要去重复
 * 首先长度小于三那直接返回
 * 排序，然后从0-length-1选一个，从i+1-length-1开始第二个，首尾指针作为第三重循环
 * 最重要的去重复，这步不容易想明白
 */
class Solution
{
public:
    void addnum(vector<int> &nums, int n1, int n2, int n3, int n4)
    {
        auto it = nums.begin();
        *(it++) = n1;
        *(it++) = n2;
        *(it++) = n3;
        *it = n4;
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ivec;
        auto it = ivec.begin();
        int length = nums.size();
        if (length < 4)
            return ivec;
        int front = 0, rear = 0; //定义首尾指针
        int nownum = 0;
        sort(nums.begin(), nums.end()); //排序

        for (int i = 0; i < length; ++i)
        {
            //去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < length; ++j)
            {
                //去重
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                front = j + 1;
                rear = length - 1;

                while (front < rear)
                {
                    // nownum = nums[i] + nums[j] + nums[front] + nums[rear];溢出
                    if (nums[i] + nums[j] > target - nums[front] - nums[rear])
                    {
                        --rear;
                    }
                    else if (nums[i] + nums[j] < target - nums[front] - nums[rear])
                    {
                        ++front;
                    }
                    else
                    {
                        ivec.push_back(vector<int>{nums[i], nums[j], nums[front], nums[rear]});

                        // 去重逻辑应该放在找到一个四元组之后
                        while (front < rear && nums[rear] == nums[rear - 1])
                            rear--;
                        while (front < rear && nums[front] == nums[front + 1])
                            front++;
                        ++front;
                        --rear;
                    }
                }
            }
        }
        return ivec;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{1, 0, -1, 0, -2, 2};
    Solution sol;
    for (auto vec : sol.fourSum(num, 0))
    {
        for (auto it : vec)
        {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
